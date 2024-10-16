#include <iostream>
#include <type_traits>


//fold expressions  -- most of times aggregate operations..
#if 1
#include <iostream>

// use a unary left fold to check if all the arguments are true using the logical AND operator (&&):
template <typename... Args>
bool all(Args... args) {
    return (... && args); // Unary left fold with logical AND
}

int main() {
    bool result = all(true, true, true, true);
    std::cout << "Result: " << std::boolalpha << result << std::endl;
    return 0;
}

#endif

#if 1
// the sum of all arguments using a binary right fold with the addition operator (+):
#include <iostream>

template <typename... Args>
int sum(Args&&... args) {
    return (args + ...); // Binary right fold with addition
}

int main() {
    int result = sum(1, 2, 3, 4);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

/*
A fold expression has the following components:
A set of parentheses ( ).
An expression involving a parameter pack.
A binary operator that combines the elements of the parameter pack.
The instantiation of a fold expression expands the expression as follows:
If you have a parameter pack Args, the fold expression (Args + ...) would apply the + operator to
 all the elements in the pack.



*/


#endif











// Base case: function to end the recursion

/*

An ellipsis is used in two ways by variadic templates. 
To the left of the parameter name, it signifies a parameter 
pack, and to the right of the parameter name, 
it expands the parameter packs into separate names.

*/

#if 1

#include <iostream>

using namespace std;

template <typename T> void print(const T& t) {
    //what are you doing with t
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {

    static int count =1;
    std::cout <<   __PRETTY_FUNCTION__<<   std::endl; 
    cout << first <<  ""  <<   count  << "\n";
    count++;
    print(rest...); // recursive call using pack expansion syntax
}

int main()
{
    
    //print(1,2,3,4);
    print(1,"hello",3.3,true);
    
    
  }

#endif



#if 0
#include <iostream>

// Base case: function to end the recursion and return 0
template<typename T>
T sum(T value) {
    std::cout << "hey is function";
    return value;
}

// Recursive variadic function template
template<typename T, typename... Args>
T sum(T first, Args... args) {
    std::cout << __PRETTY_FUNCTION__ <<std::endl;    
    return first + sum(args...); // Recursively sum the arguments
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4.5) << std::endl; // Output: 10.5
    return 0;
}


/*

Base Case:

The sum function with a single argument returns that argument.
 This serves as the base case to end the recursion.
Recursive Function Template:

The sum function template takes at least one argument (first) and a parameter pack (args...).
It returns the sum of the first argument and the result of a recursive call to sum with the remaining arguments (args...).



*/


#endif


#if 0

#include <iostream>
// Base case: function to end the recursion and return the value
constexpr int sum() {
    return 0;
}

// Recursive variadic template function
template<typename T, typename... Args>
constexpr T sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    constexpr int result = sum(1, 2, 3, 4, 5);
    std::cout << "Sum: " << result << std::endl; // Output: Sum: 15

    // Compile-time assert to check the result
    static_assert(sum(1, 2, 3, 4, 5) == 15, "Sum is incorrect");

    return 0;
}

#endif


#if 0
#include <iostream>
#include <iostream>
#include <string>

// Base case: Function to end the recursion and handle no arguments
void log() {
    std::cout << std::endl;
}

// Variadic template function to handle multiple arguments
template<typename T, typename... Args>
void log(T first, Args... args) {
    std::cout << first << " ";
    log(args...); // Recursively call log with the remaining arguments
}

int main() {
    log("This", "is", "a", "test", "with", 5, "arguments.");
    return 0;
}

#endif


#if 0

//A variadic class template can be instantiated with any number of template arguments:

template<typename... Types>
struct Tuple {};

template<class... Types>
void f(Types... args)
{

}

 

int main()
{
 
Tuple<> t0;           // Types contains no arguments
Tuple<int> t1;        // Types contains one argument: int
Tuple<int, float> t2; // Types contains two arguments: int and float
//Tuple<0> t3;  // zero is not a type

f();       // OK: args contains no arguments
f(1);      // OK: args contains one argument: int
f(2, 1.0); // OK: args contains two arguments: int and double
std::cout << " syntax ok";

}

#endif



#if 0

#include <iostream>
#include <string>
#include <array>

// Variadic class template for a Tuple
template <typename... Inputs>
class Gate {
public:
    // Constructor: Initialize gate type and input count
    Gate(const std::string& type, Inputs... inputs)
        : gateType(type), inputValues{inputs...} {}

    // Method to compute the output of the gate
    bool computeOutput() {
        // Simplified logic for demonstration purposes (AND gate)
        for (bool input : inputValues) {
            if (!input) {
                return false;
            }
        }
        return true;
    }

private:
    std::string gateType; // Type of the gate (AND, OR, NOT, etc.)
    std::array<bool, sizeof...(Inputs)> inputValues; // Input values
};



int main() {
    // Example usage: Create an AND gate with 3 inputs
    Gate andGate("AND", true, true, true);
    bool result = andGate.computeOutput();
    std::cout << "AND gate output: " << std::boolalpha << result << std::endl;

    // Create an OR gate with 4 inputs
    Gate orGate("OR", false, true, true, false);
    result = orGate.computeOutput();
    std::cout << "OR gate output: " << result << std::endl;

    // Add more gate instances and test cases as needed

    return 0;
}


#endif

#if 0
#include <format> 
#include <iostream>

template <typename... Items>
auto unaryLeftAdd(Items... items) {
   return (... + items); // unary left fold
}

template <typename... Items>
auto unaryRightAdd(Items... items) {
   return (items + ...); // unary right fold
}

template <typename... Items>
auto unaryLeftSubtract(Items... items) {
   return (... - items); // unary left fold
}

template <typename... Items>
auto unaryRightSubtract(Items... items) {
   return (items - ...); // unary right fold
}

int main() {
   std::cout <<  unaryLeftAdd(1, 2, 3, 4);
         "unaryRightAdd(1, 2, 3, 4): ", unaryRightAdd(1, 2, 3, 4));

   std::cout << "Unary left and right fold with subtraction:"
      << std::format("\n{}{}\n{}{}\n",
         "unaryLeftSubtract(1, 2, 3, 4): ",
         unaryLeftSubtract(1, 2, 3, 4),
         "unaryRightSubtract(1, 2, 3, 4): ",
         unaryRightSubtract(1, 2, 3, 4));
}

#endif
