
/*

memory orderings provided by  std::atomic library.

memory_order_relaxed:
This is the most relaxed memory order.
No synchronization or ordering constraints are imposed.
Reads and writes can be reordered freely.
Use Cases: This approach is suitable when the order of operations does not matter
 as long as the increments themselves are atomic,
  such as in counters or simple flags.


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

