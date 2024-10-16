#include <iostream>
#include <span>
#include <vector>
#include <string>

// A simple Task class with a name and a status
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

void printTasks(std::span<Task> tasks) {
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
        Task("Clean the house", true)
    };

    // Use std::span to view a subset of tasks from the vector
    std::span<Task> spanTasks(taskList);

    // Print all tasks
    std::cout << "All tasks:" << std::endl;
    printTasks(spanTasks);

    // Let's now use std::span to view only the first 3 tasks
    std::span<Task> subsetSpan(spanTasks.subspan(0, 3));

    std::cout << "\nFirst three tasks:" << std::endl;
    printTasks(subsetSpan);

    // Mark the first task in the subset as completed
    subsetSpan[0].markCompleted();

    std::cout << "\nAfter marking the first task as completed:" << std::endl;
    printTasks(subsetSpan);

    return 0;
}
