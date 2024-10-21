#if 0

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex machine; // Shared resource: machine

void highPriorityWorker() {
    for (int i = 0; i < 5; ++i) {
        machine.lock(); // Acquire machine
        std::cout << "High Priority Worker is using the machine.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        machine.unlock(); // Release machine
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Wait before next usage
    }
}

void lowPriorityWorker(int id) {
    for (int i = 0; i < 3; ++i) {
        // Attempt to acquire the machine
        if (machine.try_lock()) { // Try to acquire machine
            std::cout << "Low Priority Worker " << id << " is using the machine.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate work
            machine.unlock(); // Release machine
        } else {
            std::cout << "Low Priority Worker " << id << " could not acquire the machine.\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Wait before next attempt
    }
}

int main() {
    std::thread highWorker(highPriorityWorker);
    std::vector<std::thread> lowWorkers;

    // Create multiple low-priority workers
    for (int i = 0; i < 3; ++i) {
        lowWorkers.emplace_back(lowPriorityWorker, i + 1);
    }

    // Wait for high-priority worker to finish
    highWorker.join();

    // Wait for low-priority workers to finish
    for (auto& worker : lowWorkers) {
        worker.join();
    }

    return 0;
}


#endif

#if 1

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<std::thread::id> waitingQueue;
bool resourceInUse = false;

void fairLock() {
    std::unique_lock<std::mutex> lock(mtx);
    std::thread::id this_id = std::this_thread::get_id();
    
    // Add this thread to the waiting queue
    waitingQueue.push(this_id);
    
    // Wait until this thread is at the front of the queue
    cv.wait(lock, [this_id]() { return waitingQueue.front() == this_id && !resourceInUse; });

    // Critical section
    resourceInUse = true; // Mark the resource as in use
    std::cout << "Thread " << this_id << " is using the resource.\n";
    
    // Simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Release the resource
    resourceInUse = false;
    waitingQueue.pop(); // Remove this thread from the queue
    cv.notify_all(); // Notify all waiting threads
}

void lowPriorityWorker(int id) {
    for (int i = 0; i < 3; ++i) {
        fairLock(); // Attempt to acquire the resource
        std::cout << "Low Priority Worker " << id << " has completed its task.\n";
    }
}

void highPriorityWorker() {


    #if 0
    for (int i = 0; i < 5; ++i) {
        fairLock(); // Attempt to acquire the resource
        std::cout << "High Priority Worker is using the resource.\n";
        // Simulate longer work
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    #endif

    #if 1

    for (int i = 0; i < 5; ++i) {
        fairLock(); // Attempt to acquire the resource
        std::cout << "High Priority Worker is using the resource.\n";
        
        // Simulate longer work with time slicing
        for (int j = 0; j < 3; ++j) { // Perform work in slices
            std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate work slice
            std::cout << "High Priority Worker working...\n";
            std::this_thread::yield(); // Yield to allow other threads to run
        }

        /*
        
        Time Slicing in highPriorityWorker:
        The highPriorityWorker function now simulates its work in slices of 50 milliseconds.
        After each work slice, it calls std::this_thread::yield() to allow 
        other threads (particularly low-priority workers) to run.

        
        */
    }

    #endif
}

int main() {
    std::thread highWorker(highPriorityWorker);
    std::thread lowWorkers[3];

    // Create multiple low-priority workers
    for (int i = 0; i < 3; ++i) {
        lowWorkers[i] = std::thread(lowPriorityWorker, i + 1);
    }

    // Wait for high-priority worker to finish
    highWorker.join();

    // Wait for low-priority workers to finish
    for (auto& worker : lowWorkers) {
        worker.join();
    }

    return 0;
}


#endif



