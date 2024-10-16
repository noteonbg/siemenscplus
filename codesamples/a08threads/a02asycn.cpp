#if 1

#include <iostream>
#include <future> // Include the <future> header for std::async

// Function to fetch data from a database (simulated delay)
std::string fetchDataFromDB(const std::string& input) {
    // Simulate fetching data from a database (takes 5 seconds)
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "DB_" + input;
}

// Function to fetch data from a file (simulated delay)
std::string fetchDataFromFile(const std::string& input) {
    // Simulate fetching data from a file (takes 5 seconds)
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return "File_" + input;
}

int main() {
    // Start measuring time
    auto start = std::chrono::system_clock::now();

    // Execute fetchDataFromDB asynchronously
    auto dbFuture = std::async(std::launch::async, fetchDataFromDB, "Data");

    // Execute fetchDataFromFile asynchronously
    auto fileFuture = std::async(std::launch::async, fetchDataFromFile, "Data");

    // Wait for both tasks to complete
    std::string dbData = dbFuture.get();
    std::string fileData = fileFuture.get();

    // Calculate total time taken
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    // Combine the data
    std::string combinedData = dbData + " :: " + fileData;

    std::cout << "Total Time Taken: " << duration << " seconds" << std::endl;
    std::cout << "Combined Data: " << combinedData << std::endl;

    return 0;
}

/*

 two functions (fetchDataFromDB and fetchDataFromFile) that simulate
 fetching data from a database and a file, respectively.

use std::async to execute these functions asynchronously.

The std::launch::async policy ensures that each function runs in a separate thread.

 wait for both tasks to complete using get() on the futures.

Finally, we combine the fetched data and measure the total time taken.


*/



#endif