#if 0

#include <iostream>
#include <vector>
#include <chrono>

const int SIZE = 1024;

void multiplyMatricesUnfriendly(const std::vector<std::vector<int>>& A, 
                                 const std::vector<std::vector<int>>& B, 
                                 std::vector<std::vector<int>>& C) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j]; // Accessing B in a column-major manner
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(SIZE, std::vector<int>(SIZE, 1));
    std::vector<std::vector<int>> B(SIZE, std::vector<int>(SIZE, 1));
    std::vector<std::vector<int>> C(SIZE, std::vector<int>(SIZE, 0));

    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatricesUnfriendly(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Cache-Unfriendly Duration: " << duration.count() << " seconds" << std::endl;

    return 0;
}

#endif

#if 1

#include <iostream>
#include <vector>
#include <chrono>

const int SIZE = 1024;

void multiplyMatricesFriendly(const std::vector<std::vector<int>>& A, 
                              const std::vector<std::vector<int>>& B, 
                              std::vector<std::vector<int>>& C) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                C[i][j] += A[i][k] * B[k][j]; // Accessing in a row-major manner
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(SIZE, std::vector<int>(SIZE, 1));
    std::vector<std::vector<int>> B(SIZE, std::vector<int>(SIZE, 1));
    std::vector<std::vector<int>> C(SIZE, std::vector<int>(SIZE, 0));

    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatricesFriendly(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Cache-Friendly Duration: " << duration.count() << " seconds" << std::endl;

    return 0;
}



#endif
