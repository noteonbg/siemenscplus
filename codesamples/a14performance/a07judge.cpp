#if 1

#include <iostream>
#include <string>

struct Component {
    std::string type; // Type of the component (Resistor, Capacitor)
    double value;     // Value (Resistance in Ohms, Capacitance in Farads)
};

void printComponents(const Component components[], int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Type: " << components[i].type 
                  << ", Value: " << components[i].value << std::endl;
    }
}

int main() {
    const int componentCount = 3;
    Component components[componentCount] = {
        {"Resistor", 100.0},     // 100 Ohm resistor
        {"Capacitor", 0.001},    // 1 mF capacitor
        {"Resistor", 200.0}      // 200 Ohm resistor
    };

    std::cout << "Array of Structures:" << std::endl;
    printComponents(components, componentCount);

    return 0;
}


#endif

#if 0

#include <iostream>
#include <string>

struct ComponentData {
    std::string types[3];   // Types of components
    double values[3];       // Values (Resistance in Ohms, Capacitance in Farads)
};

void printComponents(const ComponentData& data) {
    for (int i = 0; i < 3; ++i) {
        std::cout << "Type: " << data.types[i] 
                  << ", Value: " << data.values[i] << std::endl;
    }
}

int main() {
    ComponentData data = {
        {"Resistor", "Capacitor", "Resistor"},
        {100.0, 0.001, 200.0} // 100 Ohm, 1 mF, 200 Ohm
    };

    std::cout << "\nStructure of Arrays:" << std::endl;
    printComponents(data);

    return 0;
}



#endif