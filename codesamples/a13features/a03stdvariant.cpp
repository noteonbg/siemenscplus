#if 1

#include <iostream>
#include <variant>
#include <string>
#include <vector>

int main() {
    // Create a variant that can hold an int or a float
    std::variant<int, float> myVariant;

    // Assign an int value
    myVariant = 42;

    if (std::holds_alternative<int>(myVariant)) {
        int intValue = std::get<int>(myVariant);
        std::cout << "Value in variant (int): " << intValue << std::endl;
    }

    // Assign a float value
    myVariant = 3.14f;
    if (std::holds_alternative<float>(myVariant)) {
        float floatValue = std::get<float>(myVariant);
        std::cout << "Value in variant (float): " << floatValue << std::endl;
    }

    // You can also use std::visit for more complex operations
    std::variant<std::vector<int>, double> data;
    data = std::vector<int>{1, 2, 3};



    

    std::visit( {
        if constexpr (std::is_same_v<decltype(value), std::vector<int>>) {
            std::cout << "Vector size: " << value.size() << std::endl;
        } else {
            std::cout << "Not a vector." << std::endl;
        }
    }, data);

    return 0;
}


#endif

#if 0

#include <iostream>
#include <variant>
#include <string>
#include <vector>

int main() {
    // Create a variant that can hold an int or a float
    std::variant<int, float> myVariant;

    // Assign an int value
    myVariant = 42;
    if (std::holds_alternative<int>(myVariant)) {
        int intValue = std::get<int>(myVariant);
        std::cout << "Value in variant (int): " << intValue << std::endl;
    }

    // Assign a float value
    myVariant = 3.14f;
    if (std::holds_alternative<float>(myVariant)) {
        float floatValue = std::get<float>(myVariant);
        std::cout << "Value in variant (float): " << floatValue << std::endl;
    }

    // You can also use std::visit for more complex operations
    std::variant<std::vector<int>, double> data;
    data = std::vector<int>{1, 2, 3};

    std::visit( {
        if constexpr (std::is_same_v<decltype(value), std::vector<int>>) {
            std::cout << "Vector size: " << value.size() << std::endl;
        } else {
            std::cout << "Not a vector." << std::endl;
        }
    }, data);

    return 0;
}


#endif

/*

Benefits of std::variant in EDA:
Clear representation of states: Each state is explicitly defined.
Type-safe transitions: You can’t accidentally transition to an invalid state.
Easy to extend: Adding new states is straightforward.



*/