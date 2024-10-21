#if 1


/*

key concepts

what do you want to do in a thread.... raw thread or async
Mutex: To protect shared data (e.g., the simulation results).
Condition Variable: To notify when a component's state has changed, allowing dependent components to re-evaluate.
Semaphore: To manage access to limited resources (e.g., a limited number of simulation threads).


*/

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
    std::thread t1(task1, "Hello from thread 1!");  //consider using jthread if using c++20 automatically joinable..
    std::thread t2(task2, 42);

    // Do other work in the main thread...

    // Wait for both threads to finish
    t1.join();
    t2.join();

    return 0;
}


#endif