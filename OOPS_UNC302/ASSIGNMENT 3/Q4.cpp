#include <iostream>
using namespace std;
 
void withdrawValue(double balance, double amount);
void withdrawReference(double &balance, double amount);
 
int main() {
    double initialBalance, withdrawAmount;
 
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
 
    if (withdrawAmount <= 0 || withdrawAmount > initialBalance) {
        cout << "Invalid withdrawal amount!\n";
        return 1;
    }
 
    
    double balanceForValueTest = initialBalance;
    double balanceForRefTest = initialBalance;
 
    cout << "\n-- Call by Value --\n";
    cout << "Balance before call: " << balanceForValueTest << endl;
    withdrawValue(balanceForValueTest, withdrawAmount);
    cout << "Balance after call: " << balanceForValueTest << endl;
 
    cout << "\n-- Call by Reference --\n";
    cout << "Balance before call: " << balanceForRefTest << endl;
    withdrawReference(balanceForRefTest, withdrawAmount);
    cout << "Balance after call: " << balanceForRefTest << endl;
 
    return 0;
}
 
void withdrawValue(double balance, double amount) {
    balance -= amount;  
    cout << "Balance inside withdrawValue(): " << balance << endl;
}
 
void withdrawReference(double &balance, double amount) {
    balance -= amount;  
    cout << "Balance inside withdrawReference(): " << balance << endl;
}