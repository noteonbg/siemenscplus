#if 1

#include <iostream>
#include <any>
#include <string>

// Define a generic EDA component
struct EDAComponent {
    std::string name;
    std::any properties; // Store properties (e.g., delay, power, area)
};

int main() {
    // Create an AND gate component
    EDAComponent andGate;
    andGate.name = "AND Gate";
    andGate.properties = std::make_pair(2.5, "ns"); // Delay: 2.5 ns

    // Create a flip-flop component
    EDAComponent flipFlop;
    flipFlop.name = "D Flip-Flop";
    flipFlop.properties = std::make_pair(0.5, "W"); // Power: 0.5 W

    // Access and display component properties
    std::cout << andGate.name << " Delay: "
              << std::any_cast<std::pair<double, std::string>>(andGate.properties).first
              << " " << std::any_cast<std::pair<double, std::string>>(andGate.properties).second << std::endl;

    std::cout << flipFlop.name << " Power: "
              << std::any_cast<std::pair<double, std::string>>(flipFlop.properties).first
              << " " << std::any_cast<std::pair<double, std::string>>(flipFlop.properties).second << std::endl;

    return 0;
}


#endif