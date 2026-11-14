// Q12 - Propagation and rethrowing
#include <iostream>
#include <stdexcept>
using namespace std;
 
double calculateCharge(double amount, double rate) {
    try {
        if (amount < 0 || rate < 0)
            throw invalid_argument("amount and rate must be non-negative");
        cout << "  (computing charge...)\n";          // skipped when exception is thrown
        return amount * rate / 100.0;
    } catch (const exception& e) {
        cout << "  [local log] " << e.what() << '\n';
        throw;                                         // rethrow the SAME exception object
    }
}
 
int main() {
    double tests[2][2] = { {2000, 2.5}, {-500, 2.5} };
    for (auto& t : tests) {
        cout << "amount = " << t[0] << ", rate = " << t[1] << "%\n";
        try {
            double c = calculateCharge(t[0], t[1]);
            cout << "  Service charge = " << c << '\n';
        } catch (const invalid_argument& e) {
            cout << "  [main] Final message: " << e.what() << '\n';
        }
    }
    return 0;
}
