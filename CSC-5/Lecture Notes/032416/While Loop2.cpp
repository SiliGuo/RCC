#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter an integer value for n: ";
    cin >> n;
    
    // compute the sum of integers from 1 to n
    // demonstrating the six variations of our while loop
    int sum=0;
    int count=1;
    
    while ( count <= n )
    {
//        // first variation
//        sum=sum+count;
//        count=count+1;
        
//        // second variation
//        sum+=count;
//        count+=1;
        
//        // third variation
//        sum=sum+count;
//        count++;
        
//        // fourth variation
//        sum=sum+count;
//        ++count;
        
//        // fifth variation
//        sum=sum+count++;
        
        // sixth variation
        sum+=count++;
        
        
    }
    
    cout << "Sum of integers from 1 to " << n << " is ";
    cout << sum <<endl;
}