#ifndef MATH_UTILS_H
#define MATH_UTILS_H

inline int square(int x) {
    return x * x;
}

#endif // MATH_UTILS_H


/*


Compilation Process
Preprocessing: Each source file is preprocessed to include the contents of math_utils.h.
 This means that both main.cpp and other.cpp will have their own copies
  of the square function definition.

Translation Units:

main.cpp becomes one translation unit.
other.cpp becomes another translation unit.
Compilation:

Both translation units are compiled separately.
 The square function is treated as an inline function.
  The compiler can choose to expand it inline wherever it is called.
Linking:

Since square is defined as inline, there are no multiple definition errors
 during linking, even though both translation units 
 contain the same function definition


*/