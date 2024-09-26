#include <iostream>
#include <string>

/*
https://cppinsights.io/ just to see how the code gets generated.


*/


#if 1

template <class T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;

    //observe two operations one for T return by copy
    // observe < symbol must be overloaded for the data type in case it is a class type.
}


int main()
{

int result = minimum(2,3);
double dresult = minimum<double>(2.3,4.3);
double doubleArray[]={2,3};
char arrayArray[]={'a','b'};
sort<double>(doubleArray,3);
sort(doubleArray,3);


std::cout  <<"hi";
return 0;

}


/*
T is a template parameter;
 the typename keyword says that this parameter 
 is a placeholder for a type.
*/



// Generic sort function template
template <typename T>
void sort(T arr[], int size) {
    // Implementation for generic types
    // (e.g., Quick Sort, Merge Sort, etc.)
    std::cout  <<"template for geneeric types";
}

// Specialization for char arrays (using Counting Sort)
template <>
void sort<char>(char arr[], int size) {
    // Implementation specific to char arrays
    // (e.g., Counting Sort, Radix Sort, etc.)
    std::cout << "template specialization with respect to char";
    
}

int sort(char freak[], int length)
{

   return 3;
}


#if 0

// Generic simulate function template
template <typename CircuitType>
void simulate(const CircuitType& circuit) {
    // Implementation for generic circuit types
    // (e.g., event-driven simulation, time-domain analysis, etc.)
}

// Specialization for analog circuits (using SPICE)
template <>
void simulate<AnalogCircuit>(const AnalogCircuit& circuit) {
    // SPICE-based simulation specific to analog circuits
    // (e.g., transient analysis, AC analysis, etc.)
}

// Generic Component class template
template <typename ComponentType>
class Component {
    // Implementation for generic component types
};

// Specialization for resistors (using Ohm's law)
template <>
class Component<Resistor> {
private:
    double resistance; // Resistance value in ohms
public:
    // Specific methods for resistors
    // (e.g., compute current, voltage drop, etc.)
};

#endif







#endif


#if 1



template <typename T, typename U, typename V=std::string>
 struct POC{

        T tvar;
        U uvar;
        V vvar;


};




int main()
{

    POC<int,char> temp;
    temp.tvar=23;
    temp.uvar='A';
    temp.vvar="hello";
    return 0;

}


#endif


#if 0

template<typename U,int>
class Arr
{


};

template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
   // U u; //Error. U not in scope
};

int main()
{

    Arr<int,3,4> ;
    
    return 0;
}

#endif


#if 0

//later, the compiler deduces the type of a non-type template argument that's declared with auto:
template <auto x>  auto constant = x;
int main()
{

    auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
    auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
    auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
    return 0;
}


#endif

#if 1

// partial_specialization_of_class_templates.cpp
#include <stdio.h>

template <class T> struct PTS {
   enum {
      IsPointer = 0,
      IsPointerToDataMember = 0
   };
};



#if 0
template <class T> struct PTS<T*> {
   enum {
      IsPointer = 1,
      IsPointerToDataMember = 0
   };
};

template <class T, class U> struct PTS<T U::*> {
   enum {
      IsPointer = 0,
      IsPointerToDataMember = 1
   };
};

#endif

struct S{};

int main() {
   printf_s("PTS<S>::IsPointer == %d \nPTS<S>::IsPointerToDataMember == %d\n",
           PTS<S>::IsPointer, PTS<S>:: IsPointerToDataMember);
   printf_s("PTS<S*>::IsPointer == %d \nPTS<S*>::IsPointerToDataMember == %d\n"
           , PTS<S*>::IsPointer, PTS<S*>:: IsPointerToDataMember);
   printf_s("PTS<int S::*>::IsPointer == %d \nPTS"
           "<int S::*>::IsPointerToDataMember == %d\n",
           PTS<int S::*>::IsPointer, PTS<int S::*>::
           IsPointerToDataMember);
}

#endif

#if 0


#include <iostream>
using namespace std;

