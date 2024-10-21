#if 1

#include <iostream>

int main() {
  int i = 42;

  // decltype(i) is the type of i, which is int
  auto j = i * 2;

  // decltype((i)) is the type of the expression (i), which is int
  //decltype((i)) k = i *3;
  //here in the above line it is rvalue, you cannot assign to it.
  

  // decltype(&i) is the type of the pointer to i, which is int*
  decltype(&i) l = &i;

  // decltype(i++) is the type of the expression i++, which is int
  decltype(i++) m = i;

  //std::cout << j << " " << k << " " << *l << " " << m << std::endl;
  std::cout << m << (*l) << j << "\n";

  return 0;
}

#endif

#if 1


#include <iostream>
#include <utility> // for std::declval

// Function template to multiply two values
template <class A, class B>
void MultiplyAB(A a, B b, decltype(a*b)& output) {
    output = a * b;
}


int main() {
    int intVal = 5;
    double doubleVal = 3.14;
    float floatVal = 2.5;

    decltype(intVal * doubleVal) result1; // Deduces the type of intVal * doubleVal
    decltype(floatVal * doubleVal) result2; // Deduces the type of floatVal * doubleVal

    MultiplyAB(intVal, doubleVal, result1);
    MultiplyAB(floatVal, doubleVal, result2);

    std::cout << "Result 1: " << result1 << std::endl; // Should be 15.7
    std::cout << "Result 2: " << result2 << std::endl; // Should be 7.85

    return 0;
}




#endif

#if 0

// C++ program to demonstrate use of decltype in functions
#include <iostream>
using namespace std;

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
	return (a < b) ? a : b;
}

// driver function to test various inference
int main()
{


    auto x = findMin(4,3.3);
    

	// This call returns 3.44 of double type
	cout << findMin(4, 3.44) << endl;

	// This call returns 3 of double type
	cout << findMin(5.4, 3) << endl;

	return 0;
}



#endif

#if 0


// decltype_1.cpp


#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) ->
   decltype(forward<T1>(t1) + forward<T2>(t2))
{
   return forward<T1>(t1) + forward<T2>(t2);
}

class X
{
   friend X operator+(const X& x1, const X& x2)
   {
      return X(x1.m_data + x2.m_data);
   }

public:
   X(int data) : m_data(data) {}
   int Dump() const { return m_data;}
private:
   int m_data;
};

int main()
{
   // Integer
   int i = 4;
   cout <<
      "Plus(i, 9) = " <<
      Plus(i, 9) << endl;

   // Floating point
   float dx = 4.0;
   float dy = 9.5;
   cout <<
      setprecision(3) <<
      "Plus(dx, dy) = " <<
      Plus(dx, dy) << endl;

   // String
   string hello = "Hello, ";
   string world = "world!";
   cout << Plus(hello, world) << endl;

   // Custom type
   X x1(20);
   X x2(22);
   X x3 = Plus(x1, x2);
   cout <<
      "x3.Dump() = " <<
      x3.Dump() << endl;
}

#endif

#if 0

#include <iostream>


/*
Suppose we want to create a template function that calculates 
the product of two values and returns the result.
 However, the return type should depend on the types of the arguments. 
 We'll use decltype to deduce the return type.


 decltype is used in templates to deduce types at compile time.
In the example, decltype is used in the return type of the product function to deduce the return type based on the types of its arguments.
This allows the function to work with various types while
 ensuring that the correct type is returned based on
  the types of the arguments provided.

*/
// Template function to calculate the product of two values
template<typename T, typename U>

auto product(T x, U y) ->decltype(x * y)  {
    return x * y;
}

int main() {
    int result1 = product(5, 3); // Deduced type: int
    double result2 = product(2.5, 4); // Deduced type: double

    std::cout << "Result 1: " << result1 << std::endl; // Output: 15
    std::cout << "Result 2: " << result2 << std::endl; // Output: 10.0

    return 0;
}


#endif

#if 0
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <cmath>

// Complex number type to represent impedance
using Complex = std::complex<double>;

// Base class for electronic components
class Component {
public:
    virtual Complex getImpedance(double frequency) const = 0;
    virtual std::string getName() const = 0;
    virtual ~Component() = default;
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

// Template class for a series circuit
template<typename... Components>
class SeriesCircuit {
    std::vector<Component*> components;
public:
    SeriesCircuit(Components&... comps) : components{&comps...} {}

    auto getTotalImpedance(double frequency) const {
        Complex totalImpedance(0, 0);
        for (const auto& comp : components) {
            totalImpedance += comp->getImpedance(frequency);
        }
        return totalImpedance;
    }
};

int main() {
    Resistor r1(100); // 100 ohm resistor
    Capacitor c1(1e-6); // 1 microfarad capacitor // the value assigned to x is (1 \times 10^{-6
    Inductor l1(1e-3); // 1 millihenry inductor //value assingned to l1 is 1 times 10^-3

    double frequency = 1000; // 1 kHz

    // Create a series circuit with the components
    SeriesCircuit<Resistor, Capacitor, Inductor> circuit(r1, c1, l1);

    // Calculate and print the total impedance
    auto totalImpedance = circuit.getTotalImpedance(frequency);
    std::cout << "Total impedance at " << frequency << " Hz: " << totalImpedance << " ohms" << std::endl;

    return 0;
}

/*

decltype in C++ is used to deduce the type of an expression
 at compile time. It's particularly useful in templates where
  the type may depend on the template parameters or 
  expressions within the template. 
  Let's see how decltype can be used in templates with an
   example in the electronic domain.



Using decltype in getTotalImpedance:

In the SeriesCircuit class template, the getTotalImpedance method uses auto as the return type.
The return type is deduced using decltype. Since the getImpedance function may return different types depending on the component, decltype deduces the common type of all expressions in the for loop.
Template Class Instantiation:

In main, we instantiate a SeriesCircuit with Resistor, Capacitor, and Inductor components.
The constructor of SeriesCircuit takes references to the components and stores pointers to them in a vector.
Calculating Total Impedance:

We call the getTotalImpedance method of the SeriesCircuit instance with a frequency and print the total impedance.
Summary
decltype is useful in templates when the type of an expression depends on template parameters or expressions within the template.
It can be used to deduce the return type of functions, variables, or expressions at compile time.
In the provided example, decltype is used to deduce the return type of getTotalImpedance, which depends on the types returned by getImpedance for each component in the series circuit.

*/


#endif

