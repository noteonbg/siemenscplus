#if 1

#include <iostream>
#include <vector>
#include <list>
#include <chrono>

// Generate random data
constexpr int N = 1000000;
std::vector<int> randomData(N);

void initializeRandomData() {
    for (int i = 0; i < N; ++i) {
        randomData[i] = rand() % 1000;
    }
}

// Cache-friendly vector sum
int vectorSum() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += randomData[i];
    }
    return sum;
}

// Cache-unfriendly list sum
int listSum() {
    std::list<int> myList(randomData.begin(), randomData.end());
    int sum = 0;
    for (const auto& val : myList) {
        sum += val;
    }
    return sum;
}

int main() {
    initializeRandomData();

    auto startVec = std::chrono::high_resolution_clock::now();
    int vecResult = vectorSum();
    auto endVec = std::chrono::high_resolution_clock::now();

    auto startList = std::chrono::high_resolution_clock::now();
    int listResult = listSum();
    auto endList = std::chrono::high_resolution_clock::now();

    std::cout << "Vector sum: " << vecResult << "\n";
    std::cout << "List sum: " << listResult << "\n";

    auto vecDuration = std::chrono::duration_cast<std::chrono::microseconds>(endVec - startVec);
    auto listDuration = std::chrono::duration_cast<std::chrono::microseconds>(endList - startList);

    std::cout << "Vector time: " << vecDuration.count() << " microseconds\n";
    std::cout << "List time: " << listDuration.count() << " microseconds\n";

    return 0;
}


#endif

/*
cache-friendly techniques in C++

Spatial Locality:
Arrange data in memory so that frequently accessed elements are close together.
Use contiguous memory regions (e.g., arrays or vectors) to improve cache hits.

Understand the cache line size (often 64 bytes on modern processors).
Accessing data within a cache line is faster than crossing cache lines.

Avoid Indirection:
Minimize pointer chasing or indirect access.
Directly access data whenever possible

Data Alignment:
Align data structures to cache line boundaries.
Use alignas or compiler-specific attributes to ensure proper alignment.




*/