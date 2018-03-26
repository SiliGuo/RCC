/* 
 * File:   main.cpp
 * Author: Your Name
 * Created on March 1, 2017, 6:30 PM
 * Purpose:  Simplest sorting algorithm
 */

//System Libraries
#include <iostream>  //I/O
#include <cstdlib>   //Random function
#include <ctime>     //Time
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *filAray(int);
void prntAry(int[],int,int);
void markSrt(int [],int);
void destroy(int []);

//Execution Begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=2e2;//Initialize
    int n=size/2;
    int *array=filAray(size);
    
    //Print the array
    prntAry(array,n,10);
    
    //Map inputs to outputs
    markSrt(array,n);
    
    //Display outputs
    prntAry(array,size,10);
    
    //Clean up memory
    destroy(array);

    //Exit Stage right!
    return 0;
}

void destroy(int a[]){
    delete []a;
}

void markSrt(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
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

int *filAray(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10-99]
    }
    return a;
}