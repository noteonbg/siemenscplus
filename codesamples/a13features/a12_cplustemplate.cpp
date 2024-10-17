#include <iostream>
#include <concepts>

//C++ 20 code sample of the same.

// Concept to restrict to integral types
template<typename T>
concept Integral = std::is_integral_v<T>;

// Function template using the Integral concept
void printValue(Integral auto value) {
    std::cout << "The value is: " << value << std::endl;
}

int main() {
    printValue(42);      // OK, 42 is an integral type
    printValue(3.14); // Compile-time error, 3.14 is not an integral type
    return 0;
}
