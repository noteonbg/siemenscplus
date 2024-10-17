#if 0

//•	variable templates 

#include <iostream>

// Define a variable template for Euler's number
template <typename T>
constexpr T e = T(2.718281828459045);

int main() {
    // Instantiate the variable template with different types
    std::cout << "Integer Type of e: " << e<int> << std::endl;
    std::cout << "Float Type of e: " << e<float> << std::endl;

    return 0;
}


#endif