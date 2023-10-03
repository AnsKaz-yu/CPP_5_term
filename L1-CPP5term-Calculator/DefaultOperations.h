#ifndef L1_CPP5TERM_CALCULATOR_DEFAULTOPERATIONS_H
#define L1_CPP5TERM_CALCULATOR_DEFAULTOPERATIONS_H
#include <Windows.h>
#include <string>
#include <map>
#include <functional>
#include <cmath>

using priorityMap = std::map<std::string, int>;
using operatorsMap = std::map<std::string, std::function<double(double, double)>>;

class DefaultOperations {
    priorityMap precedence;
    operatorsMap operatorsFunc;
public:
    double functions(std::string const& name, double a, double b);
    bool contains(std::string const& name);
    bool precedenceIsMaintained(std::string const& name1, std::string const& name2);
    DefaultOperations();
};


#endif //L1_CPP5TERM_CALCULATOR_DEFAULTOPERATIONS_H
