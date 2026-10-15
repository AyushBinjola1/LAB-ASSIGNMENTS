#include <iostream>
using namespace std;
 
int main() {
    // 1. IMPLICIT conversion: char -> int (done by the compiler)
    char ch = 'A';
    int code = ch;
    cout << "char value : " << ch << endl;
    cout << "int  value : " << code << "   (implicit char -> int)" << endl;
 
    // 2. EXPLICIT conversion: double -> int using static_cast
    double value = 9.75;
    int whole = static_cast<int>(value);
    cout << "\ndouble value : " << value << endl;
    cout << "int value    : " << whole << "   (explicit, fractional part lost)" << endl;
 
    // 3. EXPLICIT const_cast on an ORIGINALLY NON-CONST object
    int number = 25;                       // originally non-const
    const int *view = &number;             // read-only view
    int *modifiable = const_cast<int*>(view);   // remove const (explicit)
    cout << "\nBefore modification: number = " << number << endl;
    *modifiable = 100;                     // safe: object itself is not const
    cout << "After  modification: number = " << number << endl;
    return 0;
}
