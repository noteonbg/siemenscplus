#if 0

#include <iostream>
#include <span>
#include <vector>

void printSpan(std::span<int> s) {
    for (int value : s) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Create a span from the vector
    std::span<int> mySpan(vec.data(), vec.size());

    printSpan(mySpan);  // Output: 1 2 3 4 5

    // Create a subspan
    std::span<int> subSpan = mySpan.subspan(1, 3);  // Elements 2, 3, 4
    printSpan(subSpan);  // Output: 2 3 4

    return 0;
}

#endif

#if 0

#include <iostream>
#include <span>
#include <vector>

// Function to calculate the sum of elements in a span
int calculateSum(std::span<int> data) {
    int sum = 0;
    for (int value : data) {
        sum += value;
    }
    return sum;
}

int main() {
    // Example with a raw array
    int arr[] = {1, 2, 3, 4, 5};
    std::span<int> spanFromArray(arr);
    std::cout << "Sum of array elements: " << calculateSum(spanFromArray) << std::endl;

    // Example with a std::vector
    std::vector<int> vec = {6, 7, 8, 9, 10};
    std::span<int> spanFromVector(vec);
    std::cout << "Sum of vector elements: " << calculateSum(spanFromVector) << std::endl;

    // Example with part of an array
    std::span<int> partialSpan(arr, 3); // First three elements of arr
    std::cout << "Sum of first three array elements: " << calculateSum(partialSpan) << std::endl;

    // Example with part of a vector



#endif

/*


Non-owning Reference: std::span does not assume ownership of the data it refers to. It acts as a wrapper around the existing data.
Lightweight: std::span is designed to be efficient, employing a small memory footprint. Typically, it consists of two pointers (begin and end) and a size value.
Contiguous Sequence: std::span is compatible only with contiguous data structures such as arrays, std::vector, or std::array. It cannot be utilized with non-contiguous data structures like linked lists.
Safety Measures: std::span incorporates bounds checking,
 ensuring secure access to the underlying data. 
 It helps prevent common errors such as buffer overflows or underflows.

No Overhead: std::span does not manage memory, so it has zero overhead compared to raw pointers. It provides a view into existing data without requiring any additional copies.
Efficient Access: Since std::span provides direct access to elements,
 you can benefit from performance similar to that of raw arrays 
 while maintaining better abstraction.

Simplicity and Safety
Avoids Pointer Arithmetic: std::span abstracts away the
 need for manual pointer arithmetic, making code
  easier to read and less error-prone.

Bounds Checking: While std::span itself does not perform bounds
 checking by default, it provides member functions like at() that do, enhancing safety when accessing elements.

2. Flexibility
Variety of Input Types:
 std::span can be constructed from various containers (like std::array, std::vector, C-style arrays, etc.), which allows for flexible APIs that accept different data structures without needing to overload functions.

Subranges: You can create subranges easily, which is useful for working with parts of a container without copying data.

3. Performance
No Overhead: std::span does not manage memory, so it has zero
 overhead compared to raw pointers. It provides a view into existing data without requiring any additional copies.

Efficient Access: Since std::span provides direct access to elements, you can benefit from performance similar to that of raw arrays while maintaining better abstraction.

4. Improved Code Clarity
Clearer Intent: Using std::span makes it explicit that you are working with a view into a sequence, improving the readability of your code.
Function Signatures: Functions that accept std::span can indicate that they operate on a sequence of elements without owning them, making the API clearer.

5. Interoperability with Standard Algorithms
Integration with STL: std::span works seamlessly with standard algorithms. You can use it as a range in algorithms that accept iterators, enhancing the expressiveness of your code.







*/