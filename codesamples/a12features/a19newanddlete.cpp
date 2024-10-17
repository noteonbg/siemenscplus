#if 1

#include <iostream>

struct MyArray {
    MyArray() { std::cout << "Array Constructed at " << this << '\n'; }
    ~MyArray() { std::cout << "Array Destructed at " << this << '\n'; }
};

int main() {
    // Elided new-expression for an array (guaranteed copy elision)
    auto arr = MyArray3;

    // arr goes out of scope, destructors called automatically for each element

    return 0;
}



#endif


#if 0

#include <iostream>

struct MyObject {
    MyObject() { std::cout << "Constructed at " << this << '\n'; }
    ~MyObject() { std::cout << "Destructed at " << this << '\n'; }
};

int main() {
    // Elided new-expression (guaranteed copy elision)
    auto obj = MyObject();

    // obj goes out of scope, destructor called automatically

    return 0;
}



#endif