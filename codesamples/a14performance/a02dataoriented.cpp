#if 1

#include <iostream>
#include <vector>
#include <string>

// Component data

//Array of structures no structure of Arrays
struct Components {
    std::vector<std::string> names;
    std::vector<int> pinCounts;
    std::vector<double> powerConsumptions;
};

// Function to add a component
void addComponent(Components& components, const std::string& name, int pinCount, double powerConsumption) {
    components.names.push_back(name);
    components.pinCounts.push_back(pinCount);
    components.powerConsumptions.push_back(powerConsumption);
}

// Function to print component information
void printComponents(const Components& components) {
    std::cout << "Component Information:\n";
    for (size_t i = 0; i < components.names.size(); ++i) {
        std::cout << "Name: " << components.names[i]
                  << ", Pins: " << components.pinCounts[i]
                  << ", Power: " << components.powerConsumptions[i] << " W\n";
    }
}

int main() {
    Components allComponents;

    // Add some components
    addComponent(allComponents, "Resistor R1", 2, 0.1);
    addComponent(allComponents, "Capacitor C2", 3, 0.05);
    addComponent(allComponents, "Transistor T3", 4, 0.2);

    // Print component information
    printComponents(allComponents);

    return 0;
}



#endif