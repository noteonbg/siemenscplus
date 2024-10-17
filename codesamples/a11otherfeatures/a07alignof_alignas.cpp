#if 0

/*

The alignof operator returns the alignment requirement (in bytes) for a given type.
It tells you how many bytes the compiler will use to align objects of that type in memory.

*/

#include <iostream>

struct MyStruct {
    int x;
    double y;
    char z;
};

int main() {
    std::cout << "The alignof(MyStruct): " << alignof(MyStruct) << std::endl;
    return 0;
}


#endif

#if 0

//alignas Specifier:

/*
The alignas specifier allows you to force a specific alignment for a type or variable.
You can use it to ensure that objects are aligned to a certain boundary.

*/

#include <iostream>

// Aligns struct_float to the alignment of float (usually 4 bytes)
struct alignas(float) struct_float {
    // Your definition here
};

// Aligns sse_t to a 32-byte boundary
struct alignas(32) sse_t {
    float sse_data[4];
};

// Aligns cacheline to a 64-byte boundary
using cacheline_t alignas(64) = char[64];

int main() {
    std::cout << "alignof(struct_float): " << alignof(struct_float) << std::endl;
    std::cout << "sizeof(sse_t): " << sizeof(sse_t) << std::endl;
    std::cout << "alignof(sse_t): " << alignof(sse_t) << std::endl;
    return 0;
}



#endif

#if 1

/*

Alignment is a restriction on which memory positions a value’s first byte can be stored. 
It’s essential for improving performance on processors and enabling the use of specific instructions
 that work only on data with particular alignment. 
 For example, SSE instructions require data to be aligned to 16 bytes, while AVX requires 32-byte alignment.

Here’s how you can use alignas and alignof:

alignas:
The alignas specifier forces alignment to a specific number of bytes.
You can only align to powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, and so on.





*/

#include <iostream>

int main() {
    alignas(16) int a[4];
    alignas(1024) int b[4];
    std::cout << &a << '\n';
    std::cout << &b << '\n';
    return 0;
}


#endif