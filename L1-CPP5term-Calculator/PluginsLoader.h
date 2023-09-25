#ifndef UNTITLED_PLUGINSLOADER_H
#define UNTITLED_PLUGINSLOADER_H
#include <Windows.h>
#include <string>
#include <map>
#include <iostream>

using unary = double(*)(double);
class PluginsLoader {
    std::string path = "C:\\Users\\Lenovo\\CLionProjects\\L1-CPP5term-Calculator\\plugins\\";
    std::map<std::string, unary> funcMap;
    void addFunction(std::string const& name);
public:
    PluginsLoader();
    double functions(std::string const& name, double a);
    bool contains(std::string const& name);
};


#endif //UNTITLED_PLUGINSLOADER_H
