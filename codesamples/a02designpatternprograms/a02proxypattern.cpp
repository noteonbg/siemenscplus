/*

 Proxy Design Pattern in HVAC Context
The Proxy Design Pattern provides a surrogate or placeholder for another object to control access to it.
 In the context of an HVAC system, we can use the Proxy pattern to control access to a complex or 
 resource-intensive object, such as an HVAC controller that interfaces with physical hardware.

We have an HVACController that performs operations such as turning on the heater or cooler,
 which involves communication with hardware.
  This can be resource-intensive. 
  
We use a HVACProxy to control access to the HVACController and add additional 
functionalities such as logging and access control.

*/

#if 1

#include <iostream>


//HVACController: The real object that the proxy will represent.
class HVACController {
public:
    void turnOnHeater() {
        std::cout << "Heater is now ON." << std::endl;
    }

    void turnOnCooler() {
        std::cout << "Cooler is now ON." << std::endl;
    }

    void turnOff() {
        std::cout << "HVAC system is now OFF." << std::endl;
    }
};



//HVACProxy: The proxy class that controls access to HVACController.

class HVACProxy {
private:
    HVACController* controller;
    bool accessGranted;

    bool checkAccess() {
        // Simple access control check (e.g., based on user credentials)
        return accessGranted;
    }

public:
    HVACProxy() : controller(new HVACController()), accessGranted(false) {}

    ~HVACProxy() {
        delete controller;
    }

    void grantAccess() {
        accessGranted = true;
        std::cout << "Access granted to HVAC controller." << std::endl;
    }

    void revokeAccess() {
        accessGranted = false;
        std::cout << "Access revoked from HVAC controller." << std::endl;
    }

    void turnOnHeater() {
        if (checkAccess()) {
            std::cout << "Proxy: Turning on heater." << std::endl;
            controller->turnOnHeater();
        } else {
            std::cout << "Proxy: Access denied. Cannot turn on heater." << std::endl;
        }
    }

    void turnOnCooler() {
        if (checkAccess()) {
            std::cout << "Proxy: Turning on cooler." << std::endl;
            controller->turnOnCooler();
        } else {
            std::cout << "Proxy: Access denied. Cannot turn on cooler." << std::endl;
        }
    }

    void turnOff() {
        if (checkAccess()) {
            std::cout << "Proxy: Turning off HVAC system." << std::endl;
            controller->turnOff();
        } else {
            std::cout << "Proxy: Access denied. Cannot turn off HVAC system." << std::endl;
        }
    }
};


int main() {
    HVACProxy hvacProxy;

    // Try to operate without access
    hvacProxy.turnOnHeater();
    hvacProxy.turnOnCooler();
    hvacProxy.turnOff();

    // Grant access and operate
    hvacProxy.grantAccess();
    hvacProxy.turnOnHeater();
    hvacProxy.turnOnCooler();
    hvacProxy.turnOff();

    // Revoke access and try to operate again
    hvacProxy.revokeAccess();
    hvacProxy.turnOnHeater();
    hvacProxy.turnOnCooler();
    hvacProxy.turnOff();

    return 0;
}

#endif


/*

Client -> HVACProxy: turnOnHeater()
HVACProxy -> HVACProxy: checkAccess()
alt [access granted]
    HVACProxy -> HVACController: turnOnHeater()
    HVACController -> HVACProxy: return
else [access denied]
    HVACProxy -> Client: Access Denied
end


Plant UML syntax.
@startuml
actor Client

Client -> HVACProxy: turnOnHeater()
activate HVACProxy

HVACProxy -> HVACProxy: checkAccess()
alt Access Granted
    HVACProxy -> HVACController: turnOnHeater()
    activate HVACController
    HVACController --> HVACProxy: return
    deactivate HVACController
else Access Denied
    HVACProxy --> Client: Access Denied
end
deactivate HVACProxy

@enduml













*/