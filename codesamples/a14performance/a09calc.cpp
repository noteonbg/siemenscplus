#include <iostream>

// Function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

int main() {
    double num1 = 10.0;
    double num2 = 5.0;

    double sum = add(num1, num2);
    double difference = subtract(num1, num2);
    double product = multiply(num1, num2);
    double quotient;

    if (num2 != 0) {
        quotient = divide(num1, num2);
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 1; // Exit with error
    }

    // Output results
    std::cout << "Results:\n";
    std::cout << num1 << " + " << num2 << " = " << sum << std::endl;
    std::cout << num1 << " - " << num2 << " = " << difference << std::endl;
    std::cout << num1 << " * " << num2 << " = " << product << std::endl;
    std::cout << num1 << " / " << num2 << " = " << quotient << std::endl;

    return 0;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}
