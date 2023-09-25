#include "Calculator.h"

template <typename T1, typename T2>
bool convertToT(T1& t1, T2& t2){
    std::stringstream s;
    s<<t1;
    return static_cast<bool>(s >> t2);
}

Calculator::Calculator() {
    precedence["+"] = 1;
    precedence["-"] = 1;
    precedence["*"] = 2;
    precedence["/"] = 2;
    precedence["^"] = 3;

    functions["+"] = [](double a, double b)->double {return b + a; };
    functions["-"] = [](double a, double b)->double {return b - a; };
    functions["*"] = [](double a, double b)->double {return b * a; };
    functions["/"] = [](double a, double b)->double {return b / a; };
    functions["^"] = [](double a, double b) {return pow(b, a); };
}

std::string Calculator::to_default_view(std::string str) {
    std::string def;
    std::string t;
    double d;
    char previous = '(';
    for (auto u : str){
        if (isspace(u)) continue;
        convertToT(u, t);

        if (u == '-' && previous == '('){
            def += " 0 " + t;
            previous = u;
            continue;
        }

        if (functions.contains(t) || t == "(" || t == ")"){
            def += " " + t + " ";
            previous = u;
            continue;
        }

        if (convertToT(u, d) != convertToT(previous, d) && u != '.' && previous != '.') {
            def += " " + t;
            previous = u;
            continue;
        }

        def += t;
        previous = u;
    }
    return def;
}

void Calculator::action(){
    std::string operation = operators.top();
    operators.pop();
    if (functions.contains(operation)){
        double a, b;
        a = numbers.top(); numbers.pop();
        b = numbers.top(); numbers.pop();
        numbers.push(functions[operation](a, b));
    } else{
        double a;
        a = numbers.top(); numbers.pop();
        if (PL.contains(operation)){
            numbers.push(PL.functions(operation, a));
        }else throw std::exception();
    }
}

void Calculator::Solve(std::string expression){
    expression = to_default_view(expression);
    std::stringstream s(expression);
    std::string elem;
    double d;
    while (s>>elem){
        if (convertToT(elem, d)){
            numbers.push(d);
            continue;
        }

        if (operators.empty() || operators.top() == "("){
            operators.push(elem);
            continue;
        }

        if (elem == ")"){
            while (operators.top() != "("){
                action();
            }
            operators.pop();
            continue;
        }

        while (!operators.empty() && operators.top()!= "("
        && precedence.contains(elem)
        && precedence[operators.top()] >= precedence[elem]){
            action();
        }
        operators.push(elem);
    }

    while (!operators.empty()){
        action();
    }

    std::cout<<numbers.top()<<std::endl;
    numbers.pop();
}