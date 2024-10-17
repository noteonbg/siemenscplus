#if 1

#include <iostream>

int main() {
    // Generic lambda to compute the sum of two values
    decltype(auto) sum =  [](auto a, auto b){

        return a + b;
    };

    auto f1 = []() { static int x=4; int &y=x; return y; };

    std::cout << typeid(f1()).name();
  

    /*
    std::cout << "Sum of integers: " << sum(1, 6) << "\n";
    auto ok = sum(10,5.6);
    std::cout << "Sum of doubles: " <<  "\n";

    */

    //std::cout << "Concatenated strings: " << sum("Geeks", "ForGeeks") << "\n";


    return 0;
}


#endif