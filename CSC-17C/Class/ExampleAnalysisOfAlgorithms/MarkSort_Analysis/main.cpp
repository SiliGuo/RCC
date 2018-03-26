/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 12, 2016, 1:01 PM
 * Purpose:  Shortest Sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants
int ce,clt,cadd,csub,crel,clo;

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void mrkSort(int [],int);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=400;
    int array[SIZE];
    
    //Input data
    fillAry(array,SIZE);
    
    //Display initialization
    //prntAry(array,SIZE,perLine);
    
    //Process -> Map the input data to the output
    mrkSort(array,SIZE);
    cout<<"Equality="<<ce<<endl;
    cout<<"Relation="<<crel<<endl;
    cout<<"Subtraction="<<csub<<endl;
    cout<<"Additions="<<cadd<<endl;
    cout<<"Logic="<<clo<<endl;
    cout<<"Composite="<<ce+crel+csub+cadd+clo<<endl;
    
    //Display/Output solution here
    //prntAry(array,SIZE,perLine);

    //Exit stage right!
    return 0;
}

void mrkSort(int a[],int n){
    ce++;
    for(int i=0;i<n-1;i++){
        crel++;csub++;cadd++;
        ce++;cadd++;
        for(int j=i+1;j<n;j++){
            crel+=2;cadd++;
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
                ce+=3;clo+=3;
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();//Random 2 digit numbers
    }
}