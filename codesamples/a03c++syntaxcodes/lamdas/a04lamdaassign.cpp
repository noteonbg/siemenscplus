

#if 0

#include <vector>
#include <algorithm>

struct Component {
    std::string name;
    // Other component properties...
};

int main() {
    std::vector<Component> components;
    // Populate components vector...

    // Filter components based on a condition using a lambda expression
    auto filtered_components = std::remove_if(components.begin(), components.end(),
        [](const Component& comp) {
            return comp.name == "unwanted";
        });

    // Erase the removed components from the vector
    components.erase(filtered_components, components.end());

    // Now components vector contains only desired components
    return 0;
}


#endif

#if 0

#include <vector>
#include <algorithm>

struct Component {
    std::string name;
    double delay;
    // Other component properties...
};


//sorting criteria being mentioned at runtime.

int main() {
    std::vector<Component> components;
    // Populate components vector...

    // Sort components based on delay using a custom comparator lambda
    std::sort(components.begin(), components.end(),
        [](const Component& comp1, const Component& comp2) {
            return comp1.delay < comp2.delay;
        });

    // Now components vector is sorted based on delay
    return 0;
}


#endif

#if 0
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Use lambda with std::accumulate to calculate the sum of squares
    auto sum_of_squares = std::accumulate(data.begin(), data.end(), 0,
        [](int total, int value) {
            return total + value * value;
        });

    std::cout << "Sum of squares: " << sum_of_squares << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>
#include <functional>

void simulate(std::function<void()> on_simulation_start, std::function<void()> on_simulation_end) {
    // Simulate the circuit
    on_simulation_start();

    // Perform simulation...

    // Simulation completed
    on_simulation_end();
}

int main() {
    // Define lambda functions for simulation events
    auto on_start = []() {
        std::cout << "Simulation started." << std::endl;
    };

    auto on_end = []() {
        std::cout << "Simulation ended." << std::endl;
    };

    // Run simulation with custom callbacks
    simulate(on_start, on_end);

    return 0;
}


#endif