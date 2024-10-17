#if 1

#include <iostream>

int main() {
    if (int x = 42; x > 30) {
        
        std::cout << "x is greater than 30\n";
    } else {
        std::cout << "x is not greater than 30\n";
    }

    // Uncomment the line below to see the error (x is out of scope here)
    // std::cout << "x outside if: " << x << "\n";

    return 0;
}

#endif

#if 1

#include <iostream>

int main() {
    switch (int day = 3; day) {
        case 1:
            std::cout << "Monday\n";
            break;
        case 2:
            std::cout << "Tuesday\n";
            break;
        default:
            std::cout << "Other day\n";
    }

    // Uncomment the line below to see the error (day is out of scope here)
    // std::cout << "day outside switch: " << day << "\n";

    return 0;
}


#endif