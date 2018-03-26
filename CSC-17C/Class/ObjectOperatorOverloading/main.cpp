/* 
 * Author: Dr. Mark E. Lehr
 * Created on October 13, 2016, 4:32 PM
 * Purpose:  Complex object to use in Data-Structures for testing purposes
 *           2D square matrix with operator overloading, Copy Construction
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Object.h"

//Global Constants Here

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Create a static array of Objects that are themselves arrays
    const int SIZE=100;
    Object sArray[SIZE];
    
    //Output the last element in the array using << overloading
    cout<<"Last element in the Static Array of Objects = "<<sArray[SIZE-1];
    
    //Create a dynamic array of Objects that are themselves arrays
    Object *dArray=new Object[SIZE];  //This just allocates memory, nothing more
    
    //Fill the Dynamic with all the same objects
    Object fill1(3);      //Create a 3x3 with the constructor
    Object fill2(fill1);  //Copy construct this object from the first
    Object fill3=fill2;   //Try the overloaded equality operator
    sArray[SIZE-1]=fill3; //Another overloaded equality operator
    for(int count=0;count<SIZE;count++){
        if(count<SIZE/3)dArray[count]=fill1;
        else if(count<2*SIZE/3) dArray[count]=fill2;
        else dArray[count]=fill3;
    }
    
    //How many elements in the match the static or dynamic array
    int statSum=0,dynSum=0;
    for(int count=0;count<SIZE;count++){
        if(dArray[count]==fill1)dynSum++;  //Using the comparison op ==
        if(sArray[count]==fill2)statSum++; //Using the comparison op ==
    }    
    
    //Output the matches
    cout<<"There are "<<dynSum <<" matches in Dynamic Array"<<endl;
    cout<<"There are "<<statSum<<" matches in Static Array"<<endl<<endl;
    
    //Check the fill array against the elements in the Array
    cout<<"The fill array used in the Dynamic Array"<<fill1;
    
    //Output the last element in the array using the toString() function
    cout<<"Last element in the Dynamic Array of Objects = "
            <<dArray[SIZE-1].toString();
    cout<<"Last element in the Static Array of Objects = "
            <<sArray[SIZE-1].toString();

    //Exit Stage Right!
    return 0;
}