#if 1

#include <iostream>
#include <memory> // Include the <memory> header for shared_ptr

struct MyClass {
    int value;

    MyClass(int val) : value(val) {
        std::cout << "Constructing MyClass with value: " << value << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructing MyClass with value: " << value << std::endl;
    }
};

void f1(std::shared_ptr<MyClass> ptr2)
{

    ptr2->value=44;
    std::cout << "Value via ptr2: " << ptr2->value << std::endl;
      //if you want to detach go ahead
//      ptr2.reset(); // ptr no longer points to the the object

}

int main() {
    // Create a shared_ptr to a dynamically allocated MyClass object
    
    {
    std::shared_ptr<MyClass> ptr1(new MyClass(3));

     f1(ptr1);
        // Create another shared_ptr pointing to the same object
    // Access the object via ptr2 (still valid)
    
    std::cout << "Value via ptr1 after reset: " << ptr1->value << std::endl;
    }
    std::cout  << "main function at work";
    return 0;
}

#endif

/*

Shared Ownership:
Use std::shared_ptr when you want shared ownership of a dynamically allocated resource.
Multiple shared_ptr instances can point to the same object, and the resource is automatically cleaned
 up when the last shared_ptr goes out of scope1.
Member Objects:
You can use std::shared_ptr to point to member objects while owning the object they belong to.
This is useful when you want to share ownership of a part of an object2.

*/

#if 0

#include <iostream>
#include <memory>
#include <unordered_map>

// Example EDA component (simplified)
struct EDAComponent {
    std::string id;
    std::string type;
    // Other relevant data members...
};

class CircuitDesigner {
private:
    std::string designerId;
    std::string designerName;
    std::unordered_map<std::string, std::shared_ptr<EDAComponent>> circuitComponents;

public:
    CircuitDesigner(const std::string& id, const std::string& name)
        : designerId(id), designerName(name) {}

    void addComponentToCircuit(const std::shared_ptr<EDAComponent>& component) {
        circuitComponents[component->id] = component;
    }

    void printCircuit() const {
        std::cout << "Circuit for Designer " << designerName << " (ID: " << designerId << "):\n";
        for (const auto& entry : circuitComponents) {
            const auto& component = entry.second;
            std::cout << "  Component ID: " << component->id << ", Type: " << component->type << "\n";
            // Print other relevant info...
        }
    }
};

int main() {
    // Create shared_ptr for a NAND gate
    auto nandGate = std::make_shared<EDAComponent>();
    nandGate->id = "NAND123";
    nandGate->type = "NAND";
    // Initialize other properties...

    // Create circuit designers
    CircuitDesigner designerPerson1("D001", "Satish");
    CircuitDesigner designerPerson2("D002", "Anu");

    
    designerPerson1.addComponentToCircuit(nandGate);

    // Add the same NAND gate to Bob's circuit
    designerPerson2.addComponentToCircuit(nandGate);

    // Print circuit details
    designerPerson1.printCircuit();
    designerPerson2.printCircuit();

    return 0;
}


#endif
