#if 0

#include <iostream>
#include <utility>

template <typename T, T... Ints>
struct integer_sequence {
    // Optional: You can add member functions or use it directly in templates
};

// Helper function to print the sequence
template <typename T, T... Is>
void print_sequence(integer_sequence<T, Is...>) {
    ((std::cout << Is << ' '), ...); // Fold expression to print the sequence
}

int main() {
    // Create an integer sequence from 1 to 10
    print_sequence(integer_sequence<int, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>{});
    return 0;
}


#endif

#if 1

template <typename T, T... Ints>
struct integer_sequence_size;

// Partial specialization for non-empty integer_sequence
template <typename T, T Head, T... Tail>
struct integer_sequence_size<T, Head, Tail...> {
    static constexpr size_t value = 1 + integer_sequence_size<T, Tail...>::value;
};

// Specialization for an empty integer_sequence
template <typename T>
struct integer_sequence_size<T> {
    static constexpr size_t value = 0;
};

int main() {
    // Define an integer_sequence
    using my_sequence = integer_sequence<int, 0, 1, 2, 3, 4>;

    // Print the size of the integer_sequence
    std::cout << "Size: " << integer_sequence_size<int, 0, 1, 2, 3, 4>::value << '\n';
    // Output: Size: 5

    return 0;
}



#endif