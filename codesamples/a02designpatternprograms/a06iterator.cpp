#include <iostream>
#include <vector>


#if 0
// Abstract Iterator
class SensorIterator {
public:
    virtual bool hasNext() const = 0;
    virtual Sensor* next() = 0;
};

// Concrete Iterator
class ConcreteSensorIterator : public SensorIterator {
private:
    std::vector<Sensor*> sensors;
    size_t currentIndex;

public:
    ConcreteSensorIterator(const std::vector<Sensor*>& sensors)
        : sensors(sensors), currentIndex(0) {}

    bool hasNext() const override {
        return currentIndex < sensors.size();
    }

    Sensor* next() override {
        if (hasNext()) {
            return sensors[currentIndex++];
        }
        return nullptr;
    }
};

// Abstract Aggregate
class SensorCollection {
public:
    virtual SensorIterator* createIterator() = 0;
};

// Concrete Aggregate
class HVACSensorCollection : public SensorCollection {
private:
    std::vector<Sensor*> sensors;

public:
    void addSensor(Sensor* sensor) {
        sensors.push_back(sensor);
    }

    SensorIterator* createIterator() override {
        return new ConcreteSensorIterator(sensors);
    }
};

// Example usage
int main() {
    HVACSensorCollection hvacSensors;
    hvacSensors.addSensor(new TemperatureSensor("Living Room"));
    hvacSensors.addSensor(new TemperatureSensor("Bedroom"));
    // Add more sensors...

    SensorIterator* iterator = hvacSensors.createIterator();
    while (iterator->hasNext()) {
        Sensor* sensor = iterator->next();
        std::cout << "Sensor: " << sensor->getName() << std::endl;
    }

    // Clean up memory (delete sensors and iterator)

    return 0;
}

#endif