#if 1

#include <iostream>
#include <memory>

/*

in C++. A std::weak_ptr is a smart pointer that holds a non-owning (“weak”)
 reference to an object managed by a std::shared_ptr. 
 It allows you to access the referenced object without affecting its reference count.

*/

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor" << std::endl; }
};

int main() {
    // Create a shared_ptr to MyClass
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // Create a weak_ptr from the shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // Check if the weak_ptr is expired (i.e., if the object has been deleted)
    if (weakPtr.expired()) {
        std::cout << "Weak pointer is expired." << std::endl;
    } else {
        std::cout << "Weak pointer is still valid." << std::endl;
    }

    // Access the object through the weak_ptr (if it's still valid)
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Accessing object through weak pointer." << std::endl;
        // Do something with lockedPtr...
    } else {
        std::cout << "Object has been deleted." << std::endl;
    }

    /*
    The std::weak_ptr<T>::lock() method in C++ creates a new std::shared_ptr that shares 
    ownership of the managed object. 

If the std::weak_ptr is empty (i.e., there is no managed object), the returned std::shared_ptr is also empty.
Otherwise, it constructs a std::shared_ptr pointing to the same object as the std::weak_ptr.
In other words, lock() provides a safe way to access the resource if it’s still valid,
 returning an empty std::shared_ptr if the resource has been deleted or is no longer valid
    
    */

    // Release the shared_ptr (object will be destroyed if no other shared_ptrs hold it)
    sharedPtr.reset();

    // Check weak_ptr validity again
    if (weakPtr.expired()) {
        std::cout << "Weak pointer is expired." << std::endl;
    } else {
        std::cout << "Weak pointer is still valid." << std::endl;
    }

    return 0;
}

/*

We create a std::shared_ptr (sharedPtr) to an instance of MyClass.
Then, we create a std::weak_ptr (weakPtr) from the sharedPtr.
We check if the weakPtr is expired (i.e., if the object has been deleted).
If the weakPtr is still valid, we access the object through it using weakPtr.lock().
Finally, we release the sharedPtr, and the object is destroyed since no other shared pointers hold it.
Remember that std::weak_ptr is useful when you want to avoid circular references
 and break strong ownership cycles. It allows you to safely observe objects without
  keeping them alive indefinitely



*/


#endif

#if 0

#include <iostream>
#include <memory>

class Parent {
public:
    // ...
};

class Child {
public:
    std::weak_ptr<Parent> parentWeakPtr_;
    // ...
};

int main() {
    // Create a shared_ptr to a Parent object
    std::shared_ptr<Parent> parentSharedPtr = std::make_shared<Parent>();

    // Create a Child object
    Child child;

    // Set the weak_ptr in the Child to the shared_ptr of the Parent
    child.parentWeakPtr_ = parentSharedPtr; // Automatic conversion from shared to weak

    // Now let's simulate some actions:
    // 1. Parent is still valid
    // 2. Child accesses its parent (without owning it)
    // 3. Parent is deleted
    parentSharedPtr.reset(); // Simulating parent deletion

    // Check if the weak_ptr is still valid
    if (auto parent = child.parentWeakPtr_.lock()) {
        std::cout << "Child accessed parent: " << /* Use parent data here */ << std::endl;
    } else {
        std::cout << "Parent is no longer valid." << std::endl;
    }

    return 0;
}


#endif