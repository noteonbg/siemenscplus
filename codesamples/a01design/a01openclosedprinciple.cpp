

#if 1
#include <iostream>
#include <vector>
#include <memory>

// Abstract base class
class Device {
public:
    virtual ~Device() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Light class
class Light : public Device {
public:
    void turnOn() override {
        std::cout << "Light is turned on" << std::endl;
    }

    void turnOff() override {
        std::cout << "Light is turned off" << std::endl;
    }
};

// Thermostat class
class Thermostat : public Device {
public:
    void turnOn() override {
        std::cout << "Thermostat is turned on" << std::endl;
    }

    void turnOff() override {
        std::cout << "Thermostat is turned off" << std::endl;
    }
};

// Fan class
class Fan : public Device {
public:
    void turnOn() override {
        std::cout << "Fan is turned on" << std::endl;
    }

    void turnOff() override {
        std::cout << "Fan is turned off" << std::endl;
    }
};



// HomeAutomation class
class HomeAutomation {
public:
    void addDevice(std::shared_ptr<Device> device) {
        devices.push_back(device);
    }

    void controlDevices(bool turnOn) {
        for (const auto& device : devices) {
            if (turnOn) {
                device->turnOn();
            } else {
                device->turnOff();
            }
        }
    }

private:
    std::vector<std::shared_ptr<Device>> devices;
};

int main() {
    HomeAutomation home;
    home.addDevice(std::make_shared<Light>());
    home.addDevice(std::make_shared<Thermostat>());
    home.addDevice(std::make_shared<Fan>());

    home.controlDevices(true);  // Turn on all devices
    home.controlDevices(false); // Turn off all devices

    return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <memory>

// Abstract base class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double calculateArea() const = 0;
};

/*

 Each specific shape will derive from Shape and implement the calculateArea method.
  This way, new shapes can be added without modifying the existing code.

*/

// Rectangle class
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double calculateArea() const override {
        return width * height;
    }

private:
    double width;
    double height;
};

// Circle class
class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

// AreaCalculator class
class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<std::shared_ptr<Shape>>& shapes) const {
        double totalArea = 0;
        for (const auto& shape : shapes) {
            totalArea += shape->calculateArea();
        }
        return totalArea;
    }
};

int main() {
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Rectangle>(10, 20));
    shapes.push_back(std::make_shared<Circle>(5));

    AreaCalculator calc;
    std::cout << "Total Area: " << calc.calculateTotalArea(shapes) << std::endl;
    return 0;
}

#endif
