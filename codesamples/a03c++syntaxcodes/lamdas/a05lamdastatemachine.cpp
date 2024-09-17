#include <iostream>
#include <functional>

#if 1

enum class State {
    Idle,
    Processing,
    Completed
};

int main() {
    State currentState = State::Idle;

    // Define state transition lambdas
    auto startProcessing = [&currentState]() {
        std::cout << "Starting processing..." << std::endl;
        currentState = State::Processing;
    };

    auto finishProcessing = [&currentState]() {
        std::cout << "Processing completed." << std::endl;
        currentState = State::Completed;
    };

    // State machine simulation
    startProcessing();
    finishProcessing();

    return 0;
}

#endif