#if 1

#include <iostream>

class Rectangle {
public:
    int width;
    int height;
    Rectangle(int w, int h) : width(w), height(h) {}
};





int main()
{

    //Narrowing Conversions, Initialization Caveats 
    double d = 5.0;
int i = d; // Narrowing conversion (may lose fractional part)

int n = 42;
double x = n; // Not narrowing (exact representation)

//
unsigned int u = 100;
short s = u; // Narrowing (unsigned to signed)

/*

void someFcn(int i) {  }
double d = 5.0;
someFcn(static_cast<int>(d)); // Explicit narrowing conversion

Brace initialization (using curly braces) disallows narrowing conversions.
It’s one of the reasons why brace initialization is preferred.

*/

int io(3.3);

float f1 =3.3f;
float f2 =3.2f;




/*
Rectangle r1{10, 5};
Rectangle r2 = {8, 6};
*/



}


#endif