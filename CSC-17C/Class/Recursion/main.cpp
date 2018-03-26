/* 
    Dr. Mark E. Lehr
    April 1st, 2017
    Purpose:  Recursion Examples
 */


//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants

//User Libraries

//Function Prototypes
void   towers(int,int,int,int);
double rSn(double);
double rCs(double);
double expVal(int,int);
int    fib(int);
int    max(int *a,int beg,int end);
int    gcd(int m,int n);
int    bcoeff(int n,int k);

//Execution Begins Here
int main(int argc, char** argv) {
   //Test out the Recursive Binomial Coefficient
   //function
   int nLim=5;
   for(int n=0;n<=nLim;n++){
       for(int k=0;k<=n;k++){
           cout<<bcoeff(n,k)<<" ";
       }
       cout<<endl;
   }
   //Test out the Greatest Common Denominator
   cout<<"\n460/69 gcd = "<<gcd(460,69)<<endl;
   cout<<"\n35/17 gcd = "<<gcd(35,17)<<endl;
   cout<<"\n52/7 gcd = "<<gcd(52,7)<<endl;
   int num=460, den=69, snum, sden;
   int gcdval=gcd(num,den);
   snum=num/gcdval;sden=den/gcdval;
   cout<<"\n"<<num<<"/"<<den<<"="<<snum<<"/"<<sden<<endl;
   //Test out the max function
   int a1[]={5,4,3,2,1};
   int a2[]={2,3,5,4,1};
   int a3[]={1,2,3,4,5};
   cout<<"\nMax value in the array = "<<max(a1,0,sizeof(a1)/sizeof(int))<<endl;
   cout<<"\nMax value in the array = "<<max(a2,0,sizeof(a2)/sizeof(int))<<endl;
   cout<<"\nMax value in the array = "<<max(a3,0,sizeof(a3)/sizeof(int))<<endl;
   //Mutual Recursion
   double angle=30*atan(1)/45;
   cout<<"\nSystem sin("<<angle<<")="<<sin(angle)<<endl;
   cout<<"\nMy sin("<<angle<<")="<<rSn(angle)<<endl;
   cout<<"\nSystem cos("<<angle<<")="<<cos(angle)<<endl;
   cout<<"\nMy cos("<<angle<<")="<<rCs(angle)<<endl;
   //Check the expected value of randomly setting value in an array
   cout<<"\nk*m=10000, n=10000, expected value = "<<expVal(10000,10000)<<endl;
   //Output the Fibonacci
   cout<<"\nFirst 10 Fibonacci Set = {";
   for(int i=0;i<=9;i++){
       cout<<fib(i)<<",";
   }
   cout<<fib(10)<<"}"<<endl;
   //Output the process for solving the towers of hanoi
   cout<<"The Towers of Hanoi"<<endl<<endl;
   towers(2,1,2,3);
   //Exit stage Right
    return 0;
}

    
void towers(int nDisk,int src,int spare,int dest){
    if(nDisk>1)towers(nDisk-1,src,dest,spare);
    cout<<"Move -> "<<src<<" to -> "<<dest<<endl;
    if(nDisk>1)towers(nDisk-1,spare,src,dest);
}
    
double rSn(double angle){
    double tol=1e-8;
    if(angle>-tol&&angle<tol)return angle-angle*angle*angle/6;
    return 2*rSn(angle/2)*rCs(angle/2);
}
    
double rCs(double angle){
    double tol=1e-8;
    if(angle>-tol&&angle<tol)return 1-angle*angle/2+angle*angle*angle*angle/24;
    double csv=rCs(angle/2);
    double snv=rSn(angle/2);
    return csv*csv-snv*snv;
}
    
int max(int *a,int beg,int end){
    if(end-beg<=1)return a[beg];
    int half=(beg+end)/2;
    int m1=max(a,beg,half);
    int m2=max(a,half,end);
    return(m1>m2?m1:m2);
}
    
int gcd(int m,int n){
    if(m==0)return n;
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}
    
int bcoeff(int n,int k){
    if(k==0)return 1;
    if(k==n)return 1;
    return bcoeff(n-1,k-1)+bcoeff(n-1,k);
}

double expVal(int km,int n){
    if(km<=0)return 0;
    if(km==1)return 1;
    return 1+expVal(km-1,n)*(1-1.0f/n);
}

int fib(int n){
    if(n<=0)return 0;
    if(n==1)return 1;
    return fib(n-1)+fib(n-2);
}