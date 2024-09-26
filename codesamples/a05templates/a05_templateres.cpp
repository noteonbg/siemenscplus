#include <iostream>
#include <type_traits>



//program 1 demonstrating basic type trait syntax.
#if 0

#include <iostream>
#include <type_traits>

//type trait syntax..

class Class {};

int main() {
    std::cout << std::is_floating_point<Class>::value << '\n'; // Outputs 0
    std::cout << std::is_floating_point<float>::value << '\n'; // Outputs 1
    std::cout << std::is_floating_point<int>::value << '\n';   // Outputs 0

    //std::is_integral_v<T> is a convenient alias for std::is_integral<T>::value.

std::cout << std::is_integral_v<int> << '\n';        // Outputs 1 (true)
std::cout << std::is_integral_v<float> << '\n';      // Outputs 0 (false)
std::cout << std::is_integral_v<char> << '\n';       // Outputs 1 (true)
std::cout << std::is_integral_v<std::string> << '\n'; // Outputs 0 (false)

}


#endif


#if 1
// Function template with SFINAE to restrict to integral types

//typename std::enable_if<std::is_integral<T>::value, int>::type
template<typename T>
int printValue(T value) {
    std::cout << "\n The value is: " << value << std::endl;

    //logic 1
    return 3;
}



template<>
int printValue(char c,int d)
{
    //lgoci 2
    return 4;
}


/*
template<typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
printValue(T value) {
    //static_assert(std::is_integral_v<T>::value, "The value must be an integral type");
    std::cout << "\n data type given is not an int type.";
}
*/




/*

typename std::enable_if<!std::is_integral<T>::value, void>::type: 
This is a type trait-based condition. 
It uses std::enable_if to conditionally enable or disable the function based on whether
 T is an integral type (e.g., int, long, etc.). 
 If T is not integral, the function will be enabled and return void. 
 Otherwise, it won’t be instantiated.



*/



// Overload to handle non-integral types and give a compile-time error








int main() {
    std::cout << printValue(44);
   printValue("hello");      // OK, 42 is an integral type
    printValue(3.14); // Compile-time error, 3.14 is not an integral type
    return 0;
}


//look at  https://en.cppreference.com/w/cpp/header/type_traits

#endif

#if 0

#include <iostream>
#include <type_traits>

struct A {
    A(int, int) {}; // Constructor with two int arguments
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "is_constructible:" << std::endl;
    std::cout << "int: " << std::is_constructible<int>::value << std::endl;
    std::cout << "int(float): " << std::is_constructible<int, float>::value << std::endl;
    std::cout << "int(float, float): " << std::is_constructible<int, float, float>::value << std::endl;
    std::cout << "A: " << std::is_constructible<A>::value << std::endl;
    std::cout << "A(int): " << std::is_constructible<A, int>::value << std::endl;
    std::cout << "A(int, int): " << std::is_constructible<A, int, int>::value << std::endl;
    std::cout << "A(int, int, int): " << std::is_constructible<A, int, int, int>::value << std::endl;
    return 0;
}


#endif
