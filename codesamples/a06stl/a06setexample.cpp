#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {6, 10, 5, 1}; // Defining a set with values
    for (const auto& val : mySet) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    return 0;
}


#if 0

#include <iostream>
#include <set>

class Point2D {
public:
    Point2D(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Define the comparison operator for sorting
    bool operator<(const Point2D& other) const {
        return x < other.x;
    }

private:
    int x;
    int y;
};

int main() {
    std::set<Point2D> pointSet;

    // Insert some Point2D objects
    pointSet.insert(Point2D(2, 3));
    pointSet.insert(Point2D(5, 1));
    pointSet.insert(Point2D(3, 4));

    // Print the sorted Point2D objects
    for (const auto& point : pointSet) {
        std::cout << "Point (" << point.getX() << ", " << point.getY() << ")\n";
    }

    return 0;
}



#endif