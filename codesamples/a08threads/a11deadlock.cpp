#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex toolA;
std::mutex toolB;

void machineA();
void machineB();

#if 1
void machineA() {
    std::cout << "Machine A: Trying to acquire Tool A...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

    std::cout << "Machine A: Acquired Tool A. Trying to acquire Tool B...\n";
    toolA.lock(); // Lock Tool A
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

    toolB.lock(); // Lock Tool B
    std::cout << "Machine A: Acquired Tool B!\n";

    // Release locks
    toolB.unlock();
    toolA.unlock();
}

void machineB() {
    std::cout << "Machine B: Trying to acquire Tool B...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

    std::cout << "Machine B: Acquired Tool B. Trying to acquire Tool A...\n";
    toolB.lock(); // Lock Tool B
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

    toolA.lock(); // Lock Tool A
    std::cout << "Machine B: Acquired Tool A!\n";

    // Release locks
    toolA.unlock();
    toolB.unlock();
}

#endif

int main() {
    std::thread t1(machineA);
    std::thread t2(machineB);

    t1.join();
    t2.join();

    return 0;
}

#if 0

void machineA() {
    std::cout << "Machine A: Trying to acquire Tool A...\n";
    toolA.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    
    std::cout << "Machine A: Acquired Tool A. Trying to acquire Tool B...\n";
    toolB.lock(); // Now acquire Tool B after Tool A
    std::cout << "Machine A: Acquired Tool B!\n";

    // Release locks
    toolB.unlock();
    toolA.unlock();
}

void machineB() {
    std::cout << "Machine B: Trying to acquire Tool A...\n";
    toolA.lock(); // Change order to match machine A
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work

    std::cout << "Machine B: Acquired Tool A. Trying to acquire Tool B...\n";
    toolB.lock();
    std::cout << "Machine B: Acquired Tool B!\n";

    // Release locks
    toolB.unlock();
    toolA.unlock();
}


#endif


/*

Two Machines: machineA and machineB represent two machines in a factory.
Two Resources: toolA and toolB represent tools that both machines need to use.
Locking Order:
machineA locks toolA first and then tries to lock toolB.
machineB locks toolB first and then tries to lock toolA.
Deadlock Scenario
If machineA successfully locks toolA and then waits for toolB, while machineB locks toolB and waits for toolA, both machines are stuck waiting for each other, leading to a deadlock.
Resolution
To prevent deadlocks, you can enforce a strict order of resource acquisition or
 use techniques like timeout locks or deadlock detection mechanisms. 
 Here's a simple adjustment to avoid deadlock by locking in a consistent order:





*/