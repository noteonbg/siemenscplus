#if 0
#include <iostream>

template <typename T>
class Base {
public:
    Base(T value) : data(value) {
        std::cout  << "Base class constructor";

    }
    // Other member functions...
private:
    T data;
};

template <typename U>
class Derived : public Base<U> {
public:
    using Base<U>::Base;  // Inherit constructors from Base<U>
    // Other member functions specific to Derived...
};

int main() {
    Derived<int> d(42);  // Calls Base<int>'s constructor
    // Other usage of Derived...
    return 0;
}



#endif



#if 1

#include <iostream>

template <typename T>
class Base {
public:
    Base(T value) : data(value) {  std::cout  << "B\n "; }
    // Other member functions...
    void f1()  { std::cout << "\n f1 of B"; }
private:
    T data;
};

template <typename U>
class Derived : public Base<U> {
public:
    Derived(U value) : Base<U>(value) {  std::cout << "\n D"; }
    // Other member functions specific to Derived...
    void f2()  { std::cout << "\n f2 of B"; }
    void f3() {  
        this->f1();
        std::cout << "\n f3 of B"; 
      }
};

int main() {
    Derived<double> d(3.14);  // Calls Base<double>'s constructor
    // Other usage of Derived...
    d.f1();
    d.f2();
    d.f3();
    return 0;
}


#endif
