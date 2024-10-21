#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <vector>

std::counting_semaphore<3> semaphore(3); // Semaphore initialized to 3

void worker(int id) {
    std::cout << "Worker " << id << " is waiting to access the semaphore.\n";
    semaphore.acquire(); // Wait for semaphore access
    std::cout << "Worker " << id << " has accessed the semaphore.\n";
    
    // Simulate work
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * (id + 1)));
    
    std::cout << "Worker " << id << " is releasing the semaphore.\n";
    semaphore.release(); // Release semaphore access
}

int main() {
    std::vector<std::thread> workers;

    // Create 4 worker threads
    for (int i = 1; i < 5; ++i) {
        workers.emplace_back(worker, i);
    }

    // Wait for all threads to finish
    for (auto& worker : workers) {
        worker.join();
    }

    return 0;
}
