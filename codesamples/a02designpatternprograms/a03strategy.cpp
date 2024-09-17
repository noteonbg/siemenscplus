/*

The Strategy Design Pattern allows you to define a family of algorithms, encapsulate each one, and make them interchangeable. In the HVAC domain,
 this pattern can be used to implement different temperature control strategies.
 
We have an HVAC system that can operate in different modes, such as energy-saving mode,
 comfort mode, and quick-cooling mode.
  Each mode has a different algorithm for controlling the temperature.
   The Strategy pattern allows us to switch between these modes dynamically.


*/


#if 1
class TemperatureControlStrategy {
public:
    virtual void execute(float currentTemperature) = 0;
    virtual ~TemperatureControlStrategy() {}
};


#include <iostream>

class EnergySavingStrategy : public TemperatureControlStrategy {
public:
    void execute(float currentTemperature) override {
        std::cout << "Energy Saving Mode: Maintaining temperature at " << currentTemperature + 2 << " degrees." << std::endl;
    }
};

class ComfortStrategy : public TemperatureControlStrategy {
public:
    void execute(float currentTemperature) override {
        std::cout << "Comfort Mode: Maintaining temperature at " << currentTemperature << " degrees." << std::endl;
    }
};

class QuickCoolingStrategy : public TemperatureControlStrategy {
public:
    void execute(float currentTemperature) override {
        std::cout << "Quick Cooling Mode: Dropping temperature to " << currentTemperature - 5 << " degrees." << std::endl;
    }
};



class HVACController {
private:
    TemperatureControlStrategy* strategy;
public:
    HVACController(TemperatureControlStrategy* initialStrategy) : strategy(initialStrategy) {}

    ~HVACController() {
        delete strategy;
    }

    void setStrategy(TemperatureControlStrategy* newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }

    void controlTemperature(float currentTemperature) {
        strategy->execute(currentTemperature);
    }
};

int main() {
    HVACController hvacController(new EnergySavingStrategy());

    float currentTemperature = 24.0f;

    // Use energy saving strategy
    hvacController.controlTemperature(currentTemperature);

    // Switch to comfort strategy
    hvacController.setStrategy(new ComfortStrategy());
    hvacController.controlTemperature(currentTemperature);

    // Switch to quick cooling strategy
    hvacController.setStrategy(new QuickCoolingStrategy());
    hvacController.controlTemperature(currentTemperature);

    return 0;
}



#endif

/*

Strategy Interface: TemperatureControlStrategy defines the common interface for all strategies.
Concrete Strategies: EnergySavingStrategy, ComfortStrategy, and QuickCoolingStrategy implement the execute method with different temperature control algorithms.
Context: HVACController maintains a reference to a strategy object and delegates the temperature control operation to the strategy.
Client: Dynamically switches between different temperature control strategies by setting a new strategy in the HVACController.

This implementation of the Strategy Design Pattern in the HVAC context demonstrates how to
 encapsulate different temperature control algorithms and switch between them dynamically
  based on the current mode of the HVAC system. 
  This approach enhances flexibility and maintainability by allowing new strategies to be added without
   modifying the existing context or client code.

*/


