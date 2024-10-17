#if 1

#include <iostream>
#include <functional> // for std::invoke

// Example function
int add(int a, int b) {
    return a + b;
}

// Example class with a member function
class Calculator {
public:
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    // Example 1: Invoke a free function
    int result1 = std::invoke(add, 3, 4);
    //int result1 =add(3,4);
    std::cout << "Result from add: " << result1 << "\n";

    // Example 2: Invoke a lambda
    auto lambda = [](auto x, auto y) { return x - y; };
    int result2 = std::invoke(lambda, 10, 5);
    std::cout << "Result from lambda: " << result2 << "\n";

    // Example 3: Invoke a member function
    Calculator calc;
    int result3 = std::invoke(&Calculator::multiply, calc, 6, 7);
    std::cout << "Result from member function: " << result3 << "\n";

    return 0;
}

//

#endif

#if 1

#include <iostream>
#include <functional>

// Example simulation engines
struct SPICE {
    void simulate(const std::string& netlist) {
        std::cout << "Running SPICE simulation for netlist: " << netlist << "\n";
        // Simulate SPICE circuit
    }
};

struct Verilog {
    void simulate(const std::string& design) {
        std::cout << "Running Verilog simulation for design: " << design << "\n";
        // Simulate Verilog design
    }
};

int main() {
    // User input (can be SPICE or Verilog)
    std::string userChoice = "SPICE"; // Change to "Verilog" for Verilog simulation

    // Create simulation engine objects
    SPICE spiceEngine;
    Verilog verilogEngine;

    // Invoke the appropriate simulation engine based on user choice
    if (userChoice == "SPICE") {
        std::invoke(&SPICE::simulate, spiceEngine, "my_circuit.spice");
    } else if (userChoice == "Verilog") {
        std::invoke(&Verilog::simulate, verilogEngine, "my_design.v");
    } else {
        std::cout << "Invalid choice. Please select SPICE or Verilog.\n";
    }

    return 0;
}


#endif

#if 0
#include <iostream>
#include <functional>

struct Functor {
    void operator()(int x) {
        std::cout << "Functor called with " << x << std::endl;
    }
};

int main() {
    Functor f;
    std::invoke(f, 10);                     // Calls Functor::operator()
    std::invoke([](int x) { std::cout << x; }, 20); // Calls a lambda
    std::invoke(&MyClass::memberFunction, obj, 30); // Calls member function

    return 0;
}


struct MyClass {
    void memberFunction(int x) {
        std::cout << "Member function called with " << x << std::endl;
    }
};

MyClass obj;
std::invoke(&MyClass::memberFunction, obj, 42);  // Calls obj.memberFunction(42);




#endif