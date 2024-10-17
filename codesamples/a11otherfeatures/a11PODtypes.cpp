#if 1

/*
POD (Plain Old Data) 

It is both trivial and standard-layout.
Triviality means that it has a straightforward default constructor, 
destructor, and copy/move operations.

Standard-layout ensures that the memory layout is contiguous,
and each member has a higher address than 
the one declared before it.



*/
struct Point {
    int x;
    int y;
};

int main() {
    Point p1 = {10, 20}; // Initialization using brace notation
    Point p2;
    p2.x = 30;
    p2.y = 40;

    // Byte-for-byte copy
    Point p3 = p1;

    // Binary I/O operations
    // (e.g., writing to a file or network stream)
    // ...

    return 0;
}


/*

POD types are useful for  serialization.

*/

#endif

