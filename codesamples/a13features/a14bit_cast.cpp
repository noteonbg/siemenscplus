#if 1

#include <iostream>
#include <cstdint>
#include <bit> // For std::bit_cast

int main() {
    // Example 1: Reinterpret bits of one object as another type
    float f = 3.14f;
    uint32_t i = std::bit_cast<uint32_t>(f); // Reinterpret float as uint32_t

    std::cout << "Float: " << f << std::endl;
    std::cout << "Bits as uint32_t: " << std::hex << i << std::endl;

    // Example 2: Reinterpret bits of one object as another type (reverse)
    uint64_t bits = 0x40490fdbff4c4a9a;
    double d = std::bit_cast<double>(bits); // Reinterpret uint64_t as double

    std::cout << "Bits as uint64_t: " << std::hex << bits << std::endl;
    std::cout << "Double: " << d << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>
#include <bit> // For std::bit_cast

// Abstract base class for electronic components
class Component {
public:
    virtual void simulate() = 0; // Pure virtual function for simulation
};

// Concrete class representing a resistor
class Resistor : public Component {
private:
    double resistance; // Resistance value in ohms

public:
    Resistor(double r) : resistance(r) {}

    // Simulate the resistor
    void simulate() override {
        std::cout << "Simulating Resistor with resistance " << resistance << " ohms.\n";
        // Example usage of bit_cast: Convert resistance to an integer for low-level manipulation
        uint64_t bits = std::bit_cast<uint64_t>(resistance);
        std::cout << "Bits representing resistance: " << std::hex << bits << std::endl;
    }
};

// Concrete class representing a capacitor
class Capacitor : public Component {
private:
    double capacitance; // Capacitance value in farads

public:
    Capacitor(double c) : capacitance(c) {}

    // Simulate the capacitor
    void simulate() override {
        std::cout << "Simulating Capacitor with capacitance " << capacitance << " farads.\n";
        // Example usage of bit_cast: Convert capacitance to an integer for low-level manipulation
        uint64_t bits = std::bit_cast<uint64_t>(capacitance);
        std::cout << "Bits representing capacitance: " << std::hex << bits << std::endl;
    }
};

// Library class for EDA concepts
class EDALibrary {
private:
    std::vector<Component*> components; // Vector to store components

public:
    // Add a component to the library
    void addComponent(Component* component) {
        components.push_back(component);
    }

    // Simulate all components in the library
    void simulateAll() {
        for (Component* component : components) {
            component->simulate();
        }
    }
};

int main() {
    // Create an instance of the EDA library
    EDALibrary library;

    // Create some components and add them to the library
    Resistor r1(1000); // 1000 ohm resistor
    Capacitor c1(0.001); // 1 millifarad capacitor

    library.addComponent(&r1);
    library.addComponent(&c1);

    // Simulate all components in the library
    library.simulateAll();

    return 0;
}


#endif