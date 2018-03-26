/*
 *            PROGRAMMER: Sili Guo
 *         PROBLEM TITLE: Binary_search_vector_with_bubblesort
 *    PROBLEM DEFINITION: 1. Prompt user to enter the size of vector, and the maximum
 *                        number of the vector, then let compiler to create a series
 *                        of random number as that size, output the vector. 
 *                        2. Use bubble sort to sort numbers from largest to smallest, output
 *                        the vector after bubble sort. 
 *                        3. Prompt user to enter a number for search, use binary search to
 *                        find the number, and output the iteration that the compiler use.
 *                  DATE: 05/17/2016
 *     SYSTEM - HARDWARE: Intel i7, 16GB, RAM
 *            - SOFTWARE: OS X El Capitan, NetBeans IDE 8.1
 *         Input Devices: Keyboard
 *        Output Devices: Screen
 *                                                                          
 *   PROGRAM ASSUMPTIONS: search value, size, max as int type
 *                        four functions, binary_search function as int, others as void
 *                                                              
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// function prototype for display function
void displayList(vector<int> &);

// function prototype for bubble sort function
void bubblesort(vector<int> &);

// output vector
void output(vector<int> &);

// binary search prototype
int binary_search(vector<int> &, int );

// global variable for iterations, must reset to zero after each use
int iterations = 0;

int main()
{
    // declare three variables, and the seed for random numbers 
    int search_value, size, max;
    srand(static_cast<unsigned int>(time(0)));
    
    // prompt user to enter the size of the vector, which has to be greater than zero
    do{
        cout << "Enter the size of the vector (must be greater than zero): ";
        cin >> size;
    } while(size<=0); // loop back if user enter a number less than zero
    
    // prompt user to enter the maximum number of random numbers
    do{
        cout << "Enter the maximum number of random number (must be greater than zero): ";
        cin >> max;
    } while(max<=0); // loop back if user enter a number less than zero
    
    // declare a vector vec as int type
    vector<int> vec;
    
    // create a series of random numbers below the maximum as the size that user entered 
    for(int i=0;i<size;i++) {
        vec.push_back(rand()%max+1);
    }
    
    // output the vector
    displayList(vec);
    
    // use bubblesort to sort numbers from largest to smallest
    bubblesort(vec);
	
    // output the vector after sorted
    cout << "Vector after being sorted: " << endl;
    output(vec);
    cout << endl;
    
    // prompt user to enter the value to search
    cout << "-------------------------------------------" << endl;
    cout << "Enter a value to search for: ";
    cin >> search_value;
    
    // use binary search function to search for the number
    int index_found = binary_search(vec,search_value);
    bool found = index_found != -1; // if index_found = -1, then false, otherwise expression is true
	
    // output the result and the iteration that compiler took
    cout << search_value << " was ";
    if ( !found ) cout << "not ";
    cout << "found";
    if ( found ) cout << " at index " << index_found << endl;
    else cout <<"!" << endl;
    cout << "Took " << iterations << " iterations to execute." << endl;
	
    return 0;
}

// function implementation for display vector on screen
void displayList(vector<int> &vec) {
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if ( i != vec.size()-1 ) cout << ", ";
    }
    cout<<endl;
}

// function implementation for bubblesort
void bubblesort(vector<int> &vec)
{
    bool swap;
    do
    {
	swap = false;
	for(int i=0;i<vec.size();i++)
        {
            if ( vec[i] < vec[i+1] )
            {			
		int temp = vec[i];
		vec[i] = vec[i+1];
		vec[i+1]=temp;
		swap=true;
            }
	}
    } while ( swap != false );
}

// function implementation for display vector after bubblesort
void output(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout << vec[i];
	if ( i != vec.size()-1 ) cout << ", ";
    }
    cout << endl;
}

// function implementation for binary search
int binary_search(vector<int> &vec, int target)
{
    int first, last;
    first = 0;
    last = vec.size()-1;
    
    iterations++;
    
    while( first <= last)
    {
        int mid = (first+last)/2;
        
        cout << "Iteration " << iterations << ": first=" << first << ", last=" << last << ", mid=" << mid << endl;		
		
	if ( vec[mid] == target ) return mid;		
	else if ( vec[mid] > target ) first = mid + 1;
	else last = mid - 1;
		
	iterations++;
    }
	
    return -1;
}