#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <semaphore>

const int NUM_PATHS = 5; // Number of paths to analyze
std::vector<int> timingResults(NUM_PATHS, 0); // Shared timing results
std::mutex results_mutex; // Mutex for protecting results
std::condition_variable cv; // Condition variable for notifying updates
std::counting_semaphore<3> semaphore(3); // Semaphore to limit number of threads

void analyzePath(int id) {
    // Simulating path analysis work
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * (id + 1)));

    // Lock the mutex to update the shared timing results
    {
        std::lock_guard<std::mutex> lock(results_mutex);
        timingResults[id] = (id + 1) * 20; // Simulate timing analysis result
        std::cout << "Path " << id << " analyzed: timing result = " << timingResults[id] << std::endl;
    }

    // Notify the monitor thread that results are updated
    cv.notify_one();
}

void monitorResults() {
    for (int i = 0; i < NUM_PATHS; ++i) {
        std::unique_lock<std::mutex> lock(results_mutex);
        cv.wait(lock, []{ return timingResults[0] != 0; }); // Wait for results to be available

        // Print the current state of the timing results
        std::cout << "Monitor: Current timing results: ";
        for (int result : timingResults) {
            std::cout << result << " ";
        }
        std::cout << std::endl;

        // Clear the results for the next analysis
        std::fill(timingResults.begin(), timingResults.end(), 0);
    }
}

int main() {
    std::vector<std::thread> threads;

    // Launching path analysis threads
    for (int i = 0; i < NUM_PATHS; ++i) {
        semaphore.acquire(); // Wait for a free slot
        threads.emplace_back([i]() {
            analyzePath(i);
            semaphore.release(); // Signal that this thread is done
        });
    }

    // Launch the monitor thread
    std::thread monitor(monitorResults);

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    monitor.join();

    return 0;
}
