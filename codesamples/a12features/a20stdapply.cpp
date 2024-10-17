#if 0

#include <iostream>
#include <tuple>
#include <functional>

// A simple function
void printSum(int a, int b) {
    std::cout << "Sum: " << (a + b) << std::endl;
}

int main() {
    // Example using std::invoke
    std::invoke(printSum, 5, 10); // Direct invocation with individual arguments

    // Example using std::apply
    auto args = std::make_tuple(5, 10);
    std::apply(printSum, args); // Unpacking the tuple and invoking

    return 0;
}

#endif