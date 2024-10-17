#if 1

#include <iostream>

class MyRange {
private:
    int start;
    int end;

public:
    MyRange(int s, int e) : start(s), end(e) {}

    class iterator {
    private:
        int value;

    public:
        iterator(int v) : value(v) {}
        int operator*() const { return value; }
        iterator& operator++() {
            ++value;
            return *this;
        }
        bool operator!=(const iterator& other) const {
            return value != other.value;
        }
    };

    iterator begin() const { return iterator(start); }
    iterator end() const { return iterator(end); }
};

int main() {
    MyRange customRange(100, 105);
    for (int val : customRange) {
        std::cout << val << ' '; // Prints 100, 101, 102, 103, 104
    }
    std::cout << '\n';
    return 0;
}


#endif