#include <iostream>
using namespace std;

int main()
{
    float temp[6];
    float sum = 0.0, average;
    
    // initialize the array with individual values
    temp[0]=81.5;
    temp[1]=76.6;
    temp[2]=82.4;
    temp[3]=79.1;
    temp[4]=77.7;
    temp[5]=86.1;
    
    for(int i=0; i<6; i++)
    {
        sum=sum+temp[i];
    }
    
    average=sum/6;
    
    cout << "Average is: " << average << endl;
    return 0;
}