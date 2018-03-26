#include <iostream>
using namespace std;

// function prototype for bubblesort function
void bubblesort(int [], int);

// output array
void output(int [], int);

int main()
{
    int a[] = { 5,3,8,6,4,1,7,9 };
	
    int search_value;
    int iterations = 0;
	
    cout << "Enter a value to find: ";
    cin >> search_value;
	
    bool found = false;
	
    for(int i=0;i<8;i++)
    {
	iterations++;
	if ( a[i]==search_value )
	{
            found = true;
            break;
	}
    }
	
    cout << search_value << " was ";
    if ( !found ) cout << "not ";
    cout << "found!" << endl;
    cout << "It took " << iterations << " iterations to execute." << endl;
	
    cout << "Array before being sorted: " << endl;
    output(a,8);
    cout << endl;

    bubblesort(a,8);
	
    cout << "Array after being sorted: " << endl;
    output(a,8);
    cout << endl;

    return 0;
}

// function implementation for bubblesort
void bubblesort(int arr[], int size)
{
    bool swap;
    do
    {
	swap = false;
	for(int i=0;i<size;i++)
        {
            if ( arr[i] > arr[i+1] )
            {			
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1]=temp;
		swap=true;
            }
	}
    } while ( swap != false );
}

void output(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i];
	if ( i != size-1 ) cout << ", ";
    }
    cout << endl;
}