#if 1

#include <iostream>

// Example class template Pair
template <typename T, typename U>
struct Pair {
    T first;
    U second;

    Pair(T f, U s) : first(f), second(s) {}
};

/*
// Explicit deduction guide for Pair
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;  // we already saw this during templates

*/


/*

We provide an explicit deduction guide using -> syntax.
The deduction guide specifies that when we create a Pair object with
 two arguments, it should deduce the template arguments accordingly.
*/

int main() {
    // Create a Pair using explicit deduction guide
    Pair p = {42, "hello"};

    std::cout << "First: " << p.first << "\n";
    std::cout << "Second: " << p.second << "\n";

    return 0;
}


#endif