template <class Key, class Value> class Dictionary {
   Key* keys;
   Value* values;
   int size;
   int max_size;
public:
   Dictionary(int initial_size) :  size(0) {
      max_size = 1;
      while (initial_size >= max_size)
         max_size *= 2;
      keys = new Key[max_size];
      values = new Value[max_size];
   }
   void add(Key key, Value value) {
      Key* tmpKey;
      Value* tmpVal;
      if (size + 1 >= max_size) {
         max_size *= 2;
         tmpKey = new Key [max_size];
         tmpVal = new Value [max_size];
         for (int i = 0; i < size; i++) {
            tmpKey[i] = keys[i];
            tmpVal[i] = values[i];
         }
         tmpKey[size] = key;
         tmpVal[size] = value;
         delete[] keys;
         delete[] values;
         keys = tmpKey;
         values = tmpVal;
      }
      else {
         keys[size] = key;
         values[size] = value;
      }
      size++;
   }

   void print() {
      for (int i = 0; i < size; i++)
         cout << "{" << keys[i] << ", " << values[i] << "}" << endl;
   }
};

// Template partial specialization: Key is specified to be int.
template <class Value> class Dictionary<int, Value> {
   int* keys;
   Value* values;
   int size;
   int max_size;
public:
   Dictionary(int initial_size) :  size(0) {
      max_size = 1;
      while (initial_size >= max_size)
         max_size *= 2;
      keys = new int[max_size];
      values = new Value[max_size];
   }
   void add(int key, Value value) {
      int* tmpKey;
      Value* tmpVal;
      if (size + 1 >= max_size) {
         max_size *= 2;
         tmpKey = new int [max_size];
         tmpVal = new Value [max_size];
         for (int i = 0; i < size; i++) {
            tmpKey[i] = keys[i];
            tmpVal[i] = values[i];
         }
         tmpKey[size] = key;
         tmpVal[size] = value;
         delete[] keys;
         delete[] values;
         keys = tmpKey;
         values = tmpVal;
      }
      else {
         keys[size] = key;
         values[size] = value;
      }
      size++;
   }

   void sort() {
      // Sort method is defined.
      int smallest = 0;
      for (int i = 0; i < size - 1; i++) {
         for (int j = i; j < size; j++) {
            if (keys[j] < keys[smallest])
               smallest = j;
         }
         swap(keys[i], keys[smallest]);
         swap(values[i], values[smallest]);
      }
   }

   void print() {
      for (int i = 0; i < size; i++)
         cout << "{" << keys[i] << ", " << values[i] << "}" << endl;
   }
};

int main() {
   Dictionary<const char*, const char*> dict(10);
   dict.print();
   dict.add("apple", "fruit");
   dict.add("banana", "fruit");
   dict.add("dog", "animal");
   dict.print();

   Dictionary<int, const char*> dict_specialized(10);
   dict_specialized.print();
   dict_specialized.add(100, "apple");
   dict_specialized.add(101, "banana");
   dict_specialized.add(103, "dog");
   dict_specialized.add(89, "cat");
   dict_specialized.print();
   dict_specialized.sort();
   cout << endl << "Sorted list:" << endl;
   dict_specialized.print();
}


#endif


#if 0
#include <iostream>

template<class T> void f(T) { std::cout << "function template called"; }

// Instantiate f with the explicitly specified template.
// argument 'int'
//
template void f<int> (int);

// Instantiate f with the deduced template argument 'char'.
template void f(char);
int main()
{
  	f('c');  // automatic instiation
    f(3.3);  //automatic instantiation
  
}

/*

You can use explicit instantiation to create an instantiation of a templated class or
 function without actually using it in your code.
  Because it's useful when you're creating library (.lib) files that use templates for distribution,
   uninstantiated template definitions aren't put into object (.obj) files.


   template class MyStack<int, 6>

   Code is generated for all members.

*/





#endif

#if 0

#include <iostream>


template<typename T>
class Device
{
    x deviceId;

    public:
        void set_device_id(const T x);
        T get_device_id();

};

template<typename T>
void Device<T>::set_device_id(const T x) 
{
    deviceId =x;

}

template<typename T>
T Device<T>::get_device_id() 
{
    return deviceId;

}


//template class Device<int>; //members intialized
extern template class Device<int>;  // no member intialized


int main()
{

 std::cout << "hello\n";
 return 0;

}









#endif

#if 0

#include <iostream>

// member_function_templates.cpp
struct X
{
   template <class T> void mf(T* t) { std::cout << "logic we need to define"; }
};

int main()
{
   int i;
   X* x = new X();
   x->mf(&i);
}

#endif

