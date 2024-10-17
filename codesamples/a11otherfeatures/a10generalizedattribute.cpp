#if 1

// Apply an attribute to a variable
int x [[foo]];

// Apply multiple attributes to a function
void f [[foo, bar]]();

// Apply an attribute to a type (not very common)
[[nodiscard]] struct MyType { /* ... */ };

// Apply an attribute to a code block (rarely used)
[[likely]] {
    // Code that is likely to be executed
}




#endif


#if 1

//thread_local is an attribute.
thread_local int counter = 0;

void increment_counter() {
    counter++;
    std::cout << "Thread " << std::this_thread::get_id() << " counter = " << counter << std::endl;
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);
    t1.join();
    t2.join();
    return 0;
}


#endif