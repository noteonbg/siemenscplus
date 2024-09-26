/*

In C++, the extern template declaration is used to explicitly instantiate templates, which can improve compilation times and reduce code bloat. This feature allows you to separate the declaration of a template from its definition, ensuring that the template is instantiated in only one translation unit, while other translation units can use the pre-instantiated template.


*/

#if 0

// ElectronicComponent.h
#ifndef ELECTRONICCOMPONENT_H
#define ELECTRONICCOMPONENT_H

#include <iostream>
#include <string>

template <typename T>
class ElectronicComponent {
public:
    ElectronicComponent(const std::string& name, T value);
    void print() const;

private:
    std::string name;
    T value;
};

template <typename T>
ElectronicComponent<T>::ElectronicComponent(const std::string& name, T value)
    : name(name), value(value) {}

template <typename T>
void ElectronicComponent<T>::print() const {
    std::cout << "Component: " << name << ", Value: " << value << std::endl;
}

/*
ElectronicComponent.h defines a 
template class ElectronicComponent that takes a
 type parameter T.
The class has a constructor and a print method,
 both defined within the header file.

*/

#endif // ELECTRONICCOMPONENT_H

// ElectronicComponent.cpp
#include "ElectronicComponent.h"

// Explicit instantiation of template classes
template class ElectronicComponent<int>;
template class ElectronicComponent<double>;
template class ElectronicComponent<std::string>;


/*
ElectronicComponent.cpp includes 
the header file and explicitly 
instantiates the ElectronicComponent template
 for int, double, and std::string.

This ensures that the template is instantiated only once,
 avoiding multiple instantiations across different translation
  units.

*/


// main.cpp
#include "ElectronicComponent.h"

// Extern declarations
extern template class ElectronicComponent<int>;
extern template class ElectronicComponent<double>;
extern template class ElectronicComponent<std::string>;

/*

main.cpp includes the header file and uses extern template to
 declare the instantiated templates for int, double, and
  std::string.
This tells the compiler that these templates are 
instantiated elsewhere, preventing multiple instantiations.


*/
int main() {
    ElectronicComponent<int> resistor("Resistor", 1000);
    ElectronicComponent<double> capacitor("Capacitor", 1e-6);
    ElectronicComponent<std::string> inductor("Inductor", "10mH");

    resistor.print();
    capacitor.print();
    inductor.print();

    return 0;
}

/*

key points are

enefits
Compilation Time: Using extern template can significantly reduce
 compilation times by avoiding redundant template instantiations.
Code Size: It helps in reducing the code size, as the 
template code is instantiated only once.

Caveats
Ensure that the explicit instantiation in the .cpp file
 covers all the types you intend to use with the template.
If you miss any type, it will result in a linker 
error since the definition will be missing.


*/


#endif