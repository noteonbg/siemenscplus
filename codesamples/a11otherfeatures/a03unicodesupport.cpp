

// C++14
#include <iostream>





#if 1

#include <iostream>

// User-defined literal operator for meters
constexpr long double operator"" _m(long double value) {
    return value; // Simply return the value (interpreted as meters)
}

int main() {
    // Usage of the user-defined literal
    long double distance = 42.5_m; // 42.5 meters

    std::cout << "Distance: " << distance << " meters\n";

    return 0;
}


#endif

#if 0


#include <iostream>

// User-defined literal operator for picoseconds
constexpr long double operator"" _ps(long double value) {
    return value; // Interpret the value as picoseconds
}

int main() {
    // Usage of the user-defined literal
    long double timeInterval = 1000.0_ps; // 1000 picoseconds

    std::cout << "Time interval: " << timeInterval << " ps\n";

    return 0;
}


#endif

/*
Integer Literals:
Integer literals in C++ represent whole numbers without fractional or decimal parts.
Example: 42 (decimal), 0x2A (hexadecimal), 052 (octal).

Floating-Point Literals:
Floating-point literals represent numbers with fractional or decimal parts.
Example: 3.14, 2.5e-3.

Character Literals:
Character literals represent individual characters.
Enclosed in single quotes (e.g., 'A', '7', '%').

Escape sequences for special characters (e.g., '\n' for newline).

String Literals:
String literals represent sequences of characters.
Enclosed in double quotes (e.g., "Hello, World!").

Boolean Literals:
Boolean literals represent truth values (true or false).
Example: true, false.

Pointer Literals:
The nullptr literal represents a null pointer.


*/




#if 0

#include <iostream>
#include <string>

int main() {
    // Store the word "स्वागत" in a variable
    std::string welcomeMessage = "स्वागत";

    // Print the stored message
    std::cout << "Stored message: " << welcomeMessage << std::endl;

    return 0;
}


#endif

