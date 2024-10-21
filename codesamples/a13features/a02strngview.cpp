#if 0

#include <iostream>
#include <string_view>

void printSV(std::string_view str) {
    std::cout << str << '\n';
}

int main() {
	
	/*
	std::string_view in C++ is a lightweight, non-owning view of a string. no memory
allocation..	
	*/
    std::string_view s1 = "Hello, world!"; // Initialize with a C-style string literal
    printSV(s1);

    std::string s = "Hello, world!";
    std::string_view s2 = s; // Initialize with a std::string
    printSV(s2);

    return 0;
}


#endif