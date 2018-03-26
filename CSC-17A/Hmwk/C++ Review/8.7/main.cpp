/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 20, 2016, 9:59 PM
 * Purpose:  C++ Review (Gaddis_8th, 8.7)
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Function Prototype
void sort(string[],int);
int binary(string[],int, string);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Declare two variables in floating point
    const int NUM_NAMES = 20;
    string str;
    
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, "
                               "Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                               "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", 
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth"};

   //Input data for search
    cout << "Enter the name you want to search: ";
    cin >> str;

    //Sort the array first
    sort(names,NUM_NAMES);
    //Use binary search to find the name
    int index_found = binary(names,NUM_NAMES,str);
    bool found = index_found != -1; // if index_found = -1, then false, otherwise expression is true
    cout << str << " was ";
    if ( !found ) cout << "not ";
    cout << "found";

    
    //Exit stage right!
    return 0;
}

void sort(string arr[], int size)
{
    bool swap;
    do
    {
        swap = false;
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1; j<size-1;j++){
            if ( arr[i] > arr[i+1] )
            {			
                string temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=temp;
                swap=true;
            }
            }
        }
    } while ( swap != false );
}

int binary(string arr[], int size, string target)
{
    int first, last;
    first = 0;
    last = size-1;
	
	
    while ( first <= last )	
    {
	int mid = (first+last)/2;
	if ( arr[mid] == target ) return mid;		
	else if ( arr[mid] < target ) first = mid + 1;
	else last = mid - 1;
		
    }
	
    return -1;
}