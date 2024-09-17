#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};

    // Define a stateful lambda to calculate cumulative sum of signal
    int sum = 0;
    auto cumulative_sum = [&sum](int value) {
        sum += value;
        return sum;
    };



    // Apply the stateful lambda to the signal
    std::vector<int> cumulative_result;
    std::transform(signal.begin(), signal.end(), std::back_inserter(cumulative_result), cumulative_sum);

    


    /*


std::transform is a standard algorithm that applies
 a given function (cumulative_sum) to each
  element in the range defined by
   signal.begin() and signal.end(),
    and stores the results in another range.

std::back_inserter(cumulative_result) creates
 a back-insert iterator for the
  cumulative_result vector. 
  This iterator allows inserting elements at
   the end of the 
   vector using push_back().

During the transformation process, 
std::transform calls cumulative_sum for each element in signal,
 and the results are inserted at the end of cumulative_result 
 using the back-insert iterator.

So, effectively, std::back_inserter allows std::transform to
 append the transformed elements to cumulative_result
  without explicitly resizing or preallocating space
   in the vector. It's a convenient way to append
    elements to a container while performing 
    transformations or other operations.
    
    
    */

    // Print the cumulative sum of signal
    std::cout << "Cumulative Sum: ";
    for (const int &value : cumulative_result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
