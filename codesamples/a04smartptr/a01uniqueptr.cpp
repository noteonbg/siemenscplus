#include <iostream>
#include <memory> // Include the <memory> header for unique_ptr

#if 0
struct B
{
    virtual ~B() = default;
 
    virtual void bar() { std::cout << "B::bar\n"; }

    void f1() { std::cout  <<"this is function f1 of B\n "; }
};
 
struct D : B
{
    D() { std::cout << "D::D\n"; }
    D(int x, int y)  { std::cout << "parametrized constructor"; }
    ~D() { std::cout << "D::~D\n"; }
 
    void bar() override { std::cout << "D::bar\n"; }
};
 

void freak(std::unique_ptr<D> up)
{

        up->f1();
}


int main()
{
    //we have dynamically allocated memory on heap
    {
    //std::unique_ptr<B> up(new B());
    std::unique_ptr<D> up =std::make_unique<D>(2,3);
    freak(std::move(up));
   //up->bar();
   // up->f1();
    
}
std::cout <<"main function";
}

#endif

#if 0
struct MyClass {
    int value,value2;

    MyClass(int val,int anotherval,char anotherval1) : value(val) {
        std::cout << "Constructing MyClass with value: " << value << std::endl;
        value2=anotherval;
    }

    void freak()
    {
        std::cout <<"freak function at work" << value2  << "\n ";
    }

    ~MyClass() {
        std::cout << "Destructing MyClass with value: " << value << std::endl;
    }
};




int main() {



    // Create a unique_ptr to manage a dynamically allocated MyClass object
    std::unique_ptr<MyClass> scrap = 
    std::make_unique<MyClass>(42,23,'A');

    // Access the object through the unique_ptr
    std::cout << "Value via ptrObj: " << scrap->value << std::endl;
    scrap->freak();
     
    // The object is automatically deleted when ptrObj goes out of scope
    return 0;
}

#endif

#if 1

#include <iostream>
#include <memory>

// Example EDA component (simplified)
struct EDAComponent {
    int id;
    // Other relevant data members...
};

class CircuitNetlist {
private:
    std::unique_ptr<EDAComponent[]> components_; // Array of components
    size_t numComponents_;

public:
    explicit CircuitNetlist(size_t numComponents) : numComponents_(numComponents) {
        components_ = std::make_unique<EDAComponent[]>(numComponents_);
        // Initialize components (e.g., set IDs, load data from files, etc.)
        for (size_t i = 0; i < numComponents_; ++i) {
            components_[i].id = static_cast<int>(i);
            // Initialize other data...
        }
    }

    // Other methods for querying and manipulating the netlist...

    void printComponentInfo(size_t index) const {
        if (index < numComponents_) {
            std::cout << "Component ID: " << components_[index].id << std::endl;
            // Print other relevant info...
        } else {
            std::cout << "Invalid component index." << std::endl;
        }
    }
};

int main() {
    // Create a netlist with 5 components
    CircuitNetlist netlist(5);

    // Access component information
    netlist.printComponentInfo(2); // Print info for component at index 2

    // No need to manually delete components; unique_ptr handles it automatically

    return 0;
}


#endif

/*


Exclusive Ownership:
std::unique_ptr provides exclusive ownership of a dynamically allocated resource.
 Only one unique_ptr can point to a resource at a time.
This ensures that the resource is automatically cleaned up when the unique_ptr goes out of scope,
 preventing memory leaks1.

No Reference Counting Overhead:
Unlike std::shared_ptr, which maintains reference counts, std::unique_ptr has less overhead.
 It doesn’t count references.

This makes it more efficient in terms of memory and performance2.
Move Semantics:
std::unique_ptr is movable but not copyable. It supports move semantics, 
allowing efficient transfer of ownership between objects.

When using unique_ptr as a member variable, you might need to 
write move constructors or use std::move.

Passing a unique_ptr by value also requires using std::move2.
Clear Ownership Model:
When you use std::unique_ptr, it should completely own the managed object. It’s not shared with other classes.

*/