

/*
In C++, decltype is a keyword used to determine the type of an expression at
 compile-time. On the other hand, 
 declval is a utility function provided by the <utility> header
  that allows you to obtain a reference to an object of a
   given type without the need to create an
    instance of that type.
    
     It is commonly used in contexts where you need to
      specify a type, such as when dealing 
      with decltype expressions in decltype specifier.

*/

#if 0

/*
decl type

Converts any type T to a reference type, making it possible to use member 
functions in the operand of the decltype specifier without 
the need to go through constructors.

std::declval is commonly used in templates where acceptable template parameters may
 have no constructor in common, but have the same member function
 whose return type is needed.

*/
#include <iostream>
#include <utility>
 
struct Default
{
    int foo() const { return 1; }
};
 
struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};
 
int main()
{
    //remember all these things are related to compile time only and not runtime.


    //here decl tpe is working becuase default constructor is there
    decltype(Default().foo()) n1 = 23;                   // type of n1 is int
//  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}

#endif

#if 1

#include <iostream>
#include <utility>

struct A {
    virtual int value() = 0;
};

class B : public A {
    int val_;
public:
    B(int i, int j) : val_(i * j) {}
    int value() { return val_; }
};

int main() {
    // Using decltype with std::declval

    //observe we are creating a refernce and calling a function and storing the return type of the function
    //in the variable..
    decltype(std::declval<A>().value()) a; // Declares a variable of the return type of A::value()
    decltype(std::declval<B>().value()) b; // Declares a variable of the return type of B::value()

    // Note: We don't need to create actual instances of A or B!

    std::cout << "Type of 'a': " << typeid(a).name() << std::endl;
    std::cout << "Type of 'b': " << typeid(b).name() << std::endl;

    return 0;
}


#endif

#if 0

//decltype is used in templates to deduce types at compile time.

#include <iostream>
#include <type_traits>

// Example input signal type (you can replace this with your actual signal type)
struct InputSignal {

    InputSignal()=default;
    InputSignal(const int volt):voltage(volt){}
    InputSignal f1() { return InputSignal(); }

    double voltage;
};

// Simulate a logic gate
template <typename InputType>
bool SimulateLogicGate(const InputType& input) {
    // Perform some logic gate simulation (e.g., AND, OR, etc.)
    // For demonstration purposes, let's just check if the voltage is above a threshold
    return input.voltage > 2.5;
}

int main() {
    // Use std::declval to create a reference to InputSignal without constructing an instance
     using InputRef = decltype(std::declval<InputSignal>()>);

    // Simulate an input signal (pretend we received this from a sensor)
    InputRef input;
    input.voltage = 3.0;

    // Simulate an AND gate using the input signal
    bool result = SimulateLogicGate(input);

    std::cout << "Input voltage: " << input.voltage << std::endl;
    std::cout << "AND gate output: " << (result ? "High" : "Low") << std::endl;

    return 0;
}


#endif

#if 0

#include <utility>
template <class T, class ReturnT, class... ArgsT> class IsCallable
{
public:
   struct BadType {};
   template <class U>
   static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>
   template <class U>
   static BadType Test(...);
   static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

int main()
{

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");
return 0;

}

#endif

#if 0

#include <iostream>
#include <utility>

// Example: A simple struct representing a sensor reading
struct SensorReading {
    double value;
};

// A function that simulates processing sensor data
template <typename T>
void ProcessSensorData(const T& data) {
    // Perform some processing (for demonstration, let's just print the value)
    std::cout << "Processing sensor data: " << data.value << std::endl;
}

int main() {
    // Use std::declval to create a reference to SensorReading without constructing an instance
    using SensorRef = decltype(std::declval<SensorReading>());

    // Create a reference to SensorReading (without actually creating an object)
    SensorRef sensorDataRef;

    // Simulate sensor data (pretend we received this from a sensor)
    sensorDataRef.value = 42.5;

    // Process the sensor data
    ProcessSensorData(sensorDataRef);

    return 0;
}


#endif