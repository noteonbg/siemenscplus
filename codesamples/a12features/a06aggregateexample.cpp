/*

An aggregate class is a class that satisfies the following conditions:
It has no user-declared constructors (i.e., no constructors explicitly defined by the programmer).
It has no private or protected non-static data members (all data members are public).
It has no base classes (i.e., it is not derived from any other class).
It has no virtual functions.

C++ allows you to directly initialize an aggregate class using a brace-enclosed initializer list.
This feature simplifies the process of initializing aggregate objects.
Examples of aggregate initialization include setting up arrays, structs, and classes without user-defined constructors.

*/

#if 1

#include <iostream>
#include <string>

// Define an aggregate class for electronic components
struct Component {
    std::string name;
    double value;  // Resistance, capacitance, etc.
    int pinCount;
};

int main() {
    // Create an instance of the Component class using aggregate initialization
    Component resistor{"R1", 1000.0, 2};

    // Print out the component details
    std::cout << "Component Name: " << resistor.name << "\n";
    std::cout << "Value: " << resistor.value << " ohms\n";
    std::cout << "Pin Count: " << resistor.pinCount << "\n";

    return 0;
}


#endif