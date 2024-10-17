//wrong usage of constexpr usually..

#if 1

namespace poc
{

constexpr int add(int a, int b) {
    return a + b;
}

void f1() {
    constexpr int x = 5;
    int y = 10;

    // Error: Non-constexpr function parameter 'y'
    constexpr int result = add(x, y);
}

struct MyClass {
    int data = 42;

    // Error in C++14 and later: Non-static constexpr member function
    constexpr void modifyData() {
        data = 100; // Not allowed
    }
};

void f2() {
    constexpr MyClass obj;
    // Error: Cannot call non-static constexpr member function
    obj.modifyData();
}


}//end of namespace poc

#include <atomic>

// where const expr cannot be used.


int main()
{

// Error: Pointers cannot be constexpr
constexpr int* ptr = nullptr;

// Error: Variably modified type (array with runtime size)
constexpr int arr[] = {1, 2, 3};



// Error: Atomic type cannot be constexpr
constexpr std::atomic<int> atomic_value{42};

// Error: Volatile type cannot be constexpr
constexpr volatile int volatile_value = 10;


return 0;



}

#endif