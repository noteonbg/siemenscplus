#if 1

#include <vector>

//observer interface
class HVACObserver {
public:
    virtual void update(float temperature) = 0;
    virtual ~HVACObserver() {}//..C++ fate and not oo
};




//subject interface or place where event occurs
class HVACSubject {
public:
    virtual void attach(HVACObserver* observer) = 0;
    virtual void detach(HVACObserver* observer) = 0;
    virtual void notify() = 0;
    virtual ~HVACSubject() {}
};


#include <iostream>
#include <vector>
#include <algorithm>


//Event source.. how.. look it realizes the interface HVACSubject
class HVACSystemAnother : public HVACSubject {
private:
    HVACObserver* observer;
    float temperature;

public:
    HVACSystemAnother() : temperature(0.0f) {}

    void attach(HVACObserver* observer) override {
        this->observer=observer;
    }

    void detach(HVACObserver* observer) override {
        this->observer=nullptr;
    }

    void notify() override {
         {
            observer->update(temperature);
        
    }

    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notify();
    }

    float getTemperature() const {
        return temperature;
    }
};


// a real class where event occurs

class HVACSystem : public HVACSubject {
private:
    std::vector<HVACObserver*> observers;
    float temperature;

public:
    HVACSystem() : temperature(0.0f) {}

    void attach(HVACObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(HVACObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (HVACObserver* observer : observers) {
            observer->update(temperature);
        }
    }

    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notify();
    }

    float getTemperature() const {
        return temperature;
    }
};


// concrete observers, places where events are needed.
#include <iostream>

class DisplayUnit : public HVACObserver {
public:
    void update(float temperature) override {
        std::cout << "Display Unit: Current temperature is " << temperature << " degrees." << std::endl;
    }
};

class MonitoringSystem : public HVACObserver {
public:
    void update(float temperature) override {
        std::cout << "Monitoring System: Received temperature update: " << temperature << " degrees." << std::endl;
    }
};


//main code just to show the whole flow

int main() {
    HVACSystem hvacSystem;//Event source

    DisplayUnit display;
    MonitoringSystem monitoring;

    hvacSystem.attach(&display);  //proves that dislay and monitoring are event listeners
    hvacSystem.attach(&monitoring);

    hvacSystem.setTemperature(22.5f);  // Notify observers of the temperature change

    hvacSystem.detach(&display);

    hvacSystem.setTemperature(25.0f);  // Notify remaining observers

    return 0;
}

/*

Observer Interface: HVACObserver defines the update method.
Subject Interface: HVACSubject defines methods to attach, detach, and notify observers.
Concrete Subject: HVACSystem maintains a list of observers and notifies them of temperature changes.
Concrete Observers: DisplayUnit and MonitoringSystem implement the update method to react to changes.
In this implementation, the HVACSystem acts as the subject that holds a list of observers.
 When the temperature changes, 
 the HVACSystem notifies all attached observers by calling their update method. 
 Observers like DisplayUnit and MonitoringSystem react to these updates, 
 for example, by displaying the new temperature or logging it.



 


*/


#endif