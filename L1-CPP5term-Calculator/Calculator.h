#ifndef UNTITLED_CALCULATOR_H
#define UNTITLED_CALCULATOR_H
#include <sstream>
#include <map>
#include <functional>
#include <stack>
#include <cmath>
#include <iostream>
#include "PluginsLoader.h"
#include "DefaultOperations.h"


class Calculator {
    PluginsLoader PL;
    DefaultOperations DO;
    std::stack<double> numbers;
    std::stack<std::string> operators;
    std::string conversion_to_the_standard_form(const std::string& str);
    void action();
    void clearStacks();
public:
    Calculator() = default;
    void Solve(std::string expression);
};


#endif //UNTITLED_CALCULATOR_H
