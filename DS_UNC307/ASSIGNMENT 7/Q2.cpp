// Q2: Recursive implementations of recurrence relations and timing
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;
 
// In every function, "work" is the non-recursive cost of one call
// (a loop of 1, n, n^2 or log n iterations) and it is added to T(n-1).
 
// (i) T(n) = T(n-1) + 1
long long T1(int n) {
    if (n <= 0) return 0;                       // base case T(0) = 0
    long long work = 1;
    return T1(n - 1) + work;
}
 
// (ii) T(n) = T(n-1) + n
long long T2(int n) {
    if (n <= 0) return 0;
    long long work = 0;
    for (int i = 0; i < n; i++) work++;         // n steps
    return T2(n - 1) + work;
}
 
// (iii) T(n) = T(n-1) + n^2
long long T3(int n) {
    if (n <= 0) return 0;
    long long work = 0;
    for (long long i = 0; i < (long long)n * n; i++) work++;   // n^2 steps
    return T3(n - 1) + work;
}
 
// (iv) T(n) = T(n-1) + log n
long long T4(int n) {
    if (n <= 0) return 0;
    long long work = 0;
    for (int k = 1; k <= n; k *= 2) work++;     // floor(log2 n) + 1 steps
    return T4(n - 1) + work;
}
 
// Time one call in microseconds (best of 'reps' runs to reduce noise)
double timeUs(long long (*f)(int), int n, int reps) {
    double best = -1;
    for (int r = 0; r < reps; r++) {
        auto s = high_resolution_clock::now();
        volatile long long result = f(n);
        (void)result;
        auto e = high_resolution_clock::now();
        double us = duration_cast<nanoseconds>(e - s).count() / 1000.0;
        if (best < 0 || us < best) best = us;
    }
    return best;
}
 
int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 1 || n > 100) {
        cerr << "Enter an integer from 1 to 100.\n";
        return 1;
    }
 
    cout << "\nValues of T(n) for n = 1 to " << n << "\n";
    cout << left << setw(5) << "n" << setw(14) << "T(n-1)+1" << setw(14) << "T(n-1)+n"
         << setw(14) << "T(n-1)+n^2" << setw(14) << "T(n-1)+log n"
         << "Closed form check\n";
    for (int i = 1; i <= n; i++) {
        bool ok = (T1(i) == i) && (T2(i) == (long long)i * (i + 1) / 2) &&
                  (T3(i) == (long long)i * (i + 1) * (2 * i + 1) / 6);
        cout << left << setw(5) << i << setw(14) << T1(i) << setw(14) << T2(i)
             << setw(14) << T3(i) << setw(14) << T4(i)
             << (ok ? "match" : "MISMATCH") << "\n";
    }
 
    cout << "\nExecution time in microseconds\n";
    cout << left << setw(8) << "n" << setw(14) << "T(n-1)+1" << setw(14) << "T(n-1)+n"
         << setw(14) << "T(n-1)+n^2" << setw(14) << "T(n-1)+log n" << "\n";
    cout << fixed << setprecision(1);
    int sizes[] = {100, 200, 400, 800, 1600};
    for (int size : sizes) {
        int heavy = (size >= 800) ? 2 : 5;      // fewer repeats for slow T3
        cout << left << setw(8) << size << setw(14) << timeUs(T1, size, 5)
             << setw(14) << timeUs(T2, size, 5) << setw(14) << timeUs(T3, size, heavy)
             << setw(14) << timeUs(T4, size, 5) << "\n";
    }
    return 0;
}
