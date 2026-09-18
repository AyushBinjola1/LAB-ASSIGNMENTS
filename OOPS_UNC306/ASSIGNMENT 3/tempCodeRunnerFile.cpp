#include <iostream>
using namespace std;
 
void deposit(double &balance, double amount);
bool withdraw(double &balance, double amount);
inline double interest(double balance, double rate);
double compareBalance(double a, double b);
int compareBalance(int a, int b);                 // overloaded version
void transactionSummary(double balance);
double serviceCharge(double amount, double rate = 0.02); // default argument
 
int main() {
    double balance = 0;
    int choice;
 
    cout << "Enter initial balance: ";
    cin >> balance;
 
    do {
        cout << "\n===== Banking Menu =====\n";
        cout << "1. Deposit\n2. Withdraw\n3. Calculate Interest\n";
        cout << "4. Display Balance\n5. Compare with Another Balance\n";
        cout << "6. Transaction Summary\n-1. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 
        switch (choice) {
            case 1: {
                double amt;
                cout << "Enter deposit amount: ";
                cin >> amt;
                if (amt <= 0) cout << "Invalid deposit amount!\n";
                else deposit(balance, amt);   // call by reference
                break;
            }
            case 2: {
                double amt;
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                if (!withdraw(balance, amt))
                    cout << "Withdrawal failed (invalid amount or insufficient balance)!\n";
                break;
            }
            case 3: {
                double rate;
                cout << "Enter interest rate (%): ";
                cin >> rate;
                cout << "Interest earned: " << interest(balance, rate) << endl;   // inline function
                double charge = serviceCharge(balance);   // default argument used (rate=0.02)
                cout << "Applicable service charge (default rate): " << charge << endl;
                break;
            }
            case 4:
                cout << "Current Balance: " << balance << endl;
                break;
            case 5: {
                double other;
                cout << "Enter balance to compare with: ";
                cin >> other;
                double diff = compareBalance(balance, other);   // overload: double version
                if (diff > 0) cout << "Your balance is higher by " << diff << endl;
                else if (diff < 0) cout << "Your balance is lower by " << -diff << endl;
                else cout << "Both balances are equal.\n";
                break;
            }
            case 6:
                transactionSummary(balance);
                break;
            case -1:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid menu option!\n";
        }
    } while (choice != -1);
 
    return 0;
}
 
// call by reference - permanently modifies balance
void deposit(double &balance, double amount) {
    balance += amount;
    cout << "Deposited " << amount << ". New balance: " << balance << endl;
}
 
bool withdraw(double &balance, double amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    return true;
}
 
inline double interest(double balance, double rate) {
    return balance * rate / 100;
}
 
double compareBalance(double a, double b) {
    return a - b;
}
 
int compareBalance(int a, int b) {   // overloaded on parameter type
    return a - b;
}
 
void transactionSummary(double balance) {
    cout << "--- Transaction Summary ---\n";
    cout << "Current Balance: " << balance << endl;
}
 
double serviceCharge(double amount, double rate) {
    return amount * rate;
}
 
/*
  Sample test cases to run and record for submission:
  1) Normal transaction : deposit 2000 then withdraw 500 -> succeeds, balance updates correctly.
  2) Insufficient balance: withdraw an amount greater than current balance -> withdraw()
     returns false, "Withdrawal failed" message shown, balance unchanged.
  3) Invalid input: enter a negative deposit amount or an out-of-range menu
     choice -> program rejects it and reprints the menu without crashing.
*/
