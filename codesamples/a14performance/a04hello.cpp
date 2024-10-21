#if 1

#include <iostream>
#include <chrono>
#include <thread>

// Simulated sensor reading (replace with actual sensor code)
double readTemperatureSensor() {
    // Simulate reading temperature (e.g., from an analog sensor)
    return 25.5; // Degrees Celsius
}

// Process temperature data (example: convert to Fahrenheit)
double processTemperature(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Transmit data (example: send over Wi-Fi)
void transmitData(double fahrenheit) {
    // Simulate data transmission (delay for demonstration)
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Transmitting: " << fahrenheit << "°F\n";
}

int main() {
    while (true) {
        // Read temperature from sensor
        double celsius = readTemperatureSensor();

        // Process temperature data
        double fahrenheit = processTemperature(celsius);

        // Transmit the processed data
        transmitData(fahrenheit);
    }
    return 0;
}


#endif

#if 0

#include <iostream>

// Simulated AND gate delay (in picoseconds)
constexpr int AND_GATE_DELAY = 10;

// Function to calculate delay through a chain of AND gates
int calculatePathDelay(int numGates) {
    // Each AND gate introduces a delay
    return numGates * AND_GATE_DELAY;
}

int main() {
    // Example: A path with 5 AND gates
    int numGates = 5;
    int pathDelay = calculatePathDelay(numGates);

    std::cout << "Path delay through " << numGates << " AND gates: "
              << pathDelay << " ps\n";

    return 0;
}


#endif

#if 0

#include <iostream>
#include <wiringPi.h> // Raspberry Pi GPIO library

int main() {
    wiringPiSetup(); // Initialize GPIO library

    const int ledPin = 17; // Example GPIO pin (BCM numbering)

    pinMode(ledPin, OUTPUT); // Set pin as output

    while (true) {
        digitalWrite(ledPin, HIGH); // Turn LED on
        delay(1000); // Wait for 1 second
        digitalWrite(ledPin, LOW); // Turn LED off
        delay(1000); // Wait for 1 second
    }

    return 0;
}


#endif

#if 0

#include <iostream>
#include <wiringPiI2C.h>

int main() {
    const int i2cDevice = 0x68; // Example I2C device address
    int fd = wiringPiI2CSetup(i2cDevice);

    // Read data from I2C device (e.g., accelerometer)
    int accelX = wiringPiI2CReadReg16(fd, 0x3B);

    std::cout << "Accelerometer X: " << accelX << std::endl;

    return 0;
}


#endif

#if 0

#include <iostream>
#include <softPwm.h>

int main() {
    const int servoPin = 23; // Example GPIO pin
    const int pwmRange = 100; // Example PWM range (0-100)

    softPwmCreate(servoPin, 0, pwmRange);

    while (true) {
        for (int dutyCycle = 0; dutyCycle <= pwmRange; ++dutyCycle) {
            softPwmWrite(servoPin, dutyCycle);
            delay(10);
        }
    }

    return 0;
}


#endif

/*


concept of **Application Binary Interface (ABI)** in C++.

1. **Definition**:
   - The **ABI** defines the **low-level details** that allow **separately compiled modules** 
   (such as libraries and executables) to **work together**.
   - It specifies how functions' arguments are passed, return values retrieved, 
   data types, size, alignment, and more.
   - Essentially, the ABI bridges the gap between **compiled code** and 
   **external libraries**.

2. **Key Points**:
   - **API vs. ABI**:
     - **API (Application Programming Interface)**: Defines the
      **order of function calls** and their **parameters** (high-level).

     - **ABI**: Specifies the **mechanics** of how these calls are
      implemented at the **binary level** (registers, stack, etc.).
   - 
   **C++ Name Mangling**:
     - C++ compilers encode function names (including argument types) into a unique format (name mangling) to handle function overloading and namespaces.
     - Different compilers may use different name mangling schemes, affecting ABI compatibility.
   - 
   **Stability and Compatibility**:
     - A **stable ABI** ensures that separately compiled modules can interoperate even if compiled with different versions of the same compiler.
     - Without a stable ABI, all parts of a program must be compiled with the **same version** of the **same compiler**³.

3. **Example**:
   - Suppose you compile a C++ program using **GCC** (GNU Compiler Collection). The **ABI** used by GCC affects how function calls, exceptions, and other low-level details are handled.
   - Different compilers (e.g., GCC, Clang, MSVC) may have **distinct ABIs**, making it challenging to mix binaries compiled with different compilers.

Remember that the **ABI** is essential for ensuring compatibility between compiled code and external libraries, especially when linking and loading programs! 🚀🔍 ¹²

Source: Conversation with Copilot, 6/6/2024
(1) Stability of the C++ ABI: Evolution of a Programming Language - Oracle. https://www.oracle.com/technical-resources/articles/it-infrastructure/stable-cplusplus-abi.html.
(2) What is an application binary interface (ABI)? - Stack Overflow. https://stackoverflow.com/questions/2171177/what-is-an-application-binary-interface-abi.
(3) ABI Policy and Guidelines - GCC, the GNU Compiler Collection. https://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html.
(4) en.wikipedia.org. https://en.wikipedia.org/wiki/Application_binary_interface.


*/