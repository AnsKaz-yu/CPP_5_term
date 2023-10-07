#ifndef UNTITLED_PLUGINSLOADER_H
#define UNTITLED_PLUGINSLOADER_H

#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <unistd.h>
#include <vector>
using std::vector;
using funcType = double(*)(vector<double>);

class PluginsLoader {
    std::string path;
    std::map<std::string, funcType> funcMap;
    void addFunction(std::string const& name);
    std::string getPath();
public:
    PluginsLoader();
    double function(std::string const& name, const vector<double>& values);
    bool contains(std::string const& name);
};


#endif //UNTITLED_PLUGINSLOADER_H
