#if 1


#include <iostream>
#include <cmath> // For std::abs
#include <bit>   // For std::midpoint

int main() {
    // Example 1: Finding the midpoint of two integers
    int a = 10;
    int b = 20;

    int mid1 = std::midpoint(a, b); // Midpoint of two integers
    std::cout << "Midpoint of " << a << " and " << b << " is: " << mid1 << std::endl;

    // Example 2: Finding the midpoint of two floating-point numbers
    double x = 10.5;
    double y = 20.5;

    double mid2 = std::midpoint(x, y); // Midpoint of two floating-point numbers
    std::cout << "Midpoint of " << x << " and " << y << " is: " << mid2 << std::endl;

    // Example 3: Finding the midpoint of two values of different types
    float m = 5.5f;
    int n = 10;

    auto mid3 = std::midpoint(m, n); // Midpoint of a float and an int
    std::cout << "Midpoint of " << m << " and " << n << " is: " << mid3 << std::endl;

    return 0;
}


#endif