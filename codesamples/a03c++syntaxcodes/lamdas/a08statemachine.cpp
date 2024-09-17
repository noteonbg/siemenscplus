#include <iostream>
#include <functional>
#include <unordered_map>

enum class State {
    Idle,
    Processing,
    Completed
};

class StateMachine {
public:
    StateMachine() : currentState(State::Idle) {}

    void setStateTransition(State currentState, State nextState, std::function<void()> transitionFunction) {
        transitions[currentState] = {nextState, transitionFunction};
    }

    void triggerEvent() {
        auto it = transitions.find(currentState);
        if (it != transitions.end()) {
            State nextState = it->second.first;
            std::function<void()> transitionFunction = it->second.second;
            transitionFunction(); // Execute transition function
            currentState = nextState;
        } else {
            std::cout << "No transition defined for the current state." << std::endl;
        }
    }

    State getCurrentState() const {
        return currentState;
    }

private:
    State currentState;
    std::unordered_map<State, std::pair<State, std::function<void()>>> transitions;
};

int main() {
    StateMachine fsm;

    // Define state transitions and transition functions
    fsm.setStateTransition(State::Idle, State::Processing, []() {
        std::cout << "Transitioning from Idle to Processing." << std::endl;
    });

    fsm.setStateTransition(State::Processing, State::Completed, []() {
        std::cout << "Transitioning from Processing to Completed." << std::endl;
    });

    // Trigger events to test the state machine
    fsm.triggerEvent(); // Should transition from Idle to Processing
    fsm.triggerEvent(); // Should transition from Processing to Completed

    return 0;
}

/*

State is an enumeration representing the possible states of the finite state machine.
StateMachine is a class representing the finite state machine.
setStateTransition method allows setting transitions between states along with the transition functions.
triggerEvent method triggers an event, which executes the transition function associated with the current state and transitions to the next state.
main function demonstrates how to use the StateMachine class by defining state transitions and triggering events.

*/
