#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[10];  
    int transactionCount;

public:
    Wallet(string name) {
        ownerName = name;
        totalBalance = 0.0;
        transactionCount = 0;
    }

    void addMoney(double amount) {
        if (amount > 0) {
            totalBalance += amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = "Added " + std::to_string(amount) + " to wallet.";
            } else {
                for (int i = 1; i < 10; i++) {
                    transactionHistory[i - 1] = transactionHistory[i];
                }
                transactionHistory[9] = "Added " + std::to_string(amount) + " to wallet.";
            }
            cout << amount << " added to wallet. Total balance: " << totalBalance << endl;
        } else {
            cout << "Amount should be greater than zero." << endl;
        }
    }

    void spendMoney(double amount) {
        if (amount > 0 && amount <= totalBalance) {
            totalBalance -= amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = "Spent " + std::to_string(amount) + " from wallet.";
            } else {
                for (int i = 1; i < 10; i++) {
                    transactionHistory[i - 1] = transactionHistory[i];
                }
                transactionHistory[9] = "Spent " + std::to_string(amount) + " from wallet.";
            }
            cout << amount << " spent. Total balance: " << totalBalance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void displayTransactionHistory() {
        cout << "Transaction history for " << ownerName << ":" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << transactionHistory[i] << endl;
        }
    }
};

int main() {
    Wallet myWallet("Saad");

    myWallet.addMoney(1000);
    myWallet.spendMoney(200);
    myWallet.addMoney(500);
    myWallet.spendMoney(100);

    myWallet.displayTransactionHistory();

    return 0;
}
