#if 1

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Check if all elements are even
    bool allEven = std::all_of(numbers.begin(), numbers.end(),  {
        return x % 2 == 0;
    });

    // Check if any element is greater than 3
    bool anyGreaterThan3 = std::any_of(numbers.begin(), numbers.end(),  {
        return x > 3;
    });

    // Check if no element is negative
    bool noneNegative = std::none_of(numbers.begin(), numbers.end(),  {
        return x < 0;
    });

    std::cout << "All even: " << allEven << "\n";
    std::cout << "Any greater than 3: " << anyGreaterThan3 << "\n";
    std::cout << "None negative: " << noneNegative << "\n";

    return 0;
}


#endif

#if 0

#include <iostream>
#include <algorithm>
#include <vector>

void printSquare(int x) {
    std::cout << x * x << " ";
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), printSquare);
    return 0;
}



#endif

#if 0

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 2, 3, 2, 4, 2, 5};

    int countTwos = std::count(numbers.begin(), numbers.end(), 2);
    std::cout << "Number of twos: " << countTwos << "\n";

    return 0;
}

#endif