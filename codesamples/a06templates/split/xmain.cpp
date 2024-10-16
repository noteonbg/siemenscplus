#include "xheader.h"

// Extern declarations

/*
extern template class ElectronicComponent<int>;
extern template class ElectronicComponent<double>;
extern template class ElectronicComponent<std::string>;

*/

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

compiler the implementation of header
g++ -c .\xheaderimpl.cpp

make a static libary.
ar rcs xheaderimpl.a xheaderimpl.o
static library created with .a extension.


compile the main
g++ xmain.cpp -L./ -l:xheaderimpl.a -o work
-L./ adds the current directory to the library search path.
-lHeader links against the libHeader.a library.
-o my_program specifies the output executable name.








*/