#if 0

/*
Relaxed Constraints on Constexpr Functions (C++14):
In C++14, constexpr functions can contain more features than in C++11.
Specifically, constexpr-declared functions may now include:
Any declarations except static or thread_local variables or variable declarations without initializers.
Conditional branching statements (if and switch).
Looping statements (including range-based for loops).

*/


#include <iostream>

// Relaxed constexpr function to compute factorial
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int num = 5; // Compute factorial for 5

    // Compile-time evaluation
    constexpr int result = factorial(num);

    std::cout << "Factorial of " << num << " is " << result << "\n";
    return 0;
}




#endif