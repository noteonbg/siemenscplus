#if 0

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

// Task class definition
class Task {
public:
    Task(const std::string& name, bool completed = false)
        : name_(name), completed_(completed) {}

    const std::string& getName() const { return name_; }
    bool isCompleted() const { return completed_; }

    void markCompleted() { completed_ = true; }

    // Overload the << operator for pretty printing the Task object
    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "Task: " << task.name_ << ", Status: " << (task.completed_ ? "Completed" : "Pending");
        return os;
    }

private:
    std::string name_;
    bool completed_;
};

// Function to print tasks
void printTasks(const std::ranges::range auto& tasks) {
    for (const auto& task : tasks) {
        std::cout << task << std::endl;
    }
}

int main() {
    // Create a vector of Task objects
    std::vector<Task> taskList = {
        Task("Do the laundry"),
        Task("Buy groceries", true),
        Task("Finish homework"),
        Task("Clean the house", true),
        Task("Mow the lawn"),
        Task("Read a book", true)
    };

    // 1. Print all tasks
    std::cout << "All tasks:" << std::endl;
    printTasks(taskList);

    // 2. Use ranges to filter only the pending tasks (i.e., tasks that are not completed)
    std::cout << "\nPending tasks:" << std::endl;
    auto pendingTasks = taskList | std::ranges::views::filter([](const Task& t) { return !t.isCompleted(); });
    printTasks(pendingTasks);

    // 3. Use ranges to sort tasks by name
    std::cout << "\nTasks sorted by name:" << std::endl;
    auto sortedTasks = taskList | std::ranges::views::transform([](Task& t) -> Task& { return t; }) | std::ranges::to<std::vector>();
    std::ranges::sort(sortedTasks, [](const Task& a, const Task& b) { return a.getName() < b.getName(); });
    printTasks(sortedTasks);

    // 4. Use ranges to modify the task status (mark completed for tasks that have 'Read' in the name)
    std::cout << "\nMarking tasks with 'Read' in their name as completed:" << std::endl;
    for (auto& task : taskList | std::ranges::views::filter([](Task& t) { return t.getName().find("Read") != std::string::npos; })) {
        task.markCompleted();
    }
    printTasks(taskList);

    return 0;
}


/*
std::ranges::views::filter to filter out tasks based on some criteria.
std::ranges::views::transform is used to transform elements (e.g., sorting them, or extracting only certain fields from the elements).
std::ranges::to is used to materialize a range into a container (in this case, std::vector).
The code also demonstrates sorting tasks by their names using std::ranges::sort.


Filtering tasks: We filter out only the tasks that are not completed using std::ranges::views::filter.
Sorting tasks: We sort the tasks alphabetically by their name using std::ranges::sort.
Marking specific tasks as completed: We use a filter to find tasks that have "Read" in their name, and then mark them as completed.
*/

#endif

#if 0

#include <iostream>
#include <ranges>
#include <map>
#include <string>
#include <algorithm>

// Function to print the contents of a map
template <typename Map>
void printMap(const Map& map) {
    for (const auto& [key, value] : map) {
        std::cout << key << ": " << value << std::endl;
    }
}

int main() {
    // Create a map where keys are task names and values are their completion statuses (true = completed, false = pending)
    std::map<std::string, bool> taskMap = {
        {"Do the laundry", false},
        {"Buy groceries", true},
        {"Finish homework", false},
        {"Clean the house", true},
        {"Mow the lawn", false},
        {"Read a book", true}
    };

    // 1. Print all tasks
    std::cout << "All tasks:" << std::endl;
    printMap(taskMap);

    // 2. Use ranges to filter only completed tasks
    std::cout << "\nCompleted tasks:" << std::endl;
    auto completedTasks = taskMap | std::ranges::views::filter([](const auto& pair) { return pair.second; });
    printMap(completedTasks);

    // 3. Use ranges to filter tasks with names that contain "house"
    std::cout << "\nTasks with 'house' in their name:" << std::endl;
    auto houseTasks = taskMap | std::ranges::views::filter([](const auto& pair) { return pair.first.find("house") != std::string::npos; });
    printMap(houseTasks);

    // 4. Sort the tasks by their names (keys)
    std::cout << "\nTasks sorted by name:" << std::endl;
    auto sortedTasks = taskMap | std::ranges::to<std::vector>();  // Convert map to a vector for sorting
    std::ranges::sort(sortedTasks, [](const auto& a, const auto& b) { return a.first < b.first; });
    
    // Print the sorted tasks (as a vector)
    for (const auto& [key, value] : sortedTasks) {
        std::cout << key << ": " << value << std::endl;
    }

    // 5. Transform the map's values (marking all pending tasks as completed)
    std::cout << "\nMarking all pending tasks as completed:" << std::endl;
    for (auto& [key, value] : taskMap | std::ranges::views::filter([](const auto& pair) { return !pair.second; })) {
        value = true;  // Mark as completed
    }
    printMap(taskMap);

    return 0;
}


/*

std::map Creation:

We create a std::map where the key is a std::string representing the task name, and the value is a bool representing whether the task is completed (true) or pending (false).
Filtering Completed Tasks:

We use std::ranges::views::filter to filter out only the completed tasks by checking the second value of each key-value pair.
Filtering Tasks by Name:

We filter tasks that contain the substring "house" in their name using std::ranges::views::filter and the find method on the task name.
Sorting Tasks:

We convert the std::map to a std::vector using std::ranges::to<std::vector>(), because std::map is inherently ordered by keys, but if you want to perform custom sorting operations on it, you may need to use a vector. We then sort the vector by the task names (keys) using std::ranges::sort.
Transforming Values:

We mark all pending tasks (value == false) as completed (value = true). This is done using std::ranges::views::filter to select only the pending tasks and modify their value to true.

*/

#endif