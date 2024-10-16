#include <iostream>
#include <atomic>
#include <thread>

/*

memory orderings provided by  std::atomic library.

memory_order_relaxed:
This is the most relaxed memory order.
No synchronization or ordering constraints are imposed.
Reads and writes can be reordered freely.

memory_order_acquire:
Ensures that all previous reads and writes in the current thread are visible 
before subsequent reads.
Useful for acquiring data from other threads.


atomic<int> x(0);
int value = x.load(memory_order_acquire);

memory_order_release
atomic<int> x(0);
x.store(42, memory_order_release);


memory_order_acq_rel (Acquire-Release):
Combines acquire and release semantics.
Ensures both visibility of previous writes and 
ordering of subsequent writes.

atomic<int> x(0);
int value = x.exchange(42, memory_order_acq_rel);

explore other 

*/

#if 1

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

const int NUM_THREADS = 5; // Number of threads
const int INCREMENTS_PER_THREAD = 1000; // Increments per thread

std::atomic<int> counter(0); // Atomic variable for counter

void incrementCounter() {
    for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) {
        ++counter; // Atomic increment
    }
}

int main() {
    std::vector<std::thread> threads;

    // Launch multiple threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(incrementCounter);
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Output the final value of the counter
    std::cout << "Final counter value: " << counter.load() << std::endl;

    return 0;
}

#endif


#if 0

#include <iostream>
#include <atomic> // Include the <atomic> header for std::atomic

int main() {
    std::atomic<int> counter(0); // Create an atomic integer

    // Increment the counter atomically
    counter.fetch_add(1, std::memory_order_relaxed);

    // Read the counter value atomically
    int value = counter.load(std::memory_order_relaxed);

    std::cout << "Counter value: " << value << std::endl;



    return 0;
}



/*
The memory order (e.g., std::memory_order_relaxed) specifies
 how memory accesses are synchronized between threads.



*/

#if 0

#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counter.fetch_add(1, memory_order_relaxed);
    }
}

int main() {
    thread t1(incrementCounter);
    thread t2(incrementCounter);
    t1.join();
    t2.join();
    cout << "Counter value: " << counter.load(memory_order_relaxed) << endl;
    return 0;
}
// Output: Counter value: 20000

/*

Atomic operations allow concurrent read/write/access on atomic objects
 without causing data races or undefined behavior.

*/

#endif

#if 0

#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

atomic<int> x(0), y(0);
int res1, res2;

//Guarantees that instructions execute in the same order as in the source code.

void thread1() {
    x.store(1, memory_order_seq_cst);
    res1 = y.load(memory_order_seq_cst);
}

void thread2() {
    y.store(1, memory_order_seq_cst);
    res2 = x.load(memory_order_seq_cst);
}

int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    cout << "res1: " << res1 << endl;
    cout << "res2: " << res2 << endl;
}
// Output: res1: 0, res2: 1


#endif

#if 0

#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

atomic<int> x(0), y(0);

void wr() {
    x.store(1, memory_order_relaxed);
    y.store(1, memory_order_relaxed);
}

void rd() {
    while (y.load(memory_order_relaxed) != 1) {
        // Wait until y is set to 1
    }
    // Read y
}


/*
Types:

memory_order_relaxed, memory_order_consume, 
memory_order_acquire, memory_order_release, 
memory_order_acq_rel, and memory_order_seq_cst.



*/
#endif



/*

memory_order_relaxed:
This is the most relaxed memory order.
No synchronization or ordering constraints are imposed.
Reads and writes can be reordered freely.


#if 0
atomic<int> x(0);
x.store(42, memory_order_relaxed);
int value = x.load(memory_order_relaxed);
#endif


/*
memory_order_acquire:
Ensures that all previous reads and writes in the current thread are visible before subsequent reads.
Useful for acquiring data from other threads.
*/

#if 0
atomic<int> x(0);
int value = x.load(memory_order_acquire);

#endif

/*
memory_order_release
atomic<int> x(0);
x.store(42, memory_order_release);

Ensures that all subsequent reads and writes in the current
 thread are visible after previous writes.
Useful for releasing data to other threads.



memory_order_acq_rel (Acquire-Release):
Combines acquire and release semantics.
Ensures both visibility of previous writes and 
ordering of subsequent writes.

atomic<int> x(0);
int value = x.exchange(42, memory_order_acq_rel);memory_order_seq_cst (Sequential Consistency):


Strongest memory order.
Guarantees sequential consistency across all threads.
atomic<int> x(0), y(0);
x.store(1, memory_order_seq_cst);
int value = y.load(memory_order_seq_cst);





*/


#endif

#if 0

#include <iostream>
#include <atomic>

class Counter {
public:
    Counter() : count(0) {}

    void increment() {
        count.fetch_add(1, std::memory_order_relaxed);
    }

    int get() const {
        return count.load(std::memory_order_relaxed);
    }

private:
    std::atomic<int> count;
};

int main() {
    Counter myCounter;

    // Increment the counter in multiple threads
    constexpr int numThreads = 4;
    std::thread threads[numThreads];
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(&myCounter {
            for (int j = 0; j < 100000; ++j) {
                myCounter.increment();
            }
        });
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    std::cout << "Final count: " << myCounter.get() << std::endl;

    return 0;
}


#endif