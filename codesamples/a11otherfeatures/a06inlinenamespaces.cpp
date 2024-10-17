#include <iostream>
#include <cmath>

#if 1

// Header.h
#include <string>

namespace Test
{
    namespace old_ns
    {
        std::string Func(){ 
            return std::string("Hello from old"); 
            }
    }


    inline namespace new_ns
    {
        std::string Func() { return std::string("Hello from new"); }
    }

   
}

// main.cpp
//#include "header.h"
#include <string>
#include <iostream>

int main()
{
    using namespace Test;
    using namespace std;

    string s = Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}

#endif

