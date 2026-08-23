#include <iostream>
#include <cmath>
using namespace std;
 
int calculate(int a, int b);          // addition
double calculate(double a, double b); // multiplication
int calculate(int a, int b, int c);   // largest of three
double calculate(int a, double b);    // a raised to power b
 
int main() {
    cout << "calculate(5, 3) = " << calculate(5, 3)
         << "  [int,int -> addition]\n";
 
    cout << "calculate(2.5, 4.0) = " << calculate(2.5, 4.0)
         << "  [double,double -> multiplication]\n";
 
    cout << "calculate(10, 25, 7) = " << calculate(10, 25, 7)
         << "  [int,int,int -> largest of three]\n";
 
    cout << "calculate(2, 3.0) = " << calculate(2, 3.0)
         << "  [int,double -> power]\n";
 
    return 0;
}
 
int calculate(int a, int b) {
    return a + b;
}
 
double calculate(double a, double b) {
    return a * b;
}
 
int calculate(int a, int b, int c) {
    int largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    return largest;
}
 
double calculate(int a, double b) {
    return pow(a, b);   // library function used for exponentiation
}
