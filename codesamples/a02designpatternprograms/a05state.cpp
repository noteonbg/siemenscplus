/*

An HVAC system can be in various states such as heating, cooling, and idle. The behavior of the system changes based
 on its current state. For instance, in the heating state, it needs to turn on the heater, whereas in the cooling state, 
 it needs to turn on the air conditioner.
 Implementing this with conditional logic can lead to complex and hard-to-maintain code.

 We can use the State Pattern to encapsulate the state-specific behavior 
 and transition between states in a clean and maintainable way.

*/

#if 1

class HVACContext;  // Forward declaration

class HVACState {
public:
    virtual void handle(HVACContext* context) = 0;
    virtual ~HVACState() {}
};


#include <iostream>

class HeatingState : public HVACState {
public:
    void handle(HVACContext* context) override;
};

class CoolingState : public HVACState {
public:
    void handle(HVACContext* context) override;
};

class IdleState : public HVACState {
public:
    void handle(HVACContext* context) override;
};

void HeatingState::handle(HVACContext* context) {
    std::cout << "Heating State: Turning on the heater." << std::endl;
    // Implement heating logic here
    // Transition to the next state if needed
    // context->setState(new IdleState()); 
}

void CoolingState::handle(HVACContext* context) {
    std::cout << "Cooling State: Turning on the air conditioner." << std::endl;
    // Implement cooling logic here
    // Transition to the next state if needed
    // context->setState(new IdleState());
}

void IdleState::handle(HVACContext* context) {
    std::cout << "Idle State: System is idle." << std::endl;
    // Implement idle logic here
    // Transition to the next state if needed
    // context->setState(new HeatingState()); 
}


class HVACContext {
private:
    HVACState* currentState;
public:
    HVACContext() : currentState(new IdleState()) {}
    ~HVACContext() { delete currentState; }

    void setState(HVACState* state) {
        delete currentState;
        currentState = state;
    }

    void request() {
        currentState->handle(this);
    }
};



int main() {
    HVACContext hvac;

    // Transition to heating state
    hvac.setState(new HeatingState());
    hvac.request();

    // Transition to cooling state
    hvac.setState(new CoolingState());
    hvac.request();

    // Transition to idle state
    hvac.setState(new IdleState());
    hvac.request();

    return 0;
}

/*

State Interface: HVACState is an abstract base class defining the handle method.
Concrete States: HeatingState, CoolingState, and IdleState inherit from HVACState and implement the handle method.
Context: HVACContext manages the current state and transitions between states.
This C++ implementation follows the State Pattern, where each state-specific behavior is encapsulated in its own class,
 and the HVACContext class manages state transitions and delegates behavior to the current state object.
  This approach results in a more maintainable and scalable codebase, making it easier to add or modify states in
   the future.

*/

#endif 

