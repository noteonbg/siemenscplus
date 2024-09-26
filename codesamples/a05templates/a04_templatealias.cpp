#include <iostream>
#include <utility>


#if 1
// Template alias for a pair of ints
template<typename T>
using Pair = std::pair<T, T>;

int main() {
    Pair<int> p = {1, 2};
    std::cout << "First: " << p.first << ", Second: " << p.second << std::endl; // Output: First: 1, Second: 2
    return 0;
}

#endif

#if 1

#include <vector>
#include <map>
#include <string>
#include <iostream>

// Template alias for a vector of strings
using StringVector = std::vector<std::string>;

// Template alias for a map with string keys and integer values
using StringIntMap = std::map<std::string, int>;

int main() {
    StringVector sv = {"Hello", "World"};
    for (const auto& str : sv) {
        std::cout << str << " "; // Output: Hello World 
    }
    std::cout << std::endl;

    StringIntMap sim = {{"one", 1}, {"two", 2}};
    for (const auto& pair : sim) {
        std::cout << pair.first << ": " << pair.second << " "; // Output: one: 1 two: 2 
    }
    std::cout << std::endl;

    return 0;
}


#endif
