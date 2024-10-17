#if 0

#include <iostream>

// Define an enum for different shapes
enum class ShapeType {
    Circle,
    Rectangle,
    Triangle
};

// Create a struct to represent a shape
struct Shape {
    ShapeType type;
    double area; // For demonstration purposes
};

// Function to calculate the area of a shape
double calculateArea(const Shape& shape) {
    switch (shape.type) {
        case ShapeType::Circle:
            return 3.14 * 5.0 * 5.0; // Assuming a circle with radius 5
        case ShapeType::Rectangle:
            return 10.0 * 6.0; // Assuming a rectangle with sides 10 and 6
        case ShapeType::Triangle:
            return 0.5 * 8.0 * 4.0; // Assuming a triangle with base 8 and height 4
        default:
            return 0.0; // Invalid shape
    }
}

int main() {
    // Create instances of different shapes
    Shape circle{ ShapeType::Circle, calculateArea(circle) };
    Shape rectangle{ ShapeType::Rectangle, calculateArea(rectangle) };
    Shape triangle{ ShapeType::Triangle, calculateArea(triangle) };

    // Display the areas
    std::cout << "Area of the circle: " << circle.area << std::endl;
    std::cout << "Area of the rectangle: " << rectangle.area << std::endl;
    std::cout << "Area of the triangle: " << triangle.area << std::endl;

    return 0;
}


#endif

#if 1

#include <iostream>

// Define an enum for different digital components
enum class ComponentType {
    Gate,
    FlipFlop,
    Decoder,
    // Add more as needed
};

// Create a struct to represent a digital component
struct DigitalComponent {
    ComponentType type;
    // Other relevant properties...
};

// Function to simulate the behavior of a digital component
void simulateComponent(const DigitalComponent& component) {
    switch (component.type) {
        case ComponentType::Gate:
            std::cout << "Simulating a logic gate..." << std::endl;
            // Logic gate behavior
            break;
        case ComponentType::FlipFlop:
            std::cout << "Simulating a flip-flop..." << std::endl;
            // Flip-flop behavior
            break;
        case ComponentType::Decoder:
            std::cout << "Simulating a decoder..." << std::endl;
            // Decoder behavior
            break;
        // Handle other component types
        default:
            std::cout << "Unknown component type." << std::endl;
    }
}

int main() {
    // Create instances of different digital components
    DigitalComponent gate{ ComponentType::Gate };
    DigitalComponent flipFlop{ ComponentType::FlipFlop };
    DigitalComponent decoder{ ComponentType::Decoder };

    // Simulate their behavior
    simulateComponent(gate);
    simulateComponent(flipFlop);
    simulateComponent(decoder);

    return 0;
}



#endif

/*

Enums are useful for creating named constants and ensuring type safety.


n C, an enum constant is of type int. However, in C++, it’s of the enumerated type itself.

enum en_e {
    en_e_foo,
    en_e_bar = UINT64_MAX
};

Comparison of Enums

struct Enumerator {
    enum Values { VALUE = 5 };
};

template<int V>
struct TemplatedEnumerator {
    enum Values { VALUE = V };
};

// Comparing enums
if (static_cast<int>(Enumerator::VALUE) == static_cast<int>(TemplatedEnumerator<5>::VALUE)) {
    // ...
}

Alternatively, you can provide your own comparison operators for named enums:

template <int V>
bool operator==(Enumerator::Values lhs, typename TemplatedEnumerator<V>::Values rhs) {
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}

template <int V>
bool operator==(typename TemplatedEnumerator<V>::Values rhs, Enumerator::Values lhs) {
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}




*/