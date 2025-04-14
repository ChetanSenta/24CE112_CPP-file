#include <iostream>
#include <map>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

    static int totalAccounts;

public:

    BankAccount() : accountNumber(0), name(""), balance(0.0) {}

    BankAccount(int accNum, const string& accName, double accBalance)
        : accountNumber(accNum), name(accName), balance(accBalance) {
        totalAccounts++;
    }

    friend void transferMoney(BankAccount& from, BankAccount& to, double amount);

    void display() const {
        cout << "Account Number: " << accountNumber << ", Name: " << name
             << ", Balance: $" << balance << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;

void transferMoney(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer Successful: $" << amount << " from Account "
             << from.accountNumber << " to Account " << to.accountNumber << ".\n";
    } else {
        cout << "Transfer Failed: Insufficient balance in Account " << from.accountNumber << ".\n";
    }
}

int main() {
    map<int, BankAccount> accounts;
    int choice;

    do {
        cout << "Bank Account Management System:\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Transfer Money\n";
        cout << "4. Total Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int accountNumber;
            string name;
            double balance;

            cout << "Enter Account Number : ";
            cin >> accountNumber;
            cout << "Enter Name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Balance : ";
            cin >> balance;

            accounts[accountNumber] = BankAccount(accountNumber, name, balance);
            cout << "Account created successfully!\n" << endl ;
            break;
        }
        case 2: {
            if (accounts.empty()) {
                cout << "No accounts to display.\n";
            } else {
                for (const auto& [accNum, account] : accounts) {
                    account.display();
                }
            }
            cout << endl ;
            break;
        }
        case 3: {
            int fromAcc, toAcc;
            double amount;

            cout << "Enter Sender's Account Number : ";
            cin >> fromAcc;
            cout << "Enter Receiver's Account Number : ";
            cin >> toAcc;
            cout << "Enter Amount to Transfer : ";
            cin >> amount;

            if (accounts.find(fromAcc) != accounts.end() && accounts.find(toAcc) != accounts.end()) {
                transferMoney(accounts[fromAcc], accounts[toAcc], amount);
            } else {
                cout << "Invalid account number(s) provided.\n";
            }
            cout << endl ;
            break;
        }
        case 4: {
            cout << "Total Number of Accounts : " << BankAccount::getTotalAccounts() << endl << endl ;
            break;
        }
        case 5: {
            cout << "Exiting the program. Goodbye!\n" << endl ;
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n" << endl ;
        }
    } while (choice != 5);

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
