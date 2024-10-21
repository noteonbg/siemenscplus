
/*




The Command Design Pattern is a behavioral design pattern that encapsulates a request as an object,
 allowing for the separation of sender and receiver. It’s particularly useful for parameterizing clients with 
 different requests, queuing requests, and supporting undoable operation

 Command Interface

 Concrete Commands:

Create concrete classes for specific HVAC commands. For example:

TurnOnACCommand: Implements HVACCommand and represents turning on the air conditioner.
TurnOffHeaterCommand: Implements HVACCommand and represents turning off the heater.
Other concrete commands for different HVAC actions.

Receiver
Define a HVACDevice class (the receiver) that knows how to perform the actual work 
(e.g., turn on/off the HVAC devices).

Invoker:
Create an invoker class called RemoteControl that holds references to different commands.
The invoker triggers the execution of commands.






*/

#if 1

#include <iostream>

// Receiver (HVAC device)
class HVACDevice {
public:
    void turnOn() {
        std::cout << "HVAC device turned ON." << std::endl;
    }

    void turnOff() {
        std::cout << "HVAC device turned OFF." << std::endl;
    }
};

// Command interface
class HVACCommand {
public:
    virtual void execute() = 0;
};

// Concrete command: Turn on AC
class TurnOnACCommand : public HVACCommand {
private:
    HVACDevice& device;

public:
    TurnOnACCommand(HVACDevice& dev) : device(dev) {}

    void execute() override {
        device.turnOn();
    }
};

// Concrete command: Turn off heater
class TurnOffHeaterCommand : public HVACCommand {
private:
    HVACDevice& device;

public:
    TurnOffHeaterCommand(HVACDevice& dev) : device(dev) {}

    void execute() override {
        device.turnOff();
    }
};

// Invoker (Remote control)
class RemoteControl {
private:
    HVACCommand* command;

public:
    void setCommand(HVACCommand* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    HVACDevice hvacDevice;
    TurnOnACCommand acOn(hvacDevice);
    TurnOffHeaterCommand heaterOff(hvacDevice);

    RemoteControl remote;
    remote.setCommand(&acOn);
    remote.pressButton(); // Turns on AC

    remote.setCommand(&heaterOff);
    remote.pressButton(); // Turns off heater

    return 0;
}


#endif