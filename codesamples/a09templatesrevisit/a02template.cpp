#include <iostream>

#if 1

template <typename T>
class Multiplexer {
public:
    Multiplexer(T a, T b, bool select) : inputA(a), inputB(b), selectLine(select) {}

    T output() {
        return selectLine ? inputB : inputA;
    }

private:
    T inputA;
    T inputB;
    bool selectLine;
};

// Explicit instantiation of the Multiplexer for int and float
template class Multiplexer<int>;
template class Multiplexer<float>;

// Creating template aliases
using IntMux = Multiplexer<int>;
using FloatMux = Multiplexer<float>;


#include <iostream>

int main() {
    Multiplexer<int> intMux(1, 2, true);
    Multiplexer<float> floatMux(1.5, 2.5, false);

    std::cout << "Int MUX output: " << intMux.output() << std::endl; // Outputs 2
    std::cout << "Float MUX output: " << floatMux.output() << std::endl; // Outputs 1.5


    IntMux intMux(1, 2, true);
    FloatMux floatMux(1.5, 2.5, false);

    std::cout << "Int MUX output: " << intMux.output() << std::endl; // Outputs 2
    std::cout << "Float MUX output: " << floatMux.output() << std::endl; // Outputs 1.5


    return 0;
}



#endif


#if 0
#include <iostream>

namespace N {
    class C {
        public:
            template <class T>
            static void f(int i) {
                (void)i;
                std::cout << "__func__            " << __func__ << std::endl
                          << "__FUNCTION__        " << __FUNCTION__ << std::endl
                          << "__PRETTY_FUNCTION__ " << __PRETTY_FUNCTION__ << std::endl;
            }
            template <class T>
            static void f(double f) {
                (void)f;
                std::cout << "__PRETTY_FUNCTION__ " << __PRETTY_FUNCTION__ << std::endl;
            }
    };
}

int main() {
    N::C::f<char>(1);
    N::C::f<void>(1.0);
}

#endif



#if 0
template<typename T, size_t N>
class MyArray
{
    T arr[N];
public:
    // Full definitions:
    MyArray(){}
    void Print()
    {
        for (const auto v : arr)
        {
            std::cout << v << " , ";
        }
    }

    T& operator[](int i)
   {
       return arr[i];
   }
};

#endif

#if 0

int main()
{

    MyArray<int,3> intArray;
    MyArray<double,4> doubleArray;
    return 0;
}

#endif



#if 0


template<typename T, size_t N>
class MyArray
{
    T arr[N];
public:
    MyArray();
    void Print();
    //T& operator[](int i);
};

template<typename T, size_t N>
MyArray<T,N>::MyArray(){}

template<typename T, size_t N>
void MyArray<T,N>::Print()
{
    std::cout << "print function working";
}

int main()
{
    MyArray<int,5> intarray;
    intarray.Print();


}
#endif

#if 0


namespace N
{
    template<class T>
    class Y // template definition
    {
    public:
        void mf() { std::cout << "this function is member function"; }
    };
}
 
// template class Y<int>; // error: class template Y not visible in the global namespace
using N::Y;
// template class Y<int>; // error: explicit instantiation outside
                          // of the namespace of the template
template class N::Y<char*>;       // OK: explicit instantiation
template void N::Y<double>::mf(); // OK: explicit instantiation

int main()
{
    N::Y<int> x;
    x.mf();
    std::cout << "\n hello world working";
    return 0;
}



#endif

#if 1



void freak(); //no surpises.. old c behaviour 

template<class T>
struct Z // template definition
{
    void f() { std::cout  <<"logic is ours"; }
    void g(); // never defined
};

//template struct Z<double>;
extern template struct Z<double>;

int main()
{
 
 // explicit instantiation of Z<double>
Z<int> a;                  // implicit instantiation of Z<int>
Z<char>* p;                // nothing is instantiated here
 
p->f(); // implicit instantiation of Z<char> and Z<char>::f() occurs here.
        // Z<char>::g() is never needed and never instantiated:
 
        // it does not have to be defined

}
#endif

