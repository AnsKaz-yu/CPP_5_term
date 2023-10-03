#include "PluginsLoader.h"


void PluginsLoader::addFunction(const std::string &name) {
    HMODULE hm = LoadLibraryA((path+name).c_str());
    if (!hm)
        throw std::exception();

    std::string function = name.substr(0, name.find(".dll"));
    function.erase(0,3);

    auto func = (funcType)GetProcAddress(hm, "func");

    if (func){
        funcMap.insert(std::pair<std::string, funcType>(function, func));
    }
    else{
        throw std::exception();
    }
}

PluginsLoader::PluginsLoader() {
    path = getPath();
    WIN32_FIND_DATAA find;
    HANDLE hFind = FindFirstFileA((path + std::string("*.dll")).c_str(), &find);

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

bool PluginsLoader::contains(const std::string &name) {
    return funcMap.contains(name);
}

double PluginsLoader::function(const std::string &name, const vector<double> &values) {
    if (funcMap.contains(name)){
        try{
            double res = funcMap[name](values);
            return res;
        }
        catch(...){
            throw std::exception();
        }
    }
    else{
        throw std::exception();
    }
}

std::string PluginsLoader::getPath() {
    char P[PATH_MAX]{};
    if (!getcwd(P, sizeof(P))) throw std::exception();
    std::string full_path = P;
    while (full_path.back() != '\\') full_path.pop_back(); //deleting "cmake-build-directory" from path
    full_path += std::string("plugins\\");
    return full_path;
}
