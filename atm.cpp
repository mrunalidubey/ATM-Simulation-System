#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main() {
    int pin = 1234, enteredPin;

cout << "Enter your PIN: ";
cin >> enteredPin;

if(enteredPin != pin) {
    cout << "Incorrect PIN! Access Denied.\n";
    return 0;
}
    int choice;
    float balance = 1000;
    float dailyLimit = 5000;

    do {
        cout << "\n ATM MENU\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Your balance is: " << balance << endl;
        }
        else if(choice == 2) {
            float deposit;
            cout << "Enter amount to deposit: ";
            cin >> deposit;
            balance += deposit;
            cout << "Amount deposited successfully!\n";
            ofstream logFile("transactions.txt", ios::app);
            logFile << "Deposited: " << deposit << endl;
            logFile.close();
        }
        else if(choice == 3) {
            float withdraw;
            cout << "Enter amount to withdraw: ";
            cin >> withdraw;

            if(withdraw > balance) {
                cout << "Insufficient balance!\n";
            } else {
                balance -= withdraw;
                cout << "Please collect your cash.\n";
            }
            ofstream logFile("transactions.txt", ios::app);
            logFile << "Withdrawn: " << withdraw << endl;
            logFile.close();
        }
        else if(choice == 4) {
            cout << "exit\n";
        }
    

     while(choice != 4);

    return 0;
}