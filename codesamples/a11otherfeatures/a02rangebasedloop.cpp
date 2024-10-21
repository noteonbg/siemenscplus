#if 1

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5}; 

    // Iterate over each element in the vector
    for (const auto& num : numbers)  //observe reference being used...
     {
        std::cout << num << " ";
    }

    return 0;
}

/*




   The range-based for loop (also known as the "for-each" loop) provides a 
   cleaner syntax for iterating over elements in a container.
    It automatically handles the iteration process, making code more concise and readable.
   

Limitations of Range-Based For Loop
   - While range-based for loops are convenient, they have some limitations:
     - Forward Iteration Only:
       - Range-based for loops iterate in only one direction: forward.
       - If you need to iterate backward (e.g., from `rbegin()` to `rend()`), you cannot directly use a range-based loop.
     - No Control Over Iterators:
       - You cannot explicitly specify the iterator or control the iteration process 
       (e.g., skipping elements or stepping by a custom increment).
     - Limited to Containers with `begin()` and `end()`:
       - In C++11 through C++17, the range-based for loop had strict requirements on the container type.
       - It could only handle containers with `begin()` and `end()` member functions or free functions.
       - Custom containers without these functions were not directly compatible with range-based loops⁴.
     - Undefined Behavior for Some Containers:
       - For certain containers (e.g., `std::vector`), modifying (inserting or erasing)
        elements during iteration is undefined behavior.
    - You must be cautious when modifying containers within a range-based loop¹.

*/


#endif