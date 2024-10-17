#if 1


#include <iostream>

// Outer class (enclosing class)
class Outer {
public:
    // Public member function of the outer class
    void outerFunction() {
        std::cout << "Outer class function called.\n";
    }

    // Nested class (inner class)
    class Inner {
    public:
        void innerFunction() {
            std::cout << "Inner class function called.\n";
        }
    };
};

int main() {
    // Create an instance of the outer class
    Outer outerObj;

    // Call the outer class function
    outerObj.outerFunction();

    // Create an instance of the nested class
    Outer::Inner innerObj;

    // Call the inner class function
    innerObj.innerFunction();

    

    // DO: Use nested classes for encapsulation and information hiding
    // - Inner class members can be private, providing better encapsulation.
    // - Hide implementation details from external users.
    // - Example: hiding Node implementation in a linked list.

    // DON'T: Expose nested class members unnecessarily
    // - Avoid exposing inner class members in the outer class's public interface.
    // - Only expose what's necessary for the outer class's functionality.

    // DO: Use nested classes for related utility classes
    // - If a class is closely related to another class, consider nesting it.
    // - Example: iterators inside container classes.

    
    // DO: Understand access rights
    // - Nested classes have the same access rights as other members.
    // - Access rules apply (public, private, protected).

    
    return 0;
}


#endif