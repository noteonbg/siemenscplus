
#if 1

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx; // Mutex to synchronize access
std::condition_variable cv; // Condition variable

bool data_ready = false; // Flag indicating data availability

// Producer function (simulating data production)
void producer() {
    // Simulate data production (e.g., reading from a file or network)
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Lock the mutex
    std::unique_lock<std::mutex> lock(mtx);

    // Set the data_ready flag
    data_ready = true;

    std::cout << "\n data ready \n";

    // Notify the consumer
    cv.notify_one();
}

// Consumer function (waiting for data)
void consumer() {
    // Lock the mutex
    std::unique_lock<std::mutex> lock(mtx);

    // Wait until data_ready is true
    cv.wait(lock, [] { return data_ready; });

    // Data is now available
    std::cout << "Data consumed!" << std::endl;
}

int main() {
    std::thread consumer_thread(consumer);
    std::thread producer_thread(producer);

    consumer_thread.join();
    producer_thread.join();

    return 0;
}


#endif

#if 0

//Condition variables in C++ are synchronization primitives used to coordinate threads based on certain conditions.


/*

They allow one or more threads to wait until a shared resource becomes available or a specific condition is met. Let’s dive into an example:

Suppose we have a producer-consumer scenario where multiple producer threads add items to a shared queue, 
and multiple consumer threads remove items from the queue. We want to ensure that consumers wait when the 
queue is empty and producers signal when they add an item.

Producers add items to the sharedQueue.
Consumers wait using cv.wait(lock, predicate) until the queue is not empty.
When a producer adds an item, it signals a waiting consumer using cv.notify_one().
Remember to handle exceptions and edge cases in a real-world application. 
Condition variables are essential for efficient thread synchronization and avoiding busy-waiting.

*/




#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> sharedQueue;
std::mutex mtx;
std::condition_variable cv;

void producer(int id) {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            std::unique_lock<std::mutex> lock(mtx);
            sharedQueue.push(i);
            std::cout << "Producer " << id << " added item: " << i << std::endl;
        }
        cv.notify_one(); // Signal a consumer
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !sharedQueue.empty(); }); // Wait until queue is not empty
        int item = sharedQueue.front();
        sharedQueue.pop();
        std::cout << "Consumer " << id << " removed item: " << item << std::endl;
    }
}

int main() {
    const int numProducers = 2;
    const int numConsumers = 3;

    std::vector<std::thread> producers, consumers;

    for (int i = 0; i < numProducers; ++i)
        producers.emplace_back(producer, i);

    for (int i = 0; i < numConsumers; ++i)
        consumers.emplace_back(consumer, i);

    for (auto& t : producers)
        t.join();

    for (auto& t : consumers)
        t.join();

    return 0;
}


#endif

