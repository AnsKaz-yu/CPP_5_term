#include "PluginsLoader.h"

double PluginsLoader::functions(const std::string &name, double a) {
    if (funcMap.contains(name))
        return funcMap[name](a);
    else throw std::exception();
}

bool PluginsLoader::contains(const std::string &name) {
    return funcMap.contains(name);
}

void PluginsLoader::addFunction(const std::string &name) {
    HMODULE hm = LoadLibraryA((path+name).c_str());
    if (!hm)
        throw std::exception();

    std::string function = name.substr(0, name.find(".dll"));
    function.erase(0,3);

    auto func = (unary)GetProcAddress(hm, "func");

    if (func){
        funcMap.insert(std::pair<std::string, unary>(function, func));
    }else throw std::exception();
        
}

PluginsLoader::PluginsLoader() {
    WIN32_FIND_DATAA find;
    HANDLE hFind = FindFirstFileA((path+std::string("*.dll")).c_str(), &find);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string dllFileName(find.cFileName);
            addFunction(dllFileName);
        } while (NULL != FindNextFileA(hFind, &find));

        FindClose(hFind);
    }
    else {
        throw std::exception();
    }
}
