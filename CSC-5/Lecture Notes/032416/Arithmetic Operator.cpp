#include <iostream>
using namespace std;

int main()
{
    int x=5;
    int y=16;
    cout << "x=" << x << ", y=" << y << endl;
    
    x=x+1; // increment x by 1
    y=y-1; // decrement y by 1
    cout << "x=" << x << ", y=" << y << endl;
    
    x+=1; // increment x by 1 again
    y-=1; // decrement y by 1 again
    cout << "x=" << x << ", y=" << y << endl;
    
    x++; // increment x by 1 again
    y--; // decrement y by 1 again
    cout << "x=" << x << ", y=" << y << endl;
    
    // increment and decrements by 2
    x=x+2; // increment x by 2
    y=y-2; // decrement y by 2
    cout << "x=" << x << ", y=" << y << endl;
    
    x+=2; // increment x by 2 again
    y-=2; // decrement y by 2 again
    cout << "x=" << x << ", y=" << y << endl;
    
    int z= x++ + x++; // increment x by 2?
    cout << "x=" << x << ", z=" << z << endl;
    z= y-- + y--; // decrement y by 2?
    cout << "z=" << z << endl << endl;
    cout << "x=" << x << ", y=" << y << endl;
    return 0;
}