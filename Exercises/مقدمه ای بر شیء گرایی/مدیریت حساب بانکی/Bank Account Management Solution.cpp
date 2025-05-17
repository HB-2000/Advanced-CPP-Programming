#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNum, double bal) : ownerName(name), accountNumber(accNum), balance(bal) {}

    // Destructor
    ~BankAccount() {
        cout << "Account " << accountNumber << " is being closed." << endl;
    }

    // Getter methods
    string getOwnerName() { return ownerName; }
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    // Setter methods
    void setOwnerName(string name) { ownerName = name; }
    void setBalance(double bal) {
        if (bal >= 0) {
            balance = bal;
        }
    }

    // Other methods
    void deposit(double amount) {
        if (amount > 0 && amount <= 10000) {
            balance += amount;
            cout << fixed << setprecision(2) << "Deposited " << amount << ", new balance is " << balance << "." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance && amount <= 10000) {
            balance -= amount;
            cout << fixed << setprecision(2) << "Withdrew " << amount << ", new balance is " << balance << "." << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void transfer(BankAccount& target, double amount) {
        if (amount > 0 && amount <= balance && amount <= 10000) {
            balance -= amount;
            target.setBalance(target.getBalance() + amount);
            cout << fixed << setprecision(2) << "Transferred " << amount << " to account " << target.getAccountNumber()
                 << ", new balance is " << balance << "." << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance." << endl;
        }
    }

    void checkBalance() {
        cout << fixed << setprecision(2) << "Current balance is " << balance << "." << endl;
    }

    void applyInterest(double rate) {
        if (rate >= 0 && rate <= 10000) {
            double interest = balance * (rate / 100);
            balance += interest;
            cout << fixed << setprecision(2) << "Interest applied, new balance is " << balance << "." << endl;
        } else {
            cout << "Invalid interest rate." << endl;
        }
    }
};

int main() {
    // Read data for first account
    string name1;
    int accNum1;
    double balance1;
    cin >> name1 >> accNum1 >> balance1;

    // Read data for second account
    string name2;
    int accNum2;
    double balance2;
    cin >> name2 >> accNum2 >> balance2;

    // Create two BankAccount objects
    BankAccount account1(name1, accNum1, balance1);
    BankAccount account2(name2, accNum2, balance2);

    // Read number of operations
    int q;
    cin >> q;

    // Process operations
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            double amount;
            cin >> amount;
            account1.deposit(amount);
        } else if (op == 2) {
            double amount;
            cin >> amount;
            account1.withdraw(amount);
        } else if (op == 3) {
            double amount;
            cin >> amount;
            account1.transfer(account2, amount);
        } else if (op == 4) {
            account1.checkBalance();
        } else if (op == 5) {
            double rate;
            cin >> rate;
            account1.applyInterest(rate);
        }
    }

    return 0;
}