#if 0

#include <iostream>
#include <vector>

struct MySwappableType {
    std::vector<int> v;

    // Default constructor (not assignable)
    MySwappableType() = default;

    // Custom swap method
    void swap(MySwappableType& other) {
        std::swap(v, other.v);
    }
};

int main() {
    MySwappableType v1{{1, 2, 3}};
    MySwappableType v2{{4, 5, 6}};

    // Swap v1 and v2 using custom swap method
    v1.swap(v2);

    // Print the swapped vectors
    std::cout << "v1: {";
    for (const auto& elem : v1.v) {
        std::cout << elem << ", ";
    }
    std::cout << "}\n";

    std::cout << "v2: {";
    for (const auto& elem : v2.v) {
        std::cout << elem << ", ";
    }
    std::cout << "}\n";

    return 0;
}


#endif

#if 0


#include <iostream>

class MyClass {
public:
    // Default constructor
    MyClass() = default;

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        // Transfer resources from 'other' to 'this'
        // Properly release other  resources if needed
        // ...
        
        return *this;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2;

    // Move-assign obj2 to obj1
    obj1 = std::move(obj2);

    // Print a message to indicate successful move assignment
    std::cout << "Move assignment completed successfully!\n";

    return 0;
}


#endif