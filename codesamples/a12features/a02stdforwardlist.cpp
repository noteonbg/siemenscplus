#if 1

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> flist1; // Empty forward list
    forward_list<int> flist2; // Empty forward list
    forward_list<int> flist3; // Empty forward list

    flist1.assign({1, 2, 3}); // Assign values using initializer list
    flist2.assign(5, 10);     // Assign 10 five times
    flist3.assign(flist1.begin(), flist1.end()); // Assign from another forward list

    cout << "Elements of the first forward list: ";
    for (int& a : flist1)
        cout << a << " ";
    cout << endl;

    cout << "Elements of the second forward list: ";
    for (int& b : flist2)
        cout << b << " ";
    cout << endl;

    cout << "Elements of the third forward list: ";
    for (int& c : flist3)
        cout << c << " ";
    cout << endl;

    return 0;
}

/*

 std::forward_list from the C++ Standard Library (STL).
  A std::forward_list is a singly linked list that allows efficient 
  insertion and removal of elements. 
  Unlike std::list, it doesn’t support 
  bidirectional iteration (i.e., you can only traverse it forward).


*/


#endif

#if 0

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> flist = {10, 20, 30, 40, 50};

    flist.push_front(60); // Insert 60 at the front
    cout << "Forward list after push_front: ";
    for (int& c : flist)
        cout << c << " ";
    cout << endl;

    flist.emplace_front(70); // Create 70 directly at the front
    cout << "Forward list after emplace_front: ";
    for (int& c : flist)
        cout << c << " ";
    cout << endl;

    flist.pop_front(); // Remove the first element
    cout << "Forward list after pop_front: ";
    for (int& c : flist)
        cout << c << " ";
    cout << endl;

    return 0;
}


#endif