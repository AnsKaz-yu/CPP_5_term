
#include "DefaultOperations.h"
DefaultOperations::DefaultOperations() {
    //precedence of operations
    precedence["+"] = 1;
    precedence["-"] = 1;
    precedence["*"] = 2;
    precedence["/"] = 2;

    //binding functions to operators
    operatorsFunc["+"] = [](double a, double b){return b + a; };
    operatorsFunc["-"] = [](double a, double b){return b - a; };
    operatorsFunc["*"] = [](double a, double b){return b * a; };
    operatorsFunc["/"] = [](double a, double b) {return b / a; };
}

double DefaultOperations::functions(const std::string &name, double a, double b) {
    if (operatorsFunc.contains(name)){
        return operatorsFunc[name](a, b);
    }
    else throw std::exception();
}

bool DefaultOperations::contains(const std::string &name) {
    return(operatorsFunc.contains(name));
}

bool DefaultOperations::precedenceIsMaintained(std::string const& name1, std::string const& name2){
    if (!precedence.contains(name1) || !precedence.contains(name2)){
        throw std::exception();
    }
    return precedence[name1] < precedence[name2];
}