#include <iostream>
#include <map>
#include <string>


#if 1
class Task {
public:
    int taskId;
    std::string status;
    std::string name;

    Task(int id, const std::string& stat, const std::string& n) 
        : taskId(id), status(stat), name(n) {}

    void display() const {
        std::cout << "Task ID: " << taskId 
                  << ", Name: " << name 
                  << ", Status: " << status << std::endl;
    }
};

int main() {
    // Create a map to hold TaskId and Task
    std::map<int, Task> taskMap;

    // Adding tasks to the map
    taskMap.emplace(1, Task(1, "Pending", "Task 1"));
    taskMap.emplace(2, Task(2, "In Progress", "Task 2"));
    taskMap.emplace(3, Task(3, "Completed", "Task 3"));

    // Displaying the tasks
    for (const auto& pair : taskMap) {
        pair.second.display();
    }

    // Example of accessing a specific task by TaskId
    int taskIdToFind = 2;
    auto it = taskMap.find(taskIdToFind);
    if (it != taskMap.end()) {
        std::cout << "Found task with ID " << taskIdToFind << ":" << std::endl;
        it->second.display();
    } else {
        std::cout << "Task with ID " << taskIdToFind << " not found." << std::endl;
    }

    return 0;
}

#endif

#if 0

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class Task {
public:
    int taskId;
    std::string status;
    std::string name;
    std::string componentType; // Added for electronics context

    Task(int id, const std::string& stat, const std::string& n, const std::string& type) 
        : taskId(id), status(stat), name(n), componentType(type) {}

    void display() const {
        std::cout << "Task ID: " << taskId 
                  << ", Name: " << name 
                  << ", Status: " << status 
                  << ", Component: " << componentType << std::endl;
    }
};

int main() {
    // Create a map to hold TaskId and Task
    std::map<int, Task> taskMap;

    // Adding tasks to the map
    taskMap.emplace(1, Task(1, "Pending", "Design PCB", "PCB"));
    taskMap.emplace(2, Task(2, "In Progress", "Assemble Components", "Assembly"));
    taskMap.emplace(3, Task(3, "Completed", "Test Resistors", "Testing"));
    taskMap.emplace(4, Task(4, "Pending", "Design Capacitor Layout", "Capacitor"));
    taskMap.emplace(5, Task(5, "In Progress", "Solder Components", "Soldering"));

    // Define a component type to filter tasks
    std::string filterComponent = "Soldering";

    // Use a lambda expression to capture the filterComponent and display relevant tasks
    std::cout << "Tasks related to " << filterComponent << ":\n";
    std::for_each(taskMap.begin(), taskMap.end(), 
        [&filterComponent](const auto& pair) {
            if (pair.second.componentType == filterComponent) {
                pair.second.display();
            }
        }
    );

    return 0;
}


#endif
