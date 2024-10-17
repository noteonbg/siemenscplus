#include <iostream>


#if 0

struct MyType {
    operator int() const {
        std::cout << "hi";
        return 42; // Implicit conversion to int
    }
};

int main() {
    MyType obj;
    int value = obj; // Implicit conversion
    // value is now 42
    double value1 =obj;
    return 0;
}



#endif



#if 1


/*

In C++11 and later, you can use the explicit keyword with conversion operators to prevent
 unintended implicit conversions.

*/

struct MyType {
    explicit operator int() const {
        return 42; // Explicit conversion to int
    }
};

int main() {
    MyType obj;
    // int value = obj; // Error: Cannot implicitly convert
   int value = static_cast<int>(obj); // Explicit conversion
    // value is still 42
    return 0;
}


#endif

#if 0


int main()
{
char c ='A';
int *q = static_cast<int*>(&c); // compile-time error

char d ='B';
int *q =(int*)&d; // c style cast problematic..

}

#endif