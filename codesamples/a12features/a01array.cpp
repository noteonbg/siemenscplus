#include <iostream>
#include <array>

// Define your custom component type
struct MyComponent {
    int id;
    double value;

    MyComponent(int i, double v) : id(i), value(v) {}
};

int main() {
    // Create an array of MyComponent objects
    std::array<MyComponent, 3> components = {
        MyComponent(1, 10.5),
        MyComponent(2, 20.0),
        MyComponent(3, 15.3)
    };

    // Access and manipulate array elements
    for (const auto& comp : components) {
        std::cout << "Component ID: " << comp.id << ", Value: " << comp.value << std::endl;
    }

    // Modify an element
    components[1].value = 22.8;

    std::cout << "Updated value for Component 2: " << components[1].value << std::endl;

    return 0;
}
