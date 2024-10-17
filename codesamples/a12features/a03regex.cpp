/*

Regular expressions.

Match a single character
The regex a matches the target sequence "a" but doesn’t match "B", "b", or "c".

Character Ranges:
[b-z] matches the target sequences "b" and "c" but doesn’t match "a" or "B"

sing std::regex_match:


*/

#if 0

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string input = "apple";
    regex pattern("a.*e"); // Matches any string starting with 'a' and ending with 'e'

    if (regex_match(input, pattern))
        cout << "Pattern matched!" << endl;
    else
        cout << "Pattern not matched." << endl;

    return 0;
}




#endif


#if 0
#include <iostream>
#include <regex>
using namespace std;

//Search for a pattern within a string

int main() {
    string text = "Roses are #ff0000, violets are #0000ff";
    regex colorPattern("#([a-f0-9]{6})"); // Matches hex color codes

    smatch matches;
    while (regex_search(text, matches, colorPattern)) {
        cout << "Color code: " << matches[1] << endl;
        text = matches.suffix();
    }

    return 0;
}
#endif

#if 0

#include <iostream>
#include <regex>
using namespace std;
//Replace occurrences of a pattern with a specified string
int main() {
    string sentence = "Quick brown fox";
    regex vowels("a|e|i|o|u");

    // Replace vowels with '*'
    string result = regex_replace(sentence, vowels, "*");
    cout << "Modified sentence: " << result << endl;

    return 0;
}


#endif