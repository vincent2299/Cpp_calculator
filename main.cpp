
#include <iostream> // get inputs and display outputs
#include "Calculator.h" // include the header file for the Calculator class

int main() {


    double x, y = 0.0; // variables to hold the two numbers
    char oper = '+'; // variable to hold the operator
    bool keepRunning = true; // flag to control the loop

    Calculator calc; // create an instance of the Calculator class

    std::cout << "====================================\n";
    std::cout << "Welcome to the C++ Calculator!\n";
    std::cout << "====================================\n";
    std::cout << "Format: a + b | a - b | a * b | a / b\n";
    std::cout << "Type 'Ctrl+C' to quit the program.\n";

    while (keepRunning)
    {
        std::cout << "\nEnter your calculation: ";

        // read user input for the two numbers and the operator
        if (!(std::cin >> x >> oper >> y)) {
            std::cout << "Invalid input. Please enter in the format: a + b\n";
            std::cin.clear(); // clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            continue; // prompt the user again
        }

        // check if exit condition is met (Ctrl+C will trigger this)
        if (std::cin.eof()) {
            keepRunning = false; // exit the loop
            std::cout << "\nExiting the calculator. Goodbye!\n";
            break;
        }

        // perform the calculation and display the result
        try {
            double result = calc.Calculate(x, oper, y);
            std::cout << "Result: " << result << "\n\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n\n";
        }
    }

    return 0; // exit the program
}