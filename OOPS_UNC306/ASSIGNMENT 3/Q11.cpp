#include <iostream>
using namespace std;
 
double electricityBill(int units, double rate = 6.5, double fixedCharge = 150);
 
int main() {
    int units;
    cout << "Enter units consumed: ";
    cin >> units;
 
    if (units < 0) {
        cout << "Invalid units!\n";
        return 1;
    }
 
    cout << "\nCall 1: electricityBill(200)\n";
    cout << "Uses default rate=6.5 and default fixedCharge=150\n";
    cout << "Bill: " << electricityBill(200) << endl;
 
    cout << "\nCall 2: electricityBill(200, 7.0)\n";
    cout << "Uses given rate=7.0 and default fixedCharge=150\n";
    cout << "Bill: " << electricityBill(200, 7.0) << endl;
 
    cout << "\nCall 3: electricityBill(200, 7.0, 250)\n";
    cout << "Uses given rate=7.0 and given fixedCharge=250 (no defaults used)\n";
    cout << "Bill: " << electricityBill(200, 7.0, 250) << endl;
 
    cout << "\nYour bill for " << units << " units: " << electricityBill(units) << endl;
 
    return 0;
}
 
double electricityBill(int units, double rate, double fixedCharge) {
    return units * rate + fixedCharge;
}
 
/*
  Invalid declaration example (middle parameter has a default, one to its
  right does not):
 
      double electricityBill(int units, double rate = 6.5, double fixedCharge);
      // ERROR: once "rate" is given a default value, every parameter that
      // follows it ("fixedCharge") must also have a default value.
*/
