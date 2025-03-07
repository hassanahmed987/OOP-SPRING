#include <iostream>
using namespace std;

class Account {
public:
    int accountNumber;
    float balance;

    Account(int accNum, float bal) {
        accountNumber = accNum;
        balance = bal;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    float interestRate;

    SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal) {
        interestRate = rate;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance
             << ", Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
public:
    float overdraftLimit;

    CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal) {
        overdraftLimit = limit;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance
             << ", Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings(1001, 5000.0, 2.5);
    
    CheckingAccount checking(2001, 3000.0, 1000.0);

    cout << "Savings Account Details:" << endl;
    savings.displayDetails();
    cout << endl;

    cout << "Checking Account Details:" << endl;
    checking.displayDetails();

    return 0;
}
