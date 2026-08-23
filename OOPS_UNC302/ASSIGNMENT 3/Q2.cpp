#include <iostream>
#include <cstdlib>
using namespace std;
 

bool isPrime(int n);        // arguments + return value
void printFactors(int n);   // arguments + no return value
int readNumber();           // no arguments + return value
void showHeading();         // no arguments + no return value
 
int main() {
    showHeading();
    int num = readNumber();
 
    cout << "Entered number: " << num << endl;
 
    if (num < 2)
        cout << "Not Prime (numbers less than 2 are never prime)\n";
    else
        cout << (isPrime(num) ? "Prime" : "Not Prime") << endl;
 
    cout << ((num % 2 == 0) ? "Even" : "Odd") << endl;
 
    printFactors(num);
 
    return 0;
}
 
void showHeading() {
    cout << "===== Number Analyzer =====\n";
}
 
int readNumber() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    return n;
}
 
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
 
void printFactors(int n) {
    int value = abs(n);
    int count = 0;
    cout << "Factors: ";
    if (value == 0) {
        cout << "undefined (0 has infinite factors)\n";
        return;
    }
    for (int i = 1; i <= value; i++) {
        if (value % i == 0) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nTotal number of factors: " << count << endl;
}
