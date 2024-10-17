#if 1

#include <iostream>

void printMessage(const char* msg) {
    if (msg != nullptr) {
        std::cout << msg << std::endl;
    } else {
        std::cout << "Message is nullptr." << std::endl;
    }
}

int main() {
    const char* message = "Hello, world!";
    printMessage(message);
    printMessage(nullptr);
    return 0;
}

/*

Unlike NULL, which is typically defined as (void*)0,
 nullptr is of type std::nullptr_t
 It is implicitly convertible and comparable to any pointer type or pointer-to-member type.
 However, it is not implicitly convertible or comparable to integral types (except for bool)1.
It avoids ambiguity when overloaded functions accept both pointer and non-pointer arguments.

Dereferencing a NULL pointer causes undefined behavior (e.g., segmentation faults).
Using nullptr helps prevent such issues by providing a well-defined null pointer value.

nullptr consistently favors the pointer version of overloaded functions.
It never accidentally calls the integer version, unlike NULL.

*/


#endif