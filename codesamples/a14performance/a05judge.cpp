#if 0

#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <chrono>

class ArrayProcessor {
public:
    explicit ArrayProcessor(size_t size) : data_(size) {
        // Initialize the array with some values
        std::iota(data_.begin(), data_.end(), 1); // Fill with 1, 2, ..., size
    }

    long long sumOfSquares() const {
        return std::accumulate(data_.begin(), data_.end(), 0LL,
                               [](long long acc, int val) {
                                   return acc + val * val;
                               });
    }

private:
    std::vector<int> data_; // Use vector for automatic memory management
};

int main() {
    const size_t arraySize = 1'000'000; // 1 million elements
    ArrayProcessor processor(arraySize);

    auto start = std::chrono::high_resolution_clock::now();
    long long result = processor.sumOfSquares();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sum of squares: " << result << "\n";
    std::cout << "Time taken: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";

    return 0;
}


#endif

#if 1

#include <iostream>
#include <cstdlib> // for malloc and free
#include <chrono>

class ArrayProcessor {
public:
    ArrayProcessor(size_t size) {
        size_ = size;
        data_ = (int*)malloc(size_ * sizeof(int)); // Manual memory management
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = i + 1; // Fill with 1, 2, ..., size
        }
    }

    ~ArrayProcessor() {
        free(data_); // Memory leak risk if exceptions are thrown
    }

    long long sumOfSquares() const {
        long long sum = 0;
        for (size_t i = 0; i < size_; ++i) {
            sum += data_[i] * data_[i]; // Inefficient access
        }
        return sum;
    }

private:
    int* data_; // Raw pointer, risk of memory leaks
    size_t size_;
};

int main() {
    const size_t arraySize = 1'000'000; // 1 million elements
    ArrayProcessor processor(arraySize);

    auto start = std::chrono::high_resolution_clock::now();
    long long result = processor.sumOfSquares();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sum of squares: " << result << "\n";
    std::cout << "Time taken: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";

    return 0;
}



#endif