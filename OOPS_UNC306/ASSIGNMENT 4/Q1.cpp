#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNo;
    string holderName;
    double balance;

public:
    void setAccountDetails(int accNo, string name, double initialBalance) {
        accountNo = accNo;
        holderName = name;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal (amount <= 0 or exceeds balance)!\n";
            return;
        }
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    }

    void displayAccount() {
        cout << "\nAccount No: " << accountNo
             << "\nHolder: " << holderName
             << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    acc.setAccountDetails(1001, "Ayush Binjola", 5000);
    acc.displayAccount();

    acc.deposit(2000);
    acc.withdraw(3000);
    acc.withdraw(100000);   // should fail - exceeds balance
    acc.deposit(-50);       // should fail - non-positive

    acc.displayAccount();

    return 0;
}
