/*

Let's implement the Factory Design Pattern in the HVAC domain. 
The Factory Pattern allows you to create objects without specifying the exact class
 of object that will be created. This is useful when the type of object isn't known until runtime.

 We want to create different types of HVAC components such as heaters, coolers, and fans. 
 We use a factory to encapsulate the creation logic for these components.

*/

#if 1

class HVACComponent {
public:
    virtual void operate() = 0;
    virtual ~HVACComponent() {}
};


#include <iostream>

class Heater : public HVACComponent {
public:
    void operate() override {
        std::cout << "Heater is operating." << std::endl;
    }
};

class Cooler : public HVACComponent {
public:
    void operate() override {
        std::cout << "Cooler is operating." << std::endl;
    }
};

class Fan : public HVACComponent {
public:
    void operate() override {
        std::cout << "Fan is operating." << std::endl;
    }
};


#include <string>

class HVACFactory {
public:
    enum class ComponentType {
        Heater,
        Cooler,
        Fan
    };

    static HVACComponent* createComponent(ComponentType type) {
        switch (type) {
            case ComponentType::Heater:
                return new Heater();
            case ComponentType::Cooler:
                return new Cooler();
            case ComponentType::Fan:
                return new Fan();
            default:
                return nullptr;
        }
    }
};

int main() {
    HVACFactory::ComponentType componentType;

    // Create and use a Heater
    componentType = HVACFactory::ComponentType::Heater;
    HVACComponent* heater = HVACFactory::createComponent(componentType);
    heater->operate();
    delete heater;

    // Create and use a Cooler
    componentType = HVACFactory::ComponentType::Cooler;
    HVACComponent* cooler = HVACFactory::createComponent(componentType);
    cooler->operate();
    delete cooler;

    // Create and use a Fan
    componentType = HVACFactory::ComponentType::Fan;
    HVACComponent* fan = HVACFactory::createComponent(componentType);
    fan->operate();
    delete fan;

    return 0;
}



#endif

