#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

// Enumeration for component types
enum class ComponentType {
    Resistor,
    Capacitor,
    Inductor
};

// Class representing a generic electronic component
class Component {
public:
    Component(ComponentType type, double value)
        : type(type), value(value) {
        if (value <= 0) {
            throw std::invalid_argument("Component value must be positive.");
        }
    }

    virtual ~Component() {
        std::cout << "Component destroyed." << std::endl;
    }

    virtual void display() const {
        std::cout << "Component Type: " << static_cast<int>(type)
                  << ", Value: " << value << std::endl;
    }

private:
    ComponentType type;
    double value;
};

// Class to manage a collection of components
class Circuit {
public:
    void addComponent(std::unique_ptr<Component> component) {
        components.push_back(std::move(component));
    }

    void showComponents() const {
        if (components.empty()) {
            std::cout << "No components in the circuit." << std::endl;
            return;
        }
        for (const auto& comp : components) {
            comp->display();
        }
    }

private:
    std::vector<std::unique_ptr<Component>> components; // Smart pointer for memory management
};

// Function to demonstrate the component management
void manageCircuit() {
    Circuit circuit;

    try {
        circuit.addComponent(std::make_unique<Component>(ComponentType::Resistor, 1000));
        circuit.addComponent(std::make_unique<Component>(ComponentType::Capacitor, 0.01));
        circuit.addComponent(std::make_unique<Component>(ComponentType::Inductor, 0.1));
        
        // Attempting to add an invalid component
        circuit.addComponent(std::make_unique<Component>(ComponentType::Resistor, -500)); // This will throw an exception
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    circuit.showComponents(); // Display the components in the circuit
}

int main() {
    manageCircuit();
    return 0;
}

/*

Type Safe Enumerations (DCL12-CPP):

The ComponentType enum is defined as a strongly typed enumeration using enum class, providing type safety.
Resource Management (DCL30-CPP):

std::unique_ptr is used in the Circuit class to manage dynamic memory for components, ensuring that resources are released automatically.
Bounds Checking and Exception Safety (DCL36-CPP, ERR06-CPP):

The Component constructor checks for valid values and throws an exception if an invalid value is provided, demonstrating proper exception handling.
The Circuit class checks if components are empty before displaying them, preventing access to invalid memory.
Initialization and Input Validation (DCL51-CPP):

The value of components is validated during initialization to ensure that it is positive, avoiding potential issues with invalid data.

stupidity is unlimited examples

1. calling virtual functions in constructors.
2. not handling exceptions in destructors.
3. violating array boundaries...





*/
