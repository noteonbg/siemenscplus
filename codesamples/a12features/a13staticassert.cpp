#if 1

#include <iostream>
#include <vector>

template <class T, int Size>
class Vector {
    static_assert(Size > 3, "Vector size is too small!");
    T m_values[Size];
};

int main() {
    Vector<int, 4> four; // OK
    // Uncomment the line below to see the error:
    // Vector<short, 2> two; // Error (Vector size is too small!)
    return 0;
}


#endif