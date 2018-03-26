#include <iostream>
using namespace std;

// function prototype for bubblesort function
void bubblesort(int [], int);

// output array
void output(int [], int);

// binary search prototype
int binary_search(int [], int, int);

// global variable for iterations, must reset to zero after each use
int iterations = 0;

int main()
{
    int a[] = { 5,3,8,6,4,1,7,9,15,13,18,16,14,11,17,19 };
	
    int search_value;
		
    cout << "Enter a value to find: ";
    cin >> search_value;
		
    cout << "Array before being sorted: " << endl;
    output(a,16);
    cout << endl;
	
    bubblesort(a,16);
	
    cout << "Array after being sorted: " << endl;
    output(a,16);
    cout << "Took " << iterations << " iterations to execute." << endl;
    iterations=0;
	
    cout << endl;
	
    int index_found = binary_search(a,16,search_value);
    bool found = index_found != -1; // if index_found = -1, then false, otherwise expression is true
	
    // nice output
    cout << search_value << " was ";
    if ( !found ) cout << "not ";
    cout << "found";
    if ( found ) cout << " at index " << index_found << endl;
    else cout <<"!" << endl;
    cout << "Took " << iterations << " iterations to execute." << endl;
	
    return 0;
}

// function implementation for bubblesort
void bubblesort(int arr[], int size)
{
    bool swap;
    do
    {
        swap = false;
        for(int i=0;i<size-1;i++)
        {
            iterations++;
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

int binary_search(int arr[], int size, int target)
{
    int first, last;
    first = 0;
    last = size-1;
	
    iterations++;
	
    while ( first <= last )	
    {
	int mid = (first+last)/2;
	// debug code below		
	cout << "Iteration " << iterations << ": first="<<first<<", last="<<last<<", mid="<<mid<<endl;		
		
	if ( arr[mid] == target ) return mid;		
	else if ( arr[mid] < target ) first = mid + 1;
	else /*if ( arr[mid] > target )*/ last = mid - 1;
		
	iterations++;
    }
	
    return -1;
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