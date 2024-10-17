#if 1

#include <iostream>
#include <vector>

int main() {
    // Example 1: Copy-List-Initialization (auto deduction)
    auto a = {42}; // std::initializer_list<int>
    auto c = {1, 2}; // std::initializer_list<int>

    // Example 2: Direct-List-Initialization (auto deduction)
    auto b {42}; // int
    // Uncomment the line below to see the compilation error:
     //auto d {1, 2}; // Error (too many elements)

    // Print results
    std::cout << "a type: " << typeid(a).name() << "\n";
    std::cout << "b type: " << typeid(b).name() << "\n";
    std::cout << "c type: " << typeid(c).name() << "\n";

    return 0;
}


#endif