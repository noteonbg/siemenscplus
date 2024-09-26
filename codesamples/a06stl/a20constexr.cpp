/*

he constexpr specifier in C++ allows you to declare that a value or function can be evaluated at compile time. It is used for performance improvement by doing 
computations during compilation rather than at runtime

A constexpr function should contain only one return statement (in C++11), 
but C++14 allows more than one statement.
It can refer only to constant global variables and call
 only other constexpr functions.

*/


#include <iostream>

constexpr int product(int x, int y) {
    return x * y;
}

int main() {
    constexpr int x = product(10, 20);
    std::cout << x; // Output: 200
    return 0;
}


#if 0

#include <iostream>

constexpr int arraySize = 2 * 3; // Calculate array size at compile time

int main() {
    int arr[arraySize] = {1, 2, 3, 4, 5, 6};
    std::cout << arr[5]; // Output: 6
    return 0;
}




#endif


#if 0

#include <iostream>
#include <cmath>

constexpr double PI = 3.14159265359;

constexpr double ConvertDegreeToRadian(const double& dDegree) {
    return dDegree * (PI / 180);
}

int main() {
    auto dAngleInRadian = ConvertDegreeToRadian(90.0);
    std::cout << "Angle in radian: " << dAngleInRadian; // Output: 1.5708
    return 0;
}


#endif

#if 0

#include <iostream>

constexpr int factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int fact5 = factorial(5);
    std::cout << "Factorial of 5: " << fact5; // Output: 120
    return 0;
}




#endif