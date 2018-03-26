// Programming Competition "Credit Card Limit Calculator"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int account;
    float balance, charges, credits, limit, new_balance;
    
    do {
        do {
            cout << "Enter account number (or -1 to quit): ";
            cin >> account;
        } while (account < 0 & account != -1);
        
        if (account == -1) break;
        
        do {
            cout << "Enter beginning balance: ";
            cin >> balance;
        } while (balance < 0);
        
        do {
            cout << "Enter total charges: ";
            cin >> charges;
        } while (charges < 0);
        
        do {
            cout << "Enter total credits: ";
            cin >> credits;
        } while (credits < 0);
        
        do {
            cout << "Enter credit limit: ";
            cin >> limit;
        } while (limit < 0);
        
        new_balance = balance + charges - credits;
        
        cout << "New balance is " << setprecision(2) << fixed << showpoint << new_balance << endl;
        
        if (new_balance > limit) {
            cout << "Account: " << account << endl;
            cout << "Credit limit: " << setprecision(2) << fixed << showpoint << limit << endl;
            cout << "Balance: " << setprecision(2) << fixed << showpoint << new_balance << endl;
            cout << "Credit Limit Exceeded." << endl;
        } // end of if block
        cout << endl;
        
    } while (account != -1);
}