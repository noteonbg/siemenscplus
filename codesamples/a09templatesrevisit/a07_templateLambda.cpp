// templateLambda.cpp

#include <iostream>
#include <string>
#include <vector>

auto sumInt = [](int fir, int sec) { return fir + sec; };            // only to int convertible types (C++11)
auto sumGen = [](auto fir, auto sec) { return fir + sec; };          // arbitrary types (C++14)
auto sumDec = [](auto fir, decltype(fir) sec) { return fir + sec; }; // arbitrary, but convertible types (C++11)
auto sumTem = []<typename T>(T fir, T sec) { return fir + sec; };    // arbitrary, but identical types (C++20)

int main() {
    
    std::cout << std::endl;
   
    
    std::cout << std::endl;
    
    std::cout << "sumInt(true, 2010): " << sumInt(true, 2010) << std::endl;
    std::cout << "sumGen(true, 2010): " << sumGen(true, 2010) << std::endl;
    std::cout << "sumDec(true, 2010): " << sumDec(true, 2010) << std::endl; 
    std::cout << "sumTem(true, 2010): " << sumTem(true, 2010) << std::endl; 
    
    std::cout << std::endl;
    
}

