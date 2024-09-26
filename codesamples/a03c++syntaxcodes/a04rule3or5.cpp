#ifndef HVACUNIT_H
#define HVACUNIT_H

#include <cstring> // For std::strlen and std::strcpy
#include <iostream>


//person X is writing this
class HVACUnit {
public:
    // Constructor
    HVACUnit(const char* name, float initialTemperature)
        : temperature(initialTemperature) {
        if (name) {
            size_t len = std::strlen(name) + 1;
            this->name = new char[len];
            std::strcpy(this->name, name);
        } else {
            this->name = nullptr;
        }
    }

    // Destructor
    ~HVACUnit() {
        delete[] name;
    }

    // Copy Constructor
    HVACUnit(const HVACUnit& other)
        : temperature(other.temperature) {
        if (other.name) {
            size_t len = std::strlen(other.name) + 1;
            name = new char[len];
            std::strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }

    // Copy Assignment Operator
    HVACUnit& operator=(const HVACUnit& other) {
        if (this == &other) {
            return *this; // self-assignment check
        }
        delete[] name;
        temperature = other.temperature;
        if (other.name) {
            size_t len = std::strlen(other.name) + 1;
            name = new char[len];
            std::strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        return *this;
    }

    // Move Constructor
    HVACUnit(HVACUnit&& other) noexcept
        : name(other.name), temperature(other.temperature) {
        other.name = nullptr;
    }

    // Move Assignment Operator
    HVACUnit& operator=(HVACUnit&& other) noexcept {
        if (this == &other) {
            return *this; // self-assignment check
        }
        delete[] name;
        name = other.name;
        temperature = other.temperature;
        other.name = nullptr;
        return *this;
    }

    // Other methods
    void setTemperature(float temp) {
        temperature = temp;
    }

    float getTemperature() const {
        return temperature;
    }

    const char* getName() const {
        return name;
    }

private:
    char* name;
    float temperature;
};

#endif // HVACUNIT_H

#include "HVACUnit.h"


//person Y writing this
int main() {
    HVACUnit unit1("Heater", 70.0f);
    std::cout << unit1.getName() << " Temperature: " << unit1.getTemperature() << "°F" << std::endl;

    HVACUnit unit2 = unit1; // Copy Constructor
    std::cout << "Copied " << unit2.getName() << " Temperature: " << unit2.getTemperature() << "°F" << std::endl;

    HVACUnit unit3("Cooler", 65.0f);
    unit3 = unit1; // Copy Assignment Operator
    std::cout << "Assigned " << unit3.getName() << " Temperature: " << unit3.getTemperature() << "°F" << std::endl;

    HVACUnit unit4 = std::move(unit1); // Move Constructor
    std::cout << "Moved " << unit4.getName() << " Temperature: " << unit4.getTemperature() << "°F" << std::endl;

    HVACUnit unit5("Ventilator", 75.0f);
    unit5 = std::move(unit3); // Move Assignment Operator
    std::cout << "Move Assigned " << unit5.getName() << " Temperature: " << unit5.getTemperature() << "°F" << std::endl;

    return 0;
}
