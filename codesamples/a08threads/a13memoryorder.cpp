/*

memory_order_relaxed: Use when atomicity is needed, but no specific order between threads is required 
(e.g., incrementing a task counter).


memory_order_consume: Generally used for consuming values where subsequent operations depend
 on the consumed value 

memory_order_acquire: Use when a thread needs to acquire a resource before performing
 further actions (e.g., reading a state after checking readiness).

memory_order_release: Used when a thread updates a resource and needs to signal other
 threads about the update.

memory_order_acq_rel: Combines acquire and release; useful when both reading and writing to
 shared variables atomically.

memory_order_seq_cst: Ensures a strict global order of operations,
 making it easier to reason about thread interactions
  but potentially reducing performance.



*/


#if 0

#include <iostream>
#include <thread>
#include <atomic>

/*

 counter for the number of completed tasks that does not require synchronization between threads.

*/

std::atomic<int> taskCounter(0); // Shared counter

void worker() {
    for (int i = 0; i < 100; ++i) {
        taskCounter.fetch_add(1, std::memory_order_relaxed); // Increment counter without synchronization
    }
}

int main() {
    std::thread threads[10];
    for (auto& t : threads) {
        t = std::thread(worker);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Total completed tasks: " << taskCounter.load(std::memory_order_relaxed) << std::endl;
    return 0;
}


#endif


#if 0
//. memory_order_consume
Scenario: A task queue where a worker consumes tasks produced by another thread

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>

std::atomic<int> task(0);
std::atomic<bool> ready(false);

void producer() {
    task.store(42, std::memory_order_relaxed); // Produce a task
    ready.store(true, std::memory_order_release); // Indicate task is ready
}

void consumer() {
    while (!ready.load(std::memory_order_consume)); // Wait for task readiness
    std::cout << "Consumed task: " << task.load(std::memory_order_relaxed) << std::endl; // Consume task
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();
    return 0;
}




#endif

#if 0

//memory_order_acquire
//Scenario: A manufacturing control system where a worker must acquire a lock before reading shared resource state.

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<int> resourceState(0); // Shared resource state
std::atomic<bool> isReady(false);

void worker() {
    while (!isReady.load(std::memory_order_acquire)); // Acquire readiness
    std::cout << "Resource state: " << resourceState.load(std::memory_order_relaxed) << std::endl; // Read state
}

void prepareResource() {
    resourceState.store(1, std::memory_order_relaxed); // Update resource state
    isReady.store(true, std::memory_order_release); // Notify readiness
}

int main() {
    std::thread prep(prepareResource);
    std::thread work(worker);

    prep.join();
    work.join();
    return 0;
}





#endif

#if 0
//memory_order_release A worker updates a shared variable and releases it for others to see.

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> result(0);
std::atomic<bool> ready(false);

void worker() {
    int temp = 5; // Do some calculations
    result.store(temp, std::memory_order_release); // Store result
    ready.store(true, std::memory_order_release); // Signal readiness
}

void consumer() {
    while (!ready.load(std::memory_order_acquire)); // Wait for readiness
    std::cout << "Result: " << result.load(std::memory_order_relaxed) << std::endl; // Read result
}

int main() {
    std::thread prod(worker);
    std::thread cons(consumer);

    prod.join();
    cons.join();
    return 0;
}



#endif

#if 0
//memory_order_acq_rel
//Scenario: A worker increments a shared counter and then reads another shared variable atomically.
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);
std::atomic<int> state(0);

void worker() {
    counter.fetch_add(1, std::memory_order_acq_rel); // Increment with acquire-release
    int currentState = state.load(std::memory_order_relaxed); // Read state
    std::cout << "Counter: " << counter.load() << ", State: " << currentState << std::endl;
}

void prepare() {
    state.store(1, std::memory_order_relaxed); // Update state
}

int main() {
    std::thread prep(prepare);
    std::thread work(worker);

    prep.join();
    work.join();
    return 0;
}


#endif

#if 1
//memory_order_seq_cst
//Scenario: Ensuring a strict sequence of operations in a critical manufacturing control system.

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> value(0);

void worker1() {
    
    value.store(13,std::memory_order_relaxed);
}

void worker2() {
    
    int v = value.load(std::memory_order_seq_cst); // Load value
    std::cout << "Worker 2 read value: " << v << std::endl;
}

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);

    t1.join();
    t2.join();
    return 0;
}




#endif

