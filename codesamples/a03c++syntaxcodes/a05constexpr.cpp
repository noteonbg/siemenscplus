
#include <iostream>
#include <chrono>
#include <thread>

/*

The keyword constexpr was introduced in C++11 and improved in C++14.
 it means const expression Like const, it can be applied
  to variables:

constexpr can also be applied to functions and class
 constructors.
constexpr indicates that the value, or return value,
 is constant and,
where possible, is computed at compile time.


*/



#if 1

 
constexpr int square(int x) {
    for(int i=0; i<262144; i++);
    return x * x;
}



int main() {
    {

    auto start = std::chrono::high_resolution_clock::now();    
    
    constexpr int value = 5;
    constexpr
     int result = square(value); // Evaluated at compile time
     static_assert(result ==25);
    auto end = std::chrono::high_resolution_clock::now();
    
    int freak =4;
    int result1 = square(freak);


    // Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\n " << duration.count() << "milli seconds taken";
    }
  
    #if 0
    static_assert(result==25);
    std::cout << "Square of " << value << " is " << result << std::endl;

    #endif
    
    return 0;
}


#endif

#if 0


#include <iostream>

constexpr int arraySize(int size) {
    return size * 2;
}

int main() {
    constexpr int size = 5;
    int arr[arraySize(size)]; // Array size determined at compile time
    std::cout << "Array size: " << sizeof(arr) / sizeof(arr[0]) << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>

class Circle {
public:
    constexpr Circle(double r) : radius(r) {}

    constexpr double getArea() const {
        return pi * radius * radius;
    }

private:
    static constexpr double pi = 3.14159265358979323846;
    double radius;
};

int main() {
    constexpr Circle c(5.0); // Compile-time instantiation of Circle object
    constexpr double area = c.getArea();
    std::cout << "Area of circle with radius " << c.getRadius() << " is " << area << std::endl;

    return 0;
}


#endif