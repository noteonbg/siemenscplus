#if 0

#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

const int SIZE = 1000;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create a 2D vector of size 1000x1000
    std::vector<std::vector<int>> matrix(SIZE, std::vector<int>(SIZE));

    // Fill the array with random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = std::rand() % 100; // Random number between 0 and 99
        }
    }

    // Print the array
    for (int i = 0; i < SIZE; i++) {
        int k =0;
        for (int j = 0; j < SIZE; j++) {
            //std::cout << matrix[i][j] << " "; // Print each element
            k=matrix[i][j];

        }
        
    }

    return 0;
}

#endif

#if 1

#include <iostream>
#include <array>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

const int SIZE = 1000;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create a 2D array of size 1000x1000 using std::array
    std::array<std::array<int, SIZE>, SIZE> matrix;

    // Fill the array with random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = std::rand() % 100; // Random number between 0 and 99
        }
    }

    // Print the array
    for (int i = 0; i < SIZE; i++) {
        int k =0;
        for (int j = 0; j < SIZE; j++) {
           // std::cout << matrix[i][j] << " "; // Print each element
           k=matrix[i][j];
        }
        
    }

    return 0;
}


#endif