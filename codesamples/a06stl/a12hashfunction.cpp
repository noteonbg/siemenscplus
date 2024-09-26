#if 0

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map with string keys and integer values
    std::unordered_map<std::string, int> myMap;

    // Using std::hash to hash a string
    std::hash<std::string> hashFunction;

    std::string key = "example";
    size_t hashValue = hashFunction(key);

    std::cout << "Hash value for \"" << key << "\": " << hashValue << std::endl;

    // Adding some values to the unordered_map
    myMap["example"] = 1;
    myMap["test"] = 2;

    // Accessing the value using the key
    std::cout << "Value for \"example\": " << myMap["example"] << std::endl;

    return 0;
}

#endif

#if 0

#include <iostream>
#include <unordered_set>
#include <functional>

struct Point {
    int x, y;

    // You can also define equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Custom hash function for Point
namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y); // XOR the hashes of x and y
        }
    };
}

int main() {
    std::unordered_set<Point> pointSet;

    Point p1 = {1, 2};
    Point p2 = {3, 4};

    pointSet.insert(p1);
    pointSet.insert(p2);

    std::cout << "Number of unique points: " << pointSet.size() << std::endl;

    return 0;
}


#endif