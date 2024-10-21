#if 0

#include <iostream>
#include <thread> // Include the <thread> header for std::thread

// Function to be executed by the first thread
void task1(std::string msg) {
    std::cout << "Task 1 says: " << msg << std::endl;
}

// Function to be executed by the second thread
void task2(int value) {
    std::cout << "Task 2 received value: " << value << std::endl;
}

int main() {
    // Create two threads
    std::thread t1(task1, "Hello from thread 1!");
    std::thread t2(task2, 42);

    // Do other work in the main thread...

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}


#endif


#if 1

#include <iostream>
#include <thread>

int x = 0; // Shared variable

void incrementX() {
    for (int i = 0; i < 1000000; ++i) {
        // Race condition: Both threads can access 'x' simultaneously
        x = x + 1;
    }
}

int main() {
    std::thread t1(incrementX);
    std::thread t2(incrementX);

    t1.join();
    t2.join();

    std::cout << "Final value of x: " << x << std::endl;
    return 0;
}


#endif



#if 1
//To prevent race conditions, you would typically use synchronization mechanisms like mutexes or locks to
// ensure that only one thread accesses the shared data at a time. For example, protecting the access
// to x with a mutex would avoid the race condition:


/*

The std::lock_guard is a lightweight mutex wrapper in C++. 
It provides an easy-to-use RAII-style mechanism for owning a
 mutex within a scoped block. 

When we create a lock_guard object, it attempts to take ownership of the given mutex.
The mutex is automatically released when the lock_guard object goes out of scope 
(e.g., at the end of the block or function).

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>


//std::atomic<int> counter(0);
int counter;
std::mutex mtx; // Mutex to protect access to x
/*
A thread owns a mutex from the time it successfully calls either lock or
 try_lock until it calls unlock.
The mutex prevents other threads
 from acquiring it while it’s locked.

*/
void incrementX() {
    for (int i = 0; i < 1000000; ++i) {

        
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        counter++;
                
    }
    
}

void decrementX() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        counter--;
    }
}

int main() {
    

    //incrementX();
    //decrementX();
    
    std::thread t1(incrementX);
    std::thread t2(decrementX);
    t1.join();
    t2.join();
    std::cout << "Final value of x (with mutex): " << counter << std::endl;
    return 0;
}


#endif