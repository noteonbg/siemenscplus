#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wordFrequency;
    wordFrequency["this"] = 5;
    wordFrequency["is"] = 3;
    wordFrequency["a"] = 2;

    // Accessing values using []
    int value = wordFrequency["this"];
    std::cout << "Value of key \"this\": " << value << std::endl;

    return 0;
}



#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wordFrequency;
    wordFrequency["this"] = 5;
    wordFrequency["is"] = 3;
    wordFrequency["a"] = 2;

    // Accessing values using at()
    try {
        int val = wordFrequency.at("this");
        std::cout << "Value of key \"this\": " << val << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Key not found: " << e.what() << std::endl;
    }

    return 0;
}






#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    // Using an iterator
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}



With C++11 and later, you can use a range-based loop for a more concise syntax:

#include <iostream>
#include <map>
#include <string>

int main() {
    std::_map<std::string, int> myMap;
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    // Using range-based loop
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}



iterating thru the _MAP_


//C++17 and Later (Structured Binding):

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    // Using structured binding
    for (const auto& [key, value] : myMap) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    return 0;
}



//finding key exists or n ot


#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 3;

    // Check if "banana" exists
    if (myMap.count("banana") > 0) {
        std::cout << "Key \"banana\" exists!\n";
    } else {
        std::cout << "Key \"banana\" does not exist.\n";
    }

    return 0;
}

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 3;

    // Check if "orange" exists
    auto it = myMap.find("orange");
    if (it != myMap.end()) {
        std::cout << "Key \"orange\" exists!\n";
    } else {
        std::cout << "Key \"orange\" does not exist.\n";
    }

    return 0;
}

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 3;

    // Check if "apple" exists
    if (myMap.contains("apple")) {
        std::cout << "Key \"apple\" exists!\n";
    } else {
        std::cout << "Key \"apple\" does not exist.\n";
    }

    return 0;
}


#endif 

