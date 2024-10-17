#if 1

#include <iostream>

int main() {
    int x = 5;

    //Lamda capture initializers.
    // Lambda captures 'x' and initializes 'y' to x + 10
    auto lambda = [y = x + 10] {
        return y;
    };

    std::cout << "Result: " << lambda() << "\n"; // Prints 15

    return 0;
}

#endif

