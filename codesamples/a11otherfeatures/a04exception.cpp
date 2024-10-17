#include <exception>
#include <stdexcept>


#if 1

// noexcept specification indicates that a function does not throw any exceptions.
void myFunction(int i) noexcept {
    // Function code (no exceptions thrown)
}

void myOldFunction(int i) throw(); // Equivalent to noexcept(true) old style deprecated
{

}

void myThrowingFunction() throw (std::runtime_error)
 {
}

int main()
{

    return 0;

}

//to indicate the function can throw exceptions.
void myOtherFunction() noexcept(false) {
    // Function code (may throw exceptions)
}



    // Function code (may


#endif