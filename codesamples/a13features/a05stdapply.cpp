#if 0

/*	std::apply

std::apply is a C++ standard library function introduced in C++17.
 It allows you to invoke a callable object (such as a function or a lambda)
  with the elements of a tuple as arguments.

*/

#include <iostream>
#include <tuple>

int sum(int a, int b, int c) {
    return a + b + c;
}

void print(std::string_view a, std::string_view b) {
    std::cout << "(" << a << ", " << b << ")\n";
}

int main() {
    std::tuple numbers{1, 2, 3};
    std::cout << std::apply(sum, numbers) << '\n';

    std::tuple strs{"Hello", "World"};
    std::apply(print, strs);
}

#endif

#if 0

#include <iostream>
#include <tuple>

// Simulate the delay of a 2-input AND gate
double and_gate_delay(bool input1, bool input2) {
    // Some logic to compute the delay
    return 0.5; // Placeholder value
}

int main() {
    // Create a tuple of input vectors (test cases)
    std::tuple<std::tuple<bool, bool>, std::tuple<bool, bool>> input_vectors{
        {true, true}, {false, true}
    };

    // Apply the and_gate_delay function to each input vector
    std::apply( {
        std::cout << "Delay for inputs: ";
        ((std::cout << inputs << ' '), ...); // Print input values
        std::cout << "is " << and_gate_delay(inputs...) << " ns\n";
    }, input_vectors);
}

/*

We define an and_gate_delay function that takes two boolean inputs and returns the delay.
We create a tuple input_vectors containing two input vectors (each represented by a tuple of booleans).
Using std::apply, we invoke the lambda function that applies and_gate_delay to each input vector. 
The inputs... syntax expands the tuple elements as separate arguments to the function.

*/

#endif