#include <iostream>
#include <vector>

#if 1

/*
Use push_back when you want to move an existing object into the vector.
Use emplace_back when you create a new temporary object and want to construct it 
directly in place within the container12.
*/



struct MyObject {
    int value;
    explicit MyObject(int val) : value(val) {  std::cout << "object being created " << this->value  << "\n";}
};

int main() {
    std::vector<MyObject> myVec;
    myVec.emplace_back(42); // Constructs directly in place
    //myVec.push_back(42);
    MyObject obj(47);
    //myVec.emplace_back(obj);
    myVec.push_back(obj); // Copies obj into the vector
    // Access the element
    std::cout << "Value in vector: " << myVec[0].value << std::endl;
    return 0;
}




#endif

#if 0



struct A
{
    std::string s;
 
    A(std::string str) : s(std::move(str)) { std::cout << " constructed\n"; }
 
    A(const A& o) : s(o.s) { std::cout << " copy constructed\n"; }
 
    A(A&& o) : s(std::move(o.s)) { std::cout << " move constructed\n"; }
 
    A& operator=(const A& other)
    {
        s = other.s;
        std::cout << " copy assigned\n";
        return *this;
    }
 
    A& operator=(A&& other)
    {
        s = std::move(other.s);
        std::cout << " move assigned\n";
        return *this;
    }
};
 
int main()
{
    std::vector<A> container;
    // reserve enough place so vector does not have to resize
    container.reserve(10);
    std::cout << "construct 2 times A:\n";
    A two { "two" };
    A three { "three" };
 
    std::cout << "emplace:\n";
    container.emplace(container.end(), "one");
 
    std::cout << "emplace with A&:\n";
    container.emplace(container.end(), two);
 
    std::cout << "emplace with A&&:\n";
    container.emplace(container.end(), std::move(three));
 
    std::cout << "content:\n";
    for (const auto& obj : container)
        std::cout << ' ' << obj.s;
    std::cout << '\n';
}

#endif