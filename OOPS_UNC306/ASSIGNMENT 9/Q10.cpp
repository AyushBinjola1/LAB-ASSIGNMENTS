// Q10 - try, throw, catch : checked division
#include <iostream>
#include <stdexcept>
using namespace std;
 
double divideChecked(double numerator, double denominator) {
    if (denominator == 0)
        throw invalid_argument("denominator is zero");
    return numerator / denominator;
}
 
int main() {
    double n, d;
    cout << "Enter numerator and denominator: ";
    cin >> n >> d;
    try {
        double q = divideChecked(n, d);
        cout << n << " / " << d << " = " << q << '\n';
        cout << "Division completed normally\n";
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }
    cout << "Program ends normally\n";
    return 0;
}
