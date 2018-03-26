#include <iostream>
using namespace std;

int main()
{
    long int n;
    
    // prompt for a value of n
    cout << "Enter a positive integer for N: ";
    cin >> n;
    
    long int sum=0;
    long int counter=1;
    
    while(counter <= n)
    {
        sum = sum + counter;
        counter = counter + 1;
    }
    
    cout << "Sum of integers from 1 to " << n << " is: " << sum << endl;
}