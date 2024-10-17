#if 0
#include <iostream>
#include <tuple>

// Base case for printing: no arguments
void doPrint(std::ostream& out) {}

// Recursive function to print variadic arguments
template <typename T, typename... Args>
void doPrint(std::ostream& out, T&& t, Args&&... args) {
    out << t << ' '; // Print each argument
    doPrint(out, std::forward<Args>(args)...); // Recurse
}

int main() {
    // Generic lambda that captures a printer function
    auto vglambda =  {
        return = {
            printer(std::forward<decltype(ts)>(ts)...);
            return [=] {
                // HOW TO capture the variadic ts to be accessible HERE ↓
                printer(std::forward<decltype(ts)>(ts)...); // ERROR: no matching function call to forward
            };
        };
    };

    // Example usage
    auto p = vglambda( {
        doPrint(std::cout, std::forward<decltype(vars)>(vars)...);
    });

    auto q = p(1, 'a', 3.14, 5); // Outputs: 1 a 3.14 5
    // q(); // Use the returned lambda "printer"

    return 0;
}



#endif

#if 0

//c++ 17 approach

#include <iostream>
#include <tuple>

// Base case for printing: no arguments
void doPrint(std::ostream& out) {}

// Recursive function to print variadic arguments
template <typename T, typename... Args>
void doPrint(std::ostream& out, T&& t, Args&&... args) {
    out << t << ' '; // Print each argument
    doPrint(out, std::forward<Args>(args)...); // Recurse
}

int main() {
    // Generic lambda that captures a printer function
    auto vglambda =  {
        return = {
            printer(std::forward<decltype(ts)>(ts)...);
            return [=] {
                // HOW TO capture the variadic ts to be accessible HERE ↓
                printer(std::forward<decltype(ts)>(ts)...); // ERROR: no matching function call to forward
            };
        };
    };

    // Example usage
    auto p = vglambda( {
        doPrint(std::cout, std::forward<decltype(vars)>(vars)...);
    });

    auto q = p(1, 'a', 3.14, 5); // Outputs: 1 a 3.14 5
    // q(); // Use the returned lambda "printer"

    return 0;
}


#endif

#if 0

#include <iostream>
#include <boost/hana.hpp>

// Base case for printing: no arguments
void doPrint(std::ostream& out) {}

// Recursive function to print variadic arguments using Boost.Hana
template <typename... Args>
void doPrint(std::ostream& out, Args&&... args) {
    boost::hana::for_each(boost::hana::make_tuple(std::forward<Args>(args)...),
                          & { out << arg << ' '; });
}

int main() {
    // Generic lambda that captures a printer function
    auto vglambda =  {
        return = {
            printer(std::forward<decltype(ts)>(ts)...);
            return [=] {
                // Capture the variadic ts to be accessible here
                doPrint(std::cout, std::forward<decltype(ts)>(ts)...);
            };
        };
    };

    // Example usage
    auto p = vglambda( {
        doPrint(std::cout, std::forward<decltype(vars)>(vars)...);
    });

    auto q = p(1, 'a', 3.14, 5); // Outputs: 1 a 3.14 5
    // Use the returned lambda "printer"
    q(); // Outputs: 1 a 3.14 5
    return 0;
}


#endif

#if 0

#include <iostream>
#include <tuple>

// Function to capture a lambda and its arguments
template <typename Lambda, typename... Args>
auto capture_call(Lambda&& lambda, Args&&... args) {
    return [lambda = std::forward<Lambda>(lambda),
            captured_args = std::make_tuple(std::forward<Args>(args)...)] {
        std::apply(lambda, captured_args);
    };
}

int main() {
    // Example usage
    auto myLambda =  {
        std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    };

    auto capturedLambda = capture_call(myLambda, 1, 'a', 3.14, 5);
    capturedLambda(); // Outputs: 1 a 3.14 5
    return 0;
}



#endif