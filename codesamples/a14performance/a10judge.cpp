#if 1
#include <iostream>
#include <vector>

void processBranchFriendly(const std::vector<int>& data) {
    // Preallocate space for the outputs
    std::vector<int> lessThanTen;
    std::vector<int> tenOrMore;

    // First pass: categorize values
    for (int value : data) {
        if (value < 10) {
            lessThanTen.push_back(value);
        } else {
            tenOrMore.push_back(value);
        }
    }

    // Process less than 10
    for (int value : lessThanTen) {
        std::cout << "Value: " << value << " is less than 10." << std::endl;
    }

    // Process 10 or more
    for (int value : tenOrMore) {
        std::cout << "Value: " << value << " is 10 or more." << std::endl;
    }
}

int main1() {
    std::vector<int> data = {1, 5, 12, 8, 20, 3};
    processBranchFriendly(data);
    return 0;
}





void processBranchUnfriendly(const std::vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] < 10) {
            std::cout << "Value: " << data[i] << " is less than 10." << std::endl;
        } else {
            std::cout << "Value: " << data[i] << " is 10 or more." << std::endl;
        }
    }
}

int main2() {
    std::vector<int> data = {1, 5, 12, 8, 20, 3};
    processBranchUnfriendly(data);
    return 0;
}


int main()
{
    main1();
    main2();
    return 0;
}




#endif