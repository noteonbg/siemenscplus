#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <chrono>
#include <semaphore>

std::mutex mtx;
std::condition_variable cv_material, cv_inspection;
std::queue<int> rawMaterials;        // Queue for raw materials
std::queue<int> inspectedComponents;  // Queue for inspected components
std::counting_semaphore<5> availableMaterials(0); // Semaphore for raw materials
std::counting_semaphore<5> availableInspected(0); // Semaphore for inspected components

// Raw Material Processor
void produceMaterials(int id) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 200 + 100)); // Simulate production time
        {
            std::lock_guard<std::mutex> lock(mtx);
            rawMaterials.push(i); // Add raw material
            std::cout << "Machine " << id << " produced raw material " << i << ".\n";
        }
        availableMaterials.release(); // Signal that raw material is available
        cv_material.notify_one();      // Notify inspector
    }
}

// Quality Inspector
void inspectComponents(int id) {
    for (int i = 0; i < 10; ++i) {
        availableMaterials.acquire(); // Wait for raw materials to be available
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!rawMaterials.empty()) {
                int material = rawMaterials.front();
                rawMaterials.pop();
                std::cout << "Inspector " << id << " is inspecting raw material " << material << ".\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 150 + 50)); // Simulate inspection time
        {
            std::lock_guard<std::mutex> lock(mtx);
            inspectedComponents.push(i); // Add inspected component
            std::cout << "Inspector " << id << " completed inspection of material. Inspected component: " << i << ".\n";
        }
        availableInspected.release(); // Signal that inspected component is available
        cv_inspection.notify_one();    // Notify assembler
    }
}

// Assembler
void assembleProducts(int id) {
    for (int i = 0; i < 10; ++i) {
        availableInspected.acquire(); // Wait for inspected components to be available
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!inspectedComponents.empty()) {
                int component = inspectedComponents.front();
                inspectedComponents.pop();
                std::cout << "Assembler " << id << " is assembling product from inspected component " << component << ".\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 250 + 100)); // Simulate assembly time
        std::cout << "Assembler " << id << " completed assembly of product from component " << i << ".\n";
    }
}

int main() {
    std::srand(std::time(nullptr)); // Seed for random number generation

    // Create threads for machines
    std::thread materialProducer(produceMaterials, 1);
    std::thread inspector(inspectComponents, 1);
    std::thread assembler(assembleProducts, 1);

    // Join threads
    materialProducer.join();
    inspector.join();
    assembler.join();

    return 0;
}
