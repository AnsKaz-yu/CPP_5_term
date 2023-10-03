#include "Calculator.h"

template <typename T1, typename T2>
bool convert_via_stringstream(T1&& t1, T2&& t2){
    std::stringstream s;
    s<<t1;
    return static_cast<bool>(s >> t2);
}


std::string Calculator::conversion_to_the_standard_form(const std::string& str) {
    std::string def;
    std::string t;
    double d;
    char previous = '(';
    for (auto u : str){
        if (isspace(u)) continue;
        convert_via_stringstream(u, t);

        if (u == '-' && previous == '('){
            def += " 0 " + t;
            previous = u;
            continue;
        }

        if (DO.contains(t) || t == "(" || t == ")"){
            def += " " + t + " ";
            previous = u;
            continue;
        }

        if (convert_via_stringstream(u, double()) != convert_via_stringstream(previous, double())
        && u != '.' && previous != '.') {
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
    if (DO.contains(operation)){
        double a, b;
        a = numbers.top(); numbers.pop();
        b = numbers.top(); numbers.pop();
        numbers.push(DO.functions(operation, a, b));
        return;
    }

    if (!PL.contains(operation)) {
            throw std::exception();
    }

    std::vector<double> values;
    bool success;
    double res;
    do{
        success = true;
        if (numbers.empty()){
            throw std::exception();
        }
        values.push_back(numbers.top());
        numbers.pop();
        try {
            res = PL.function(operation, values);
        }
        catch (...) {
            success = false;
        }
    }while (!success);
    numbers.push(res);
}

void Calculator::Solve(std::string expression){
    clearStacks();
    expression = conversion_to_the_standard_form(expression);
    std::stringstream s(expression);
    std::string elem;
    double d;
    while (s>>elem){
        if (convert_via_stringstream(elem, d)){
            numbers.push(d);
            continue;
        }

        if (operators.empty() || operators.top() == "(" || elem == "(" || PL.contains(elem)){
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

        while (!operators.empty() && operators.top() != "("
        && ((DO.contains(operators.top()) && !DO.precedenceIsMaintained(operators.top(), elem))
        || PL.contains(operators.top()))){
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

void Calculator::clearStacks() {
    std::stack<double>().swap(numbers);
    std::stack<std::string>().swap(operators);
}
