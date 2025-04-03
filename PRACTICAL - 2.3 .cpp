#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:

    BankAccount() {
        balance = 0.0;
        accountHolderName = "Unknown";
        accountNumber = "0";
    }

    BankAccount(string name, string accNum, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $ " << balance << endl;
    }

    void setAccountHolderName(const string &name) {
        accountHolderName = name;
    }

    void setAccountNumber(const string &accNum) {
        accountNumber = accNum;
    }

    void setBalance(double initialBalance) {
        balance = initialBalance;
    }
};

int main() {
    string name, accNum;
    double balance, amount;
    int choice;

    cout << "Enter account holder's name : ";
    getline(cin, name);

    cout << "Enter account number : ";
    getline(cin, accNum);

    cout << "Enter initial balance : $ ";
    cin >> balance;

    BankAccount account(name, accNum, balance);

    do {
        cout << "\nMenu : 1.Deposit\n";
        cout << "       2.Withdraw\n";
        cout << "       3.Display Account Details\n";
        cout << "       4.Exit\n";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount : $ ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount : $ ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                cout << "\nAccount Details : \n";
                account.displayAccountDetails();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

