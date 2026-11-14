// Q2 - Formatted Output: width, precision, flags, manipulators
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
void printItem(int id, const string& name, double price) {
    cout << setfill('0') << right << setw(4) << id      // ID: zero padded
         << setfill(' ') << "  "
         << left << setw(14) << name                    // name: left aligned
         << right << setw(10) << fixed << setprecision(2) << price << '\n';
}
 
int main() {
    cout << left << setw(6) << "ID" << setw(14) << "Item"
         << right << setw(10) << "Price" << '\n';
    cout << string(30, '-') << '\n';
 
    printItem(7,   "Notebook",     45.5);
    printItem(42,  "Ball Pen",     12.0);
    printItem(255, "Geometry Box", 120.756);
 
    // decimal and hexadecimal
    int id = 255;
    cout << "\nID in decimal : " << id << '\n';
    cout << "ID in hex     : " << hex << id << '\n';
    cout << dec;                                         // restore decimal
    cout << "Back to dec   : " << id << '\n';
 
    // width applies to next field only
    cout << "\nsetw(10) applies once:\n";
    cout << '[' << setw(10) << 12 << ']' << '[' << 34 << "]\n";
 
    // fill and precision persist
    cout << setfill('*') << setw(8) << 5 << setw(8) << 6 << '\n';
    cout << setfill(' ');
 
    // precision with and without fixed
    double v = 3.14159265;
    cout.unsetf(ios::fixed);
    cout << "\nsetprecision(2) without fixed: " << setprecision(2) << v << '\n';
    cout << "setprecision(2) with fixed   : " << fixed << setprecision(2) << v << '\n';
    return 0;
}
