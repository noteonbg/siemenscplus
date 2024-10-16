#include <iostream>
#include <tuple>

// A simple Tuple class using variadic templates
template <typename... Types>
class SimpleTuple;

// Base case: empty tuple
template <>
class SimpleTuple<> {};

// Recursive case: non-empty tuple
template <typename Head, typename... Tail>
class SimpleTuple<Head, Tail...> : public SimpleTuple<Tail...> {
public:
    SimpleTuple(Head head, Tail... tail) : SimpleTuple<Tail...>(tail...), head_(head) {}

    void print() const {
        std::cout << head_ << " ";
        SimpleTuple<Tail...>::print(); // Call print on the tail
    }

private:
    Head head_;
};

// Overload for the empty tuple
template <>
void SimpleTuple<>::print() const {
    std::cout << "(empty tuple)";
}

int main() {
    SimpleTuple<int, double, std::string> myTuple(1, 3.14, "Hello");
    myTuple.print(); // Output: 1 3.14 Hello 
    return 0;
}
