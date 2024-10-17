#if 1

#include <iostream>
#include <string>

class Person {
public:
    // Default constructor
    Person() : Person("Unknown", 0) {}

    // Constructor with name and age
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Creating a Person object: " << name << ", " << age << " years old\n";
    }

    // Constructor with name (delegates to the previous constructor)
    Person(const std::string& name) : Person(name, 0) {

        
    }

    // Print person details
    void printDetails() {
        std::cout << "Name: " << name << ", Age: " << age << " years\n";
    }

private:
    std::string name;
    int age;
};

int main() {
    Person p1; // Default constructor
    p1.printDetails();

    Person p2("X", 30); // Constructor with name and age
    p2.printDetails();

    Person p3("Y"); // Constructor with name (delegates to the previous constructor)
    p3.printDetails();

    return 0;
}


#endif