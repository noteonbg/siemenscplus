/*

Decorator pattern allows behavior to be added to individual objects dynamically,
 without affecting the behavior of other objects from the same class.
  It’s particularly useful when you need to add functionalities to objects in a
   flexible and reusable way1.


   Base HVAC Device:
We’ll start with a base class called HVACDevice, representing the fundamental HVAC device (e.g., air conditioner or heater).
The base class will have common properties and methods, such as turning the device on/off.

Concrete HVAC Devices:
We’ll create concrete classes for specific HVAC devices (e.g., AirConditioner, Heater).
Each concrete device will inherit from the HVACDevice base class.

Decorator Classes:
We’ll define decorator classes that enhance the behavior of HVAC devices.

Examples of decorators:
TemperatureControlDecorator: Adds temperature control functionality.
TimerDecorator: Allows setting a timer for the device.
EnergySaverDecorator: Optimizes energy consumption.

Usage:
Users can customize their HVAC devices by adding decorators to the base device.
Decorators can be stacked to create complex combinations of features.

*/



#if 1

#include <iostream>
#include <string>

// Base HVAC Device
class HVACDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Concrete Air Conditioner
class AirConditioner : public HVACDevice {
public:
    void turnOn() override {
        std::cout << "Air conditioner turned ON." << std::endl;
    }

    void turnOff() override {
        std::cout << "Air conditioner turned OFF." << std::endl;
    }
};

// Decorator: Temperature Control
class TemperatureControlDecorator : public HVACDevice {
private:
    HVACDevice* wrappedDevice;
    int desiredTemperature; // Additional property

public:
    TemperatureControlDecorator(HVACDevice* device, int temp)
        : wrappedDevice(device), desiredTemperature(temp) {}

    void turnOn() override {
        wrappedDevice->turnOn();
        std::cout << "Setting temperature to " << desiredTemperature << "°C." << std::endl;
    }

    void turnOff() override {
        wrappedDevice->turnOff();
    }
};

// Usage
int main() {
    HVACDevice* ac = new AirConditioner();

    HVACDevice* acWithTempControl = 
    new TemperatureControlDecorator(ac, 22);  //PrintWriter code

    acWithTempControl->turnOn();
    // Output: Air conditioner turned ON. Setting temperature to 22°C.

    delete acWithTempControl;
    delete ac;

    return 0;
}

#endif
