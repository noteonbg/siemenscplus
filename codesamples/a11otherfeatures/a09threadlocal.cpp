#if 1

#include <iostream>
#include <thread>


/*

The thread_local keyword allows each thread to have its own separate instance of a variable.
 each thread can have its own independent copy of a variable without
  interfering with other threads.


*/

void thread_func() {
    //static thread_local int stls_variable = 0;
    static int stls_variable = 0;
    stls_variable += 1;
    std::cout << "Thread ID: " << std::this_thread::get_id() << ", Variable: " << stls_variable << std::endl;
}

int main() {
    std::thread t1(thread_func);
    std::thread t2(thread_func);
    t1.join();
    t2.join();
    return 0;
}

#endif