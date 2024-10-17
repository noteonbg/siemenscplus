/*

In C++, a literal type is a type that can be constructed at compile time,
 and its objects can be used in constant expressions.

class or struct to be considered a literal type, it must satisfy the following conditions:

Trivial Destructor: The destructor must be trivial.
All Base Classes and Non-static Data Members: Must be of literal types.
No Virtual Member Functions: The class cannot have virtual functions or
 virtual base classes.
User-Defined Constructors: Must be constexpr if defined

Built-in Literal Types
  
Integral Types: int, char, bool, long, etc.
Floating-Point Types: float, double.
Pointers: Pointers to objects and functions.
References: References to objects and functions.



*/

#if 1
struct Point {
    int x;
    int y;
    constexpr Point(int x, int y) : x(x), y(y) {}
};


struct Rectangle {
    int width;
    int height;

    constexpr Rectangle(int w, int h) : width(w), height(h) {}
    constexpr int area() const {
        return width * height;
    }
};

constexpr Point p1(3, 4);
constexpr Rectangle r1(3, 4);

//Non-Literal Type Example

struct NonLiteral {
    int x;
    NonLiteral() {}  // Non-constexpr constructor
};



int main() {
    static_assert(p1.x == 3, "p1.x should be 3");
    static_assert(r1.area() == 12, "r1.area() should be 12");

    return 0;
}




#endif





