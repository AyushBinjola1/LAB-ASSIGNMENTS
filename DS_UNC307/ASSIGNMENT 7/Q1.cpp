// Q1: Analyze and Compare Time Complexities (operation counting)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
 
typedef unsigned long long ull;
 
// Every function performs its algorithm and returns the number of steps executed.
 
// O(1)
ull constantTime(int n) {
    ull c = 0;
    c++;
    return c;
}
 
// O(log n): i doubles each time, so the loop runs floor(log2 n) + 1 times
ull logTime(int n) {
    ull c = 0;
    for (int i = 1; i <= n; i *= 2) c++;
    return c;
}
 
// O(sqrt n): runs while i*i <= n
ull sqrtTime(int n) {
    ull c = 0;
    for (long long i = 1; i * i <= n; i++) c++;
    return c;
}
 
// O(n)
ull linearTime(int n) {
    ull c = 0;
    for (int i = 0; i < n; i++) c++;
    return c;
}
 
// O(n log n): n iterations of an inner loop that doubles j
ull nlognTime(int n) {
    ull c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j *= 2) c++;
    return c;
}
 
// O(n^2)
ull quadraticTime(int n) {
    ull c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) c++;
    return c;
}
 
// O(n^3)
ull cubicTime(int n) {
    ull c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) c++;
    return c;
}
 
// O(2^n): every call makes two calls with n-1, giving 2^n leaf calls
void expRec(int n, ull &c) {
    if (n == 0) { c++; return; }
    expRec(n - 1, c);
    expRec(n - 1, c);
}
ull expTime(int n) {
    ull c = 0;
    expRec(n, c);
    return c;
}
 
// O(n!): every call makes n calls with n-1, giving n! leaf calls
void factRec(int n, ull &c) {
    if (n == 0) { c++; return; }
    for (int i = 0; i < n; i++) factRec(n - 1, c);
}
ull factTime(int n) {
    ull c = 0;
    factRec(n, c);
    return c;
}
 
// Values for large n (executing 2^n or n! steps is not feasible).
// They are exactly the counts the recursions above would produce.
long double expValue(int n) { return ldexpl(1.0L, n); }
long double factValue(int n) {
    long double f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}
 
int main() {
    vector<int> sizes = {1, 2, 3, 5, 10, 15, 20, 25};
 
    // ---- Part (b): operation counts for increasing n ----
    cout << "Operation counts for different values of n\n\n";
    cout << left << setw(5) << "n" << setw(7) << "O(1)" << setw(9) << "O(logn)"
         << setw(10) << "O(sqrtn)" << setw(7) << "O(n)" << setw(10) << "O(nlogn)"
         << setw(9) << "O(n^2)" << "O(n^3)\n";
    for (int n : sizes)
        cout << left << setw(5) << n << setw(7) << constantTime(n)
             << setw(9) << logTime(n) << setw(10) << sqrtTime(n)
             << setw(7) << linearTime(n) << setw(10) << nlognTime(n)
             << setw(9) << quadraticTime(n) << cubicTime(n) << "\n";
 
    // ---- Graph 3 (tabular only): O(2^n) and O(n!) ----
    cout << "\nGraph 3: O(2^n) and O(n!)\n\n";
    cout << left << setw(5) << "n" << setw(12) << "O(2^n)" << "O(n!)\n";
    int tableN[] = {1, 2, 3, 5, 10, 15, 20};
    for (int n : tableN) {
        ull e = expTime(n);                                   // executed for real
        ull f = (n <= 10) ? factTime(n) : (ull)factValue(n);  // 15!, 20!
        cout << left << setw(5) << n << setw(12) << e << f << "\n";
    }
    cout << "(n! for n > 10 is computed by multiplication, "
         << "running it would take too long)\n";
 
    // ---- Part (c): CSV files ----
    ofstream f1("complexity_1_to_100.csv");           // used for Graph 1 and Graph 2
    f1 << "n,O(1),O(logn),O(sqrtn),O(n),O(nlogn),O(n^2),O(n^3)\n";
    for (int n = 1; n <= 100; n++)
        f1 << n << ',' << constantTime(n) << ',' << logTime(n) << ','
           << sqrtTime(n) << ',' << linearTime(n) << ',' << nlognTime(n) << ','
           << quadraticTime(n) << ',' << cubicTime(n) << '\n';
    f1.close();
 
    ofstream f2("complexity_all_nine.csv");           // all nine complexities
    f2 << setprecision(15);
    f2 << "n,O(1),O(logn),O(sqrtn),O(n),O(nlogn),O(n^2),O(n^3),O(2^n),O(n!)\n";
    for (int n : sizes) {
        f2 << n << ',' << constantTime(n) << ',' << logTime(n) << ','
           << sqrtTime(n) << ',' << linearTime(n) << ',' << nlognTime(n) << ','
           << quadraticTime(n) << ',' << cubicTime(n) << ',';
        f2 << (n <= 20 ? (long double)expTime(n) : expValue(n)) << ',';
        f2 << (n <= 10 ? (long double)factTime(n) : factValue(n)) << '\n';
    }
    f2.close();
 
    cout << "\nValues saved in complexity_1_to_100.csv and complexity_all_nine.csv\n";
    return 0;
}
