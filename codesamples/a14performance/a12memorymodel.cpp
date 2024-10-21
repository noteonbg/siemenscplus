#if 0

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x(0);
std::atomic<int> y(0);
std::atomic<int> z(0);

void thread1() {
    x.store(1, std::memory_order_relaxed);
    z.store(1, std::memory_order_release);
}

void thread2() {
    y.store(1, std::memory_order_relaxed);
    z.store(1, std::memory_order_release);
}

void checker() {
    while (z.load(std::memory_order_acquire) == 0) {
        // Wait for z to be set
    }
    if (x.load(std::memory_order_relaxed) == 1 && y.load(std::memory_order_relaxed) == 1) {
        std::cout << "Data race detected!" << std::endl;
    } else {
        std::cout << "No data race." << std::endl;
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread chk(checker);

    t1.join();
    t2.join();
    chk.join();

    return 0;
}

#endif

#if 0

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x(0);
std::atomic<int> y(0);
std::atomic<int> z(0);

void thread1() {
    x.store(1, std::memory_order_release); // Release store
    z.store(1, std::memory_order_release); // Release store
    std::cout  << "thread 1 running";
}

void thread2() {
    y.store(1, std::memory_order_release); // Release store
    z.store(1, std::memory_order_release); // Release store
    std::cout  << "thread  running";
}

void checker() {
    while (z.load(std::memory_order_acquire) == 0) {
        // Wait for z to be set
    }
    
    // Now we can safely load x and y
    int x_value = x.load(std::memory_order_acquire); // Acquire load
    int y_value = y.load(std::memory_order_acquire); // Acquire load

    if (x_value == 1 && y_value == 1) {
        std::cout << "Both x and y are 1: Data race detected!" << std::endl;
    } else {
        std::cout << "No data race: x = " << x_value << ", y = " << y_value << std::endl;
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread chk(checker);

    t1.join();
    t2.join();
    chk.join();

    return 0;
}

#endif

#if 1
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>

std::atomic<int> x(0);
std::atomic<int> y(0);
std::atomic<int> z(0);
std::atomic<int> flag(0);

void thread1() {
    x.store(1, std::memory_order_relaxed); // Relaxed store
    flag.store(1, std::memory_order_release); // Release store
}

void thread2() {
    y.store(1, std::memory_order_relaxed); // Relaxed store
    flag.store(2, std::memory_order_release); // Release store
}

void checker() {
    while (flag.load(std::memory_order_acquire) == 0) {
        // Wait for flag to be set
    }
    
    // Acquire load
    int x_value = x.load(std::memory_order_acquire);
    int y_value = y.load(std::memory_order_acquire);

    if (x_value == 1 && y_value == 1) {
        std::cout << "Data race detected: Both x and y are 1!" << std::endl;
    } else {
        std::cout << "No data race: x = " << x_value << ", y = " << y_value << std::endl;
    }
    std::cout  << "\n flag out variable is"  << flag.load();
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread chk(checker);

    t1.join();
    t2.join();
    chk.join();

    return 0;
}


#endif

/*

memory_order_relaxed: No synchronization or ordering guarantees.
memory_order_consume: Guarantees that dependent loads see the correct values.
 (Less commonly used due to complexity).

memory_order_acquire: Ensures visibility of all previous operations 
before this point.

memory_order_release: Ensures that all previous writes in the thread become visible 
to other threads performing an acquire.

memory_order_acq_rel: Combines acquire and release semantics.

memory_order_seq_cst: Provides a total ordering of operations 
across threads.


*/