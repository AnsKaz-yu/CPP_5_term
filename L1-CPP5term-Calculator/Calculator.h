#ifndef UNTITLED_CALCULATOR_H
#define UNTITLED_CALCULATOR_H
#include <sstream>
#include <map>
#include <functional>
#include <stack>
#include <cmath>
#include <iostream>
#include "PluginsLoader.h"

using priorityMap = std::map<std::string, int>;
using operatorsMap = std::map<std::string, std::function<double(double, double)>>;

class Calculator {
    PluginsLoader PL;
    priorityMap precedence;
    operatorsMap functions;
    std::stack<double> numbers;
    std::stack<std::string> operators;
    std::string to_default_view(std::string str);
    void action();

public:
    Calculator();
    void Solve(std::string expression);
};


#endif //UNTITLED_CALCULATOR_H
