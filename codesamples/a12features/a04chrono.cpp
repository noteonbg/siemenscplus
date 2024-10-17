#if 1

/*


<chrono> provides three main clock types:
std::chrono::system_clock: Represents the system-wide real-time wall clock. It may not be monotonic
 (i.e., it can be adjusted due to system time changes).
std::chrono::steady_clock: Represents a monotonically increasing clock that’s not affected
 by system time adjustments.
std::chrono::high_resolution_clock: Provides the shortest tick period available on the system.

 A duration object expresses a time span (e.g., minutes, hours, milliseconds).
It consists of a count (number of ticks) and a unit (such as seconds or nanoseconds).

Time Points:
A time point represents a specific point in time.
It combines a clock type (e.g., system_clock) with a duration (e.g., seconds).
You can use time points to measure intervals or calculate future or past times.


*/


#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
    // Create a duration of 60 seconds
    milliseconds mil(1000);
    mil = mil * 60;

    std::cout << "Duration (in periods): " << mil.count() << " milliseconds.\n";
    std::cout << "Duration (in seconds): " << (mil.count() * milliseconds::period::num / milliseconds::period::den) << " seconds.\n";

    return 0;
}

#endif

#if 0

#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono;

int main() {
    std::cout << "Waiting for 2 seconds...\n";
    std::this_thread::sleep_for(seconds(2));
    std::cout << "Done!\n";

    return 0;
}


#endif

#if 0

#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
    system_clock::time_point now = system_clock::now();
    std::time_t now_c = system_clock::to_time_t(now);

    std::cout << "Current time: " << std::ctime(&now_c);

    return 0;
}


#endif


#if 0

#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
    steady_clock::time_point start = steady_clock::now();

    // Simulate some work
    for (int i = 0; i < 1000000; ++i) {
        // Do something
    }

    steady_clock::time_point end = steady_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(end - start);

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";

    return 0;
}

#endif