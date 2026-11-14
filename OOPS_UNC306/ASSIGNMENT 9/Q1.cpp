// Q1 - Unformatted Console I/O: get(), getline(), put(), write()
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;
 
void showName(const string& name) {
    // write() needs the exact number of characters: name.size()
    cout << "Name  (write): ";
    cout.write(name.c_str(), static_cast<streamsize>(name.size()));
    cout << " [" << name.size() << " chars]\n";
}
 
void showGrade(char grade) {
    cout << "Grade (put)  : ";
    cout.put(grade);
    cout.put('\n');
}
 
int main() {
    string name;
    char grade;
 
    cout << "Enter full name (with spaces): ";
    getline(cin, name);                       // keeps embedded spaces
 
    cout << "Enter grade character: ";
    cin.get(grade);                           // reads exactly one char
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // drop pending '\n'
 
    showName(name);
    showGrade(grade);
 
    // --- Compare >> with getline() on the same name ---
    istringstream demo(name);
    string firstWord;
    demo >> firstWord;                        // stops at first whitespace
    cout << "\nUsing cin >> on \"" << name << "\" would store only: \""
         << firstWord << "\"\n";
 
    // --- get() vs >> for whitespace ---
    istringstream a("  X"), b("  X");
    char c1, c2;
    a.get(c1);                                // returns the space itself
    b >> c2;                                  // skips leading whitespace
    cout << "get() read : '" << c1 << "' (ASCII " << int(c1) << ")\n";
    cout << ">>    read : '" << c2 << "' (ASCII " << int(c2) << ")\n";
    return 0;
}
