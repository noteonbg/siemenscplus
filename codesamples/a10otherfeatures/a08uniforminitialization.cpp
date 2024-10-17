#if 1

//Uniform initialization is a feature introduced in C++11 that allows consistent syntax for 
//initializing variables and objects using braces ({}) to enclose initializer values. 
//It simplifies initialization across various types, including primitive types and aggregates.

class A {
    int arr[3];

public:
    A(int x, int y, int z) : arr{x, y, z} {}// look array has been intialized.
};


namespace another
{
class A {
    int a;
    int b;
public:
    A(int x, int y) : a(x), b(y) {}
};

A f(int a, int b) {
    return {a, b};
}



void f(A x) {
    // Use x
}

void check() {
    f({1, 2});
    return ;
}



}




int main()
{
//    int i = 10;
int i{10};
// for array
int a[]{1, 2, 3, 4};




}


#endif