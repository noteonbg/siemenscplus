#if 0

#include <iostream>
#include <tuple>

// Example struct
struct Point {
    int x;
    int y;
};

int main() {
    // Example 1: Structured binding for a tuple
    std::tuple<int, double, std::string> myTuple = {42, 3.14, "hello"};
    auto [a, b, c] = myTuple;
    std::cout << "Tuple elements: " << a << ", " << b << ", " << c << "\n";

    // Example 2: Structured binding for a struct
    Point p = {1, 2};
    auto [x_coord, y_coord] = p;
    std::cout << "X Coordinate: " << x_coord << "\n";
    std::cout << "Y Coordinate: " << y_coord << "\n";

    return 0;
}


#endif

#if 1

#include <iostream>
#include <utility> // for std::pair

// Example EDA netlist representation
using NetlistEntry = std::pair<std::string, std::string>;

int main() {
    // Create an EDA netlist entry
    NetlistEntry entry = {"R1", "Net1"};

    // Extract component name and net using structured bindings
    auto [componentName, netName] = entry;

    std::cout << "Component Name: " << componentName << "\n";
    std::cout << "Net Name: " << netName << "\n";

    return 0;
}


#endif