#include <iostream>
using namespace std;
 
/*
  Suitability Analysis (before writing code):
  A) Two-integer addition            -> SUITABLE     (tiny body, no loop/recursion)
  B) Recursive factorial             -> NOT SUITABLE  (recursion prevents straightforward inline expansion)
  C) Array search containing a loop  -> NOT SUITABLE  (loop causes code bloat when expanded at every call site)
  D) Very large data-processing func -> NOT SUITABLE  (large body drastically increases executable size)
  E) Function containing a static variable -> NOT SUITABLE
        (a static variable must have a single, unique storage location shared across calls;
         most compilers refuse to inline such functions to preserve that single-copy guarantee)
 
  Only function A (two-integer addition) is implemented as inline below.
*/
 
inline int add(int a, int b) {
    return a + b;
}
 
int main() {
    cout << "add(2, 3) = " << add(2, 3) << endl;
    cout << "add(-5, 10) = " << add(-5, 10) << endl;
    cout << "add(100, 250) = " << add(100, 250) << endl;
    return 0;
}
