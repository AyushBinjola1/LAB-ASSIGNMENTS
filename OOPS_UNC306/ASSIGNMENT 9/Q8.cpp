// Q8 - Function template: larger of two values
#include <iostream>
using namespace std;
 
template <typename T>
T larger(T first, T second) {
    return (first > second) ? first : second;
}
 
int main() {
    cout << "larger<int>(10, 25)      = " << larger<int>(10, 25) << '\n';   // explicit
    cout << "larger(3.5, 2.75)        = " << larger(3.5, 2.75) << '\n';     // deduced double
    cout << "larger('a', 'Z')         = " << larger('a', 'Z') << '\n';      // deduced char
    cout << "ASCII of 'a' = " << int('a') << ", 'Z' = " << int('Z') << '\n';
 
    // cout << larger(5, 6.5);   // ERROR: T deduced as int from 5 and double from 6.5
    // Fixes: larger<double>(5, 6.5)  or  larger(5.0, 6.5)
    cout << "larger<double>(5, 6.5)   = " << larger<double>(5, 6.5) << '\n';
    return 0;
}
