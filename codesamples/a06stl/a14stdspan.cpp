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