#if 0

#include <iostream>

template <int N>
void printValue() {
    std::cout << "Value: " << N << '\n';
}

int main() {
    printValue<42>(); // Prints "Value: 42"
    printValue<100>(); // Prints "Value: 100"
    return 0;
}


#endif