#if 1

//Designated initializers are a feature introduced in C++20 that allow you to initialize data members of a struct or an array in any order you want. They provide a more readable and flexible way of initializing data members. Let’s look at an example:


#include <iostream>

struct Date {
    int year;
    int month;
    int day;
};

int main() {
    Date dt{ .year = 2023, .month = 4, .day = 24 };
    std::cout << "Year: " << dt.year << '\n';
    std::cout << "Month: " << dt.month << '\n';
    std::cout << "Day: " << dt.day << '\n';
    return 0;
}

#endif