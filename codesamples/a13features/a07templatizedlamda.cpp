#if 0

#include <iostream>

// Templated lambda that takes any type T and prints it
auto print_value = []<typename T>(T value) {
    std::cout << "Value: " << value << '\n';
};

int main() {
    print_value(42); // Prints "Value: 42"
    print_value("Hello, world!"); // Prints "Value: Hello, world!"
    return 0;
}


#endif