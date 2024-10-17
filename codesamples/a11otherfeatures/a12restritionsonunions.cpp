#if 1

/*

A union is a special class type that can hold only
 one of its non-static data members at a time.

 Limitations on unions

 No Virtual Functions:
A union cannot have virtual functions.
Unlike classes or structs, unions do not support polymorphism through virtual functions.

No Base Classes:
A union cannot have base classes, and it cannot be used as a base class for other classes.

No Non-Static Data Members of Reference Types:
Unions cannot contain non-static data members of reference types.

No Non-Trivial Special Member Functions:
A union cannot have non-static data members with non-trivial special member functions.
These special member functions include the copy constructor, copy-assignment operator, and destructor.



*/

#include <iostream>

union MyUnion {
    int i;
    double d;
};

int main() {
    MyUnion u;
    u.i = 42;
    std::cout << "Value of i: " << u.i << std::endl;
    u.d = 3.14;
    std::cout << "Value of d: " << u.d << std::endl;
    return 0;
}


#endif