#if 1

#include <iostream>
#include <array>
#include <algorithm> // For std::for_each

int main() {
    // Example: Convert a braced-init-list to a std::array
    auto arr = std::to_array({1, 2, 3, 4, 5}); // Convert {1, 2, 3, 4, 5} to std::array

    // Print the elements of the std::array
    std::cout << "Array elements: ";
    std::for_each(arr.begin(), arr.end(), [](int val) {
        std::cout << val << " ";
    });
    std::cout << std::endl;

    return 0;
}

#endif

#if 0

#include <iostream>
#include <array> // For std::array
#include <algorithm> // For std::for_each

// Abstract base class for electronic components
class Component {
public:
    virtual void simulate() = 0; // Pure virtual function for simulation
};

// Concrete class representing a resistor
class Resistor : public Component {
private:
    std::array<double, 3> resistances; // Resistance values in ohms

public:
    Resistor(std::array<double, 3> r) : resistances(r) {}

    // Simulate the resistor
    void simulate() override {
        std::cout << "Simulating Resistor with resistance values: ";
        std::for_each(resistances.begin(), resistances.end(), [](double resistance) {
            std::cout << resistance << " ohms ";
        });
        std::cout << std::endl;
        // Actual simulation code would go here
    }
};

// Concrete class representing a capacitor
class Capacitor : public Component {
private:
    std::array<double, 3> capacitances; // Capacitance values in farads

public:
    Capacitor(std::array<double, 3> c) : capacitances(c) {}

    // Simulate the capacitor
    void simulate() override {
        std::cout << "Simulating Capacitor with capacitance values: ";
        std::for_each(capacitances.begin(), capacitances.end(), [](double capacitance) {
            std::cout << capacitance << " farads ";
        });
        std::cout << std::endl;
        // Actual simulation code would go here
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
    Resistor r(std::to_array({1000.0, 2200.0, 3300.0})); // Resistance values in ohms
    Capacitor c(std::to_array({0.001, 0.01, 0.1})); // Capacitance values in farads

    library.addComponent(&r);
    library.addComponent(&c);

    // Simulate all components in the library
    library.simulateAll();

    return 0;
}


#endif