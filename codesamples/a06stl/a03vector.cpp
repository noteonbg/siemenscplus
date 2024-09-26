// CPP program to illustrate std::find_i
#include <vector>
#include <iostream>
#include <algorithm> 


using namespace std;




// Returns true if argument is odd
bool IsOdd(int i) { return i % 2; }

// Driver code
int main()
{
	vector<int> vec{ 10, 25, 40, 55 };

	// Iterator to store the position of element found
	vector<int>::iterator it;

	// std::find_if
	it = find_if(vec.begin(), vec.end(), IsOdd);

	cout << "The first odd value is " << *it << '\n';

	return 0;
}
