#if 1

#include <iostream>
#include <string>

// Abstract class representing the HVAC device builder
class HVACDeviceBuilder {
public:
    void assembleDevice() {
        // Common steps for all devices
        connectPower();
        installComponents();
        testDevice();

        // Specific steps (to be implemented by subclasses)
        customizeDevice();
    }

    // Common steps
    void connectPower() {
        std::cout << "Connecting power supply." << std::endl;
    }

    void installComponents() {
        std::cout << "Installing standard components." << std::endl;
    }

    void testDevice() {
        std::cout << "Running device tests." << std::endl;
    }

    // Abstract method (to be overridden by subclasses)
    virtual void customizeDevice() = 0;
};

// Concrete subclass for building an air conditioner
class AirConditionerBuilder : public HVACDeviceBuilder {
public:
    void customizeDevice() override {
        std::cout << "Adding cooling coils and adjusting settings." << std::endl;
    }
};

// Concrete subclass for building a heater
class HeaterBuilder : public HVACDeviceBuilder {
public:
    void customizeDevice() override {
        std::cout << "Installing heating elements and adjusting temperature." << std::endl;
    }
};

int main() {
    // Build an air conditioner
    AirConditionerBuilder acBuilder;
    std::cout << "Assembling air conditioner:" << std::endl;
    acBuilder.assembleDevice();
    std::cout << std::endl;

    // Build a heater
    HeaterBuilder heaterBuilder;
    std::cout << "Assembling heater:" << std::endl;
    heaterBuilder.assembleDevice();

    return 0;
}


#endif

/*


The Template Method pattern defines the skeleton of an algorithm in a superclass but allows
subclasses to override specific steps of the algorithm without changing its overall structure

We want to design a system that can build different types of HVAC devices 
(e.g., air conditioners, heaters, fans). Each device has a common structure for assembly,
 but specific steps may vary based on the type of device.

 Abstract Class (or Interface):
We’ll create an abstract class called HVACDeviceBuilder. This class defines the template method (assembleDevice()) that represents the overall algorithm for building an HVAC device.
The template method will consist of several steps, some of which will be abstract (to be implemented by subclasses) and others concrete (common to all devices).
Concrete Subclasses:
We’ll create concrete subclasses for specific HVAC devices (e.g., AirConditionerBuilder, HeaterBuilder, etc.).
Each subclass will provide concrete implementations for the abstract steps defined in the HVACDeviceBuilder.
Abstract (or Hook) Methods:
These are placeholders for steps in the algorithm that should be implemented by subclasses. In our case, these methods represent specific assembly steps for different devices.





*/