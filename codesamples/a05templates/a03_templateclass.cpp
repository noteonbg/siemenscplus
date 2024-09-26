#include <iostream>


#if 0
template <typename T>
class Device {
private:
  T deviceId;

public:
  // Constructor
  Device(T initialData) : deviceId(initialData) {}

  // Get the data
  T getDeviceId(); 

  // Set the data
  void setDeviceid(T deviceId);
   
};

template<typename T>
T Device<T>::getDeviceId()
{
    return deviceId;
}

template<typename T>
void Device<T>::setDeviceid(T initialData)
{
    deviceId = initialData;
    
}



int main() {
  // Create a MyTemplateClass object with an integer data type
  Device<int> device1(10);//compiler makes a copy

  // Get the data from the object
  int device_id1 = device1.getDeviceId();

  // Print the data
  std::cout << "The integer data is: " << device_id1 << std::endl;

  // Create a MyTemplateClass object with a string data type
  Device<std::string> device2("A1234");

  // Get the data from the object
  std::string device_id2 = device2.getDeviceId();

  // Print the data
  std::cout << "The string data is: " << device_id2 << std::endl;

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

#if 1

#include <iostream>
#include <string_view>
#include <source_location>

void log(std::string_view message,
         std::source_location location = std::source_location::current()
) {
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << ":"
              << location.function_name() << " "
              << message << '\n';
}

int f(int i) {
    log("Hello world!"); // Line 16
    return i + 1;
}

int f(double i) {
    log("Hello world!"); // Line 21
    return i + 1.0;
}

int main() {
    f(1);
    f(1.0);
}


#endif
