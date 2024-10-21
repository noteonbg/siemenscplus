#include <iostream>

class A
{
    public:
        A()=default;
        A(const A& c) =delete;
    private:
        //A(const A& c) {}

};

int main()
{
std::cout <<1;
A obj1;
A obj = obj1;
return 0;


}