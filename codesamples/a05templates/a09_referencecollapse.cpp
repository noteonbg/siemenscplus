#if 0

#include <iostream>

void process(int& value) {
    std::cout << "Processing lvalue reference: " << value << '\n';
}

void process(int&& value) {
    std::cout << "Processing rvalue reference: " << value << '\n';
}

int main()
{
    int k=4;
    int &m =k;
    process(4);
    return 0;

}


#endif




#if 0


#include <iostream>

template <typename T>
void foo(T&& value) {
    std::cout << "Reference type: ";
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "lvalue reference\n";
    } else if constexpr (std::is_rvalue_reference_v<T>) {
        std::cout << "rvalue reference\n";
    } else {
        std::cout << "neither lvalue nor rvalue reference\n";
    }
}

int main() {
    int x = 42;
    int& lvalue_ref = x;
    int&& rvalue_ref = 42;

   // foo(x);         // lvalue reference

   
   // foo(lvalue_ref); // lvalue reference
    
   // foo(rvalue_ref); // lvalue reference
    foo(42);        // rvalue reference
   
}

//stop look at the output..


#endif
#if 0

#include <iostream>
#include <utility>

void process(int& value) {
    std::cout << "Processing lvalue reference: " << value << '\n';
}

void process(int&& value) {
    std::cout << "Processing rvalue reference: " << value << '\n';
}



#if 0
template <typename T>
// problem is both l reference and r refernce are calling the same function.
void forward_example(T&& value) {
    std::cout << "1 \n ";
    process(value);
}
#endif

#if 0
 // problem of not being able to assing a r_refernece to it
template <typename T>
void forward_example(T& value) {
    std::cout << "2 \n ";
    process(value);
}
#endif


#if 0
template<typename T>
void forward_example(T&& value) {
    process(std::forward<T>(value));
}
#endif


int main() {
    int x = 42;
    forward_example<int&>(x);       // lvalue reference
    forward_example<int&&>(123);     // rvalue reference
     //forward_example(std::move(x)); // rvalue reference

     

   


}

#endif

#if 0

#include <iostream>
#include <utility>

class MyClass {
public:
    MyClass(int value) : data(value) {}
    int getData() const { return data; }

private:
    int data;
};

int main() {
    MyClass obj1(42);
    MyClass obj2 = std::move(obj1); // Move obj1 into obj2

    std::cout << "obj1 data: " << obj1.getData() << '\n'; // Undefined behavior
    std::cout << "obj2 data: " << obj2.getData() << '\n'; // 42
}


#endif