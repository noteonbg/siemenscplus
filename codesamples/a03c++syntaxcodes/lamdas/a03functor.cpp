#include <iostream>
using namespace std;

// Functor class for addition
class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Add add;          // Create an object of Add class
    int sum = add(100, 78);
    cout << "100 + 78 = " << sum << endl;
    return 0;
}


#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> aVect = {3, 2, 5, 4};
    vector<int> bVect;
    auto first = aVect.begin();
    auto last = aVect.end();
    transform(first, last, back_inserter(bVect), multiplies<>());
    // bVect now contains the product of elements in aVect
    return 0;
}


/*

multiplies<> is a predefined functor that multiplies two values.
Functors provide flexibility and allow us to customize behavior in various contexts. 
They are especially useful when working with STL algorithms!

*/


#endif 