#include <iostream>
using namespace std;

long *my_fun(int);

int main() {
    const int MAX_TERMS=50;
    long *fibo = my_fun(MAX_TERMS);
    
    for(int i=0;i<MAX_TERMS;i++)
        cout << "fibonacci[" << i << "]= " << fibo[i] << endl;
    
    return 0;
}

long *my_fun(int n) {
    long *ptr = new long[n];
    *(ptr+0) = 1;
    *(ptr+1) = 1;
    for(int i=2;i<n;i++)
        *(ptr+i) = *(ptr+i-2)+ *(ptr+i-1);
    
    return ptr;
}