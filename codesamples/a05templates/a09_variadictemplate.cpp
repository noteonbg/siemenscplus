#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <cmath>


#if 1

// Base case: Empty Circuit
template<typename... Components>
class Circuit;

// Specialization for a non-empty Circuit
template<typename Head, typename... Tail>
class Circuit<Head, Tail...> {
    Head component;
    Circuit<Tail...> next;

public:
    Circuit(Head c, Tail... t) : component(c), next(t...) {}

    Head getComponent() const {
        return component;
    }

    const Circuit<Tail...>& getNext() const {
        return next;
    }
};


//The Circuit class template is defined to handle an 
//arbitrary number of component types.
// Specialization for an empty Circuit
template<>
class Circuit<> {
};

// Helper function to create a Circuit
template<typename... Args>
Circuit<Args...> makeCircuit(Args... args) {
    return Circuit<Args...>(args...);
}

int main() {
    auto myCircuit = makeCircuit("Resistor 10", "Capacitor 100", "Inductor 1mH");

    std::cout << "First component: " << myCircuit.getComponent() << std::endl;  // Output: Resistor 10kΩ
    std::cout << "Second component: " << myCircuit.getNext().getComponent() << std::endl;  // Output: Capacitor 100μF
    std::cout << "Third component: " << myCircuit.getNext().getNext().getComponent() << std::endl;  // Output: Inductor 1mH

    return 0;
}

#endif


#if 1




// Complex number type to represent impedance
using Complex = std::complex<double>;

// Base class for electronic components
class Component {
public:
    virtual Complex getImpedance(double frequency) const = 0;
    virtual std::string getName() const = 0;
};

// Resistor class
class Resistor : public Component {
    double resistance; // in ohms
public:
    Resistor(double r) : resistance(r) {}

    Complex getImpedance(double) const override {
        return Complex(resistance, 0);
    }

    std::string getName() const override {
        return "Resistor";
    }
};

// Capacitor class
class Capacitor : public Component {
    double capacitance; // in farads
public:
    Capacitor(double c) : capacitance(c) {}

    Complex getImpedance(double frequency) const override {
        return Complex(0, -1 / (2 * M_PI * frequency * capacitance));
    }

    std::string getName() const override {
        return "Capacitor";
    }
};

// Inductor class
class Inductor : public Component {
    double inductance; // in henrys
public:
    Inductor(double l) : inductance(l) {}

    Complex getImpedance(double frequency) const override {
        return Complex(0, 2 * M_PI * frequency * inductance);
    }

    std::string getName() const override {
        return "Inductor";
    }
};

// Base case: Function to calculate total impedance (zero components)
constexpr Complex calculateTotalImpedance(double) {
    return Complex(0, 0);
}

// Variadic template function to calculate total impedance
template<typename First, typename... Rest>
Complex calculateTotalImpedance(double frequency, First first, Rest... rest) {
    return first.getImpedance(frequency) + calculateTotalImpedance(frequency, rest...);
}

int main() {
    Resistor r1(100); // 100 ohm resistor
    Capacitor c1(1e-6); // 1 microfarad capacitor
    Inductor l1(1e-3); // 1 millihenry inductor

    double frequency = 1000; // 1 kHz

    Complex totalImpedance = calculateTotalImpedance(frequency, r1, c1, l1);

    std::cout << "Total impedance at " << frequency << " Hz: " << totalImpedance << " ohms" << std::endl;

    return 0;
}


#endif