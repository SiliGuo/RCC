#include <iostream>
using namespace std;

bool search(float[], int, float);

int main()
{
    const int ARRAY_SIZE = 5;
    
    float myArray[ARRAY_SIZE];
    
    cout << "Hi there! Please enter " << ARRAY_SIZE << " floating point numbers..." << endl;
    
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        cout << "Enter value for element #" << i << ": ";
        cin >> myArray[i];
    }
    
    cout << "Enter a number for me to search for: ";
    float target;
    
    cin >> target;
    
    bool found_it = false;
    
    cout << "Well... I did ";
    found_it = search(myArray, ARRAY_SIZE, target);
    
    if (found_it == false)
    {
        cout << "not ";
    }
    
    cout << "find the number!!!" << endl;
}

/// implementation of search
bool search(float a[], int size, float target)
{
    bool found=false;
    for(int i=0;i<size;i++)
    {
        if ( a[i]==target )
        {
            found=true;
            break;
        }
    }
    return found;
}
