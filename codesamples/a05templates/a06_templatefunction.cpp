#include <iostream>
#include <string>

// Template function to calculate power dissipation (P = I^2 * R)
template <typename T>
T calculatePower(T resistance, T current) {
    std::cout << "phase 3 \n";
    return current * current * resistance;
}

template <>
int calculatePower(int resistance,int current )
{
    std::cout << "phase 1";
    return resistance * current * current;
}


int calculatePower(int resistance,int current )
{

    std::cout << "phase 2";
    return resistance * current * current;
}

int main() {

    // Example with an electronic resistor
    #if 0
    double resistance = 1000.0; // Resistance in ohms
    double current = 0.02; // 20 mA
    double power = calculatePower(resistance, current);
    std::cout << "Power dissipation: " << power << " watts" << std::endl;
    #endif

    int iresistance =10;
    int icurrent =3;
    int ipower=5;
    ipower = calculatePower<int>(iresistance,icurrent);
    std::cout << "Power dissipation: " << ipower << " watts" << std::endl;





    
    #if 1
    // Example with a different data type (e.g., float)
    float resistanceFloat = 220.0; // Resistance in ohms
    float currentFloat = 0.01; // 10 mA
    float powerFloat = calculatePower(resistanceFloat, currentFloat);

    std::cout << "Power dissipation (float): " << powerFloat << " watts" << std::endl;
    #endif

    return 0;
}
