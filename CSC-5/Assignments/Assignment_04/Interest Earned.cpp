/* Programmer: Sili Guo
 * Date: 3/8/16
 * Description: this is a program that prompt user to enter the principal,
 *  the interest rate, and the times the interest is compounded during a 
 * year. Compute the amount in savings account, and display the result as
 * a report with well worded, and good format. (Exercise 3.18, pg 145 in Gaddis Text)
 * 
 * Assumption: inputs will be floating point
 * 
 * Variables: rate          -the interest rate
 *            times         -the number of times the interest is compounded during a year
 *            principal     -the balance in the savings account
 *            interest      -the interest in a year
 *            amount        -the total amount in savings account in a year
 */

#include <iostream> // for cin, and cout
#include <cmath> // for pow function
#include <iomanip> // for manipulators for nice output
using namespace std;

int main()
{
    // Declare five variables of floating point type
    float rate, times, principal, interest, amount;
    
    // next several lines are prompting user to enter the principal, rate, and times
    cout << "Enter the principal in your savings account is: ";
    cin  >> principal;
    
    cout << "Enter the interest rate is: ";
    cin >> rate;
    
    cout << "Enter the number of times the interest is compounded is: ";
    cin >> times;
    
    // Calculate the amount, and stored in the variable amount
    amount = principal*pow((1+rate/(100*times)),times);
    interest = amount-principal; // Calculate the interest
    cout << endl; // extra blank line
    cout << "----------------------------------------" << endl; // to make the output looks format
    cout << endl; // extra blank line
    
    // sets width to 19, output value of rate, right justified
    cout << "Interest Rate: " << setw(19) << right << rate <<"%" << endl;
    // sets width to 16, output value of times, right justified
    cout << "Times Compounded: " << setw(16) << right << times << endl;
    // sets width to 9, precision is 2 digits, display fixed, and show decimal point, output value of principal, right justified
    cout << "Principal:              $" << setw(9) << setprecision(2) << right << fixed << showpoint << principal << endl;
    // sets width to 9, precision is 2 digits, display fixed, and show decimal point, output value of interest, right justified
    cout << "Interest:               $" << setw(9) << setprecision(2) << right << fixed << showpoint << interest << endl;
    // sets width to 9, precision is 2 digits, display fixed, and show decimal point, output value of amount, right justified
    cout << "Amount in Savings:      $" << setw(9) << setprecision(2) << right << fixed << showpoint << amount << endl;
    
    return 0;
}