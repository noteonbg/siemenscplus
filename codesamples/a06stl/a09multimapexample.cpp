#include <iostream>
#include <map>

int main() {
    // Create an empty multimap with int keys and string values
    std::multimap<int, std::string> myMultimap;

    // Insert some key-value pairs
    myMultimap.insert(std::make_pair(1, "Apple"));
    myMultimap.insert(std::make_pair(2, "Banana"));
    myMultimap.insert(std::make_pair(1, "Apricot")); // Duplicate key

    // Print the multimap
    std::cout << "Multimap contents:\n";
    for (const auto& pair : myMultimap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    }

    return 0;
}
