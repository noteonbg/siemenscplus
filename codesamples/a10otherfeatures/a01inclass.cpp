#if 1

class MyClass {
public:
    int myInt = 42; // In-class initializer for an integer
    double myDouble = 3.14; // In-class initializer for a double
};


/*

When an object of MyClass is created, the member variables myInt and myDouble will be 
initialized with the specified default values (42 and 3.14, respectively).

*/

#endif

#if 1

int main()
{

    int a = 5;
    int b(5); //this indicates that for  class type constructor call.
    int c{5};  //Using braces {} ensures that the compiler protects against information loss during type convers
    auto d = 5; // 'd' is an integer compiler inference.
    return 0;

}


#endif