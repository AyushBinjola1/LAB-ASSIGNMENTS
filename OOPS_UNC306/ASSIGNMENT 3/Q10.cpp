#include <iostream>
using namespace std;
 
/*
  Pair 1: int process(int a);       double process(double a);
          VALID - parameter types differ (int vs double)
 
  Pair 2: int compute(int a, int b);  float compute(int a, int b);
          INVALID - identical parameter lists; differs only in return type
          FIX: change a parameter type, e.g. float compute(float a, float b);
 
  Pair 3: void show(int a, float b);  void show(float a, int b);
          VALID - parameter order/types differ
 
  Pair 4: int find(int a);  int find(int x);
          INVALID - identical signature int find(int); parameter NAMES do not
          count, only parameter TYPES/order do
          FIX: change parameter type, e.g. int find(long x);
 
  Pair 5: void calculate(int a);  void calculate(int a, int b);
          VALID - differs by number of parameters
*/
 
// ---- Pair 1 (already valid) ----
int process(int a) { return a * 2; }
double process(double a) { return a * 2.0; }
 
// ---- Pair 2 (corrected) ----
int compute(int a, int b) { return a + b; }
float compute(float a, float b) { return a + b; }
 
// ---- Pair 3 (already valid) ----
void show(int a, float b) { cout << "show(int,float): " << a << ", " << b << endl; }
void show(float a, int b) { cout << "show(float,int): " << a << ", " << b << endl; }
 
// ---- Pair 4 (corrected) ----
int find(int a) { return a; }
int find(long x) { return (int)x; }
 
// ---- Pair 5 (already valid) ----
void calculate(int a) { cout << "calculate(int): " << a << endl; }
void calculate(int a, int b) { cout << "calculate(int,int): " << (a + b) << endl; }
 
int main() {
    cout << process(5) << endl;
    cout << process(5.5) << endl;
 
    cout << compute(3, 4) << endl;
    cout << compute(3.5f, 4.5f) << endl;
 
    show(1, 2.5f);
    show(2.5f, 1);
 
    cout << find(10) << endl;
    cout << find(10L) << endl;
 
    calculate(5);
    calculate(5, 10);
 
    return 0;
}
