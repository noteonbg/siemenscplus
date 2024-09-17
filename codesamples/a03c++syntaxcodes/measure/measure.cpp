#include <iostream>
#include <chrono>
#include <thread>

class Timer
{

std::chrono::time_point<std::chrono::steady_clock> start,end;
std::chrono::duration<double,std::milli> duration;

Timer()
{
    start = std::chrono::high_resolution_clock::now();
}

~Timer()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end-start;
    std::cout << " Duration is " << duration.count();
}


};



#if 0
// Example function to simulate a task
void performTask() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulates a 2-second task
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    performTask();
    
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> duration = end - start;  // duration by default in seconds
    
    std::cout << "performTask() took " << duration.count() << " seconds to execute.\n";
    
    return 0;
}

#endif

#if 1

int main() {
    // Get the starting point
    auto start = std::chrono::high_resolution_clock::now();
    
    // Call the function you want to measure
    //myFunction();
    for(long long  i=0; i <1000000000; i++ );
    
    // Get the ending point
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    
    // Output the duration in milliseconds
    std::cout << "myFunction() took " << duration.count() << " ms to execute.\n";
    
    return 0;
}

#endif


