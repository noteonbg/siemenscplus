#include <iostream>
#include <functional>

class Calculator {
public:
    Calculator() {
        // Initialize the lambda expression as a member variable
        addFunction = [](int a, int b) { return a + b; };
    }

    // Method to set a custom add function
    void setAddFunction(std::function<int(int, int)> func) {
        addFunction = func;
    }

    // Method to perform addition using the stored add function
    int add(int a, int b) const {
        return addFunction(a, b);
    }

private:
    std::function<int(int, int)> addFunction;
};

int main() {
    // Create an instance of the Calculator class
    Calculator calc;

    // Use the default add function
    std::cout << "Default Add: " << calc.add(5, 3) << std::endl;

    // Define and set a custom add function using a lambda expression
    calc.setAddFunction([](int a, int b) { return a * b; });
    std::cout << "Custom Multiply: " << calc.add(5, 3) << std::endl;

    return 0;
}
