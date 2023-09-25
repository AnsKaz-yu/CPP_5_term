#include <iostream>
#include "Calculator.h"
int main() {
    Calculator Calc;
    std::cout << "Enter the expression... (to exit, enter the word \"exit\")" << std::endl;
    std::string expression;
    std::getline(std::cin, expression);
    while (expression != "exit"){
        try {
            Calc.Solve(expression);
        }
        catch (std::exception& error) {
            std::cout << error.what() << std::endl;
        }
        std::cout << "Enter the expression... (to exit, enter the word \"exit\")" << std::endl;
        std::getline(std::cin, expression);
    }
    return 0;
}
