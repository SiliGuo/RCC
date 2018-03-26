#include <iostream>
using namespace std;

int main()
{
    const int ARRAY_SIZE = 6;
    
    float temp[ARRAY_SIZE] = {81.5, 76.6, 82.4, 79.1, 77.7, 86.1 };
    float sum=0.0, average, minimum, maximum;
    
    // sum up all elements in the array
    for(int i=0; i< ARRAY_SIZE; i++)
    {
        sum=sum+temp[i];
    }
    
    // find the largest and smallest values in the array
    minimum=temp[0];
    maximum=temp[0];
    for(int i=1; i< ARRAY_SIZE; i++)
    {
        // if temp[i] is smaller than minimum, set new minimum value to temp[i]
        if ( temp[i] < minimum )
        {
            minimum=temp[i];
        }
        
        // if temp[i] is bigger than maximum, set new maximum value to temp[i]
        if ( temp[i] > maximum )
        {
            maximum=temp[i];
        }
    }
    
    average=sum/ ARRAY_SIZE;
    
    cout << "Average is: " << average << endl;
    cout << "Minimum value is: " << minimum << endl;
    cout << "Maximum value is: " << maximum << endl;
    return 0;
}