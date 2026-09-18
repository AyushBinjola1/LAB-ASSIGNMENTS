#include <iostream>
using namespace std;

class AuditRule;   // forward declaration needed for the friend prototype

class BankAccount {
private:
    int accountNo;
    double balance;
    static int successfulTransactions;

public:
    void setAccountDetails(int accNo, double initialBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    bool transferTo(BankAccount &receiver, double amount);
    void displayAccount();
    static void displayTransactionCount();

    friend void auditAccount(BankAccount, AuditRule);
};

int BankAccount::successfulTransactions = 0;   // static member defined outside the class

void BankAccount::setAccountDetails(int accNo, double initialBalance) {
    accountNo = accNo;
    balance = (initialBalance >= 0) ? initialBalance : 0;
}

bool BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Deposit failed on A/C " << accountNo << ": amount must be positive.\n";
        return false;
    }
    balance += amount;
    successfulTransactions++;
    cout << "Deposited " << amount << " to A/C " << accountNo << ". Balance: " << balance << endl;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Withdrawal failed on A/C " << accountNo << " (invalid amount or insufficient balance).\n";
        return false;
    }
    balance -= amount;
    successfulTransactions++;
    cout << "Withdrew " << amount << " from A/C " << accountNo << ". Balance: " << balance << endl;
    return true;
}

bool BankAccount::transferTo(BankAccount &receiver, double amount) {
    if (amount <= 0 || amount > balance) {
        cout << "Transfer failed from A/C " << accountNo << " to A/C " << receiver.accountNo << ".\n";
        return false;
    }
    balance -= amount;
    receiver.balance += amount;      // permanently updates the receiver via reference
    successfulTransactions++;
    cout << "Transferred " << amount << " from A/C " << accountNo
         << " to A/C " << receiver.accountNo << endl;
    return true;
}

void BankAccount::displayAccount() {
    cout << "A/C No: " << accountNo << ", Balance: " << balance << endl;
}

void BankAccount::displayTransactionCount() {
    cout << "Total successful transactions: " << successfulTransactions << endl;
}

class AuditRule {
private:
    double minimumRequiredBalance;

public:
    void setMinimumBalance(double m) {
        minimumRequiredBalance = m;
    }

    friend void auditAccount(BankAccount, AuditRule);
};

// common friend function of BankAccount and AuditRule
void auditAccount(BankAccount acc, AuditRule rule) {
    cout << "Audit of A/C " << acc.accountNo << ": ";
    if (acc.balance >= rule.minimumRequiredBalance)
        cout << "Satisfies minimum-balance rule.\n";
    else
        cout << "Does NOT satisfy minimum-balance rule.\n";
}

int main() {
    BankAccount acc1, acc2;
    acc1.setAccountDetails(101, 5000);
    acc2.setAccountDetails(102, 2000);

    cout << "-- Initial state --\n";
    acc1.displayAccount();
    acc2.displayAccount();

    cout << "\n-- Operation 1: successful deposit --\n";
    acc1.deposit(1000);

    cout << "\n-- Operation 2: failed withdrawal (exceeds balance) --\n";
    acc2.withdraw(50000);

    cout << "\n-- Operation 3: successful transfer --\n";
    acc1.transferTo(acc2, 1500);

    cout << "\n-- Operation 4: static transaction count --\n";
    BankAccount::displayTransactionCount();

    cout << "\n-- Operation 5: audit both accounts --\n";
    AuditRule rule;
    rule.setMinimumBalance(1000);
    auditAccount(acc1, rule);
    auditAccount(acc2, rule);

    cout << "\n-- Final state --\n";
    acc1.displayAccount();
    acc2.displayAccount();

    return 0;
}
