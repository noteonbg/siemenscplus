#include <iostream>
#include <optional>

// A function that returns an optional integer
std::optional<int> divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return std::nullopt; // Return an empty optional
    }
}

int main() {
    int numerator = 10;
    int denominator = 2;

    // Call the divide function
    auto result = divide(numerator, denominator);

    if (result) {
        std::cout << "Result: " << *result << std::endl;
    } else {
        std::cout << "Division by zero!" << std::endl;
    }

    return 0;
}
