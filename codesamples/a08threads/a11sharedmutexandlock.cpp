#if 0


#include <iostream>
#include <shared_mutex>
#include <thread>

/*

A std::shared_mutex allows multiple threads to share read-only access to a resource while ensuring exclusive access for writing.
It’s useful when many threads need read-only access to the same data structure, but write operations are infrequent.

*/

std::shared_mutex sharedMutex;

//shared mutex and demonstrate both shared (read) and exclusive (write) locks.
int sharedData = 0;

void readData() {
    std::shared_lock<std::shared_mutex> lock(sharedMutex);
    std::cout << "Thread " << std::this_thread::get_id() << ": Shared data = " << sharedData << "\n";
}

void writeData(int newValue) {
    std::unique_lock<std::shared_mutex> lock(sharedMutex);
    sharedData = newValue;
    std::cout << "Thread " << std::this_thread::get_id() << ": Updated shared data to " << sharedData << "\n";
}

int main() {
    std::thread reader1(readData);
    std::thread reader2(readData);
    std::thread writer(writeData, 42);

    reader1.join();
    reader2.join();
    writer.join();

    return 0;
}


#endif


#if 0

#include <iostream>
#include <shared_mutex>
#include <vector>

std::vector<int> data = {1, 2, 3, 4, 5};
std::shared_mutex dataMutex;

void readData() {
    std::shared_lock<std::shared_mutex> lock(dataMutex);
    for (const auto& value : data) {
        std::cout << value << " ";
    }
    std::cout << "\n";
}

int main() {
    std::thread reader1(readData);
    std::thread reader2(readData);

    reader1.join();
    reader2.join();

    return 0;
}

/*

Multiple threads can acquire shared locks simultaneously, but only one thread can acquire an exclusive lock at a time.
Use shared locks for read-only access and unique locks for write access.


*/


#endif

#if 0

#include <iostream>
#include <thread>
#include <shared_mutex>

class HardwareConfiguration {
public:
    void readConfig() {
        std::shared_lock<std::shared_mutex> lock(configMutex);
        std::cout << "Reading hardware configuration...\n";
        // Simulate reading from the configuration data
    }

    void updateConfig(const std::string& newConfig) {
        std::unique_lock<std::shared_mutex> lock(configMutex);
        // Simulate updating the configuration data
        configData = newConfig;
        std::cout << "Updated hardware configuration: " << configData << "\n";
    }

private:
    std::string configData; // Simulated hardware configuration data
    std::shared_mutex configMutex; // Shared mutex for concurrent access
};

int main() {
    HardwareConfiguration hardware;

    // Simulate multiple threads accessing the hardware configuration
    std::thread reader1(&HardwareConfiguration::readConfig, &hardware);
    std::thread reader2(&HardwareConfiguration::readConfig, &hardware);
    std::thread writer([&hardware] {
        hardware.updateConfig("New settings");
    });

    reader1.join();
    reader2.join();
    writer.join();

    return 0;
}


#endif

