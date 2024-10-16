#include <iostream>
#include "a03template.h"
using namespace std;

template<typename T, size_t N>
MyArray<T,N>::MyArray(){}

template<typename T, size_t N>
void MyArray<T,N>::Print()
{

    std::cout << "print function at work" << "\n ";
    
}
