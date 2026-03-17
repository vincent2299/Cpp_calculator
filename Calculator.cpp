
// writing logic and implemenation for the calculator class

#include "Calculator.h"
#include <stdexcept> // for handling exceptions

double Calculator::Calculate(double x, char oper, double y) {
    switch (oper) { // switch statement to determine the operation to perform
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y == 0) {
                // handle division by zero error
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            return x / y;
        default:
            // handle invalid operator error
            throw std::invalid_argument("Invalid operator. Use +, -, *, or /.");
    }
}