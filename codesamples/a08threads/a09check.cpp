#include <iostream>
#include <thread>
#include <map>
#include <mutex>
#include <vector>
#include <chrono>

// Shared inventory map and mutex for synchronization
std::map<std::string, int> inventory;
std::mutex inventory_mutex;

// Function for machine production
void produceItems(const std::string& machineName, const std::vector<std::pair<std::string, int>>& items) {
    for (const auto& item : items) {
        const std::string& productName = item.first;
        int quantity = item.second;

        // Simulate production time
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Lock the mutex before updating the shared inventory
        {
            std::lock_guard<std::mutex> lock(inventory_mutex);
            inventory[productName] += quantity; // Update inventory
            std::cout << machineName << " produced " << quantity << " of " << productName << ". Total: " 
                      << inventory[productName] << std::endl;
        }
    }
}

int main() {
    // Define production items for each machine
    std::vector<std::pair<std::string, int>> machine1Items = {{"Widget", 10}, {"Gadget", 5}};
    std::vector<std::pair<std::string, int>> machine2Items = {{"Widget", 20}, {"Gadget", 10}};
    std::vector<std::pair<std::string, int>> machine3Items = {{"Gadget", 15}, {"Thingamajig", 8}};

    // Create threads for each machine
    std::thread machine1(produceItems, "Machine 1", machine1Items);
    std::thread machine2(produceItems, "Machine 2", machine2Items);
    std::thread machine3(produceItems, "Machine 3", machine3Items);

    // Join threads
    machine1.join();
    machine2.join();
    machine3.join();

    // Final inventory report
    std::cout << "\nFinal Inventory Report:\n";
    {
        std::lock_guard<std::mutex> lock(inventory_mutex);
        for (const auto& [product, quantity] : inventory) {
            std::cout << product << ": " << quantity << std::endl;
        }
    }

    return 0;
}
