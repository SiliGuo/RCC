#include <iostream>
using namespace std;

int main() 
{
    int x = 10, y = 8;

    cout << "Enter an integer value for x: ";
    cin >> x;
    cout << "Enter an integer value for y: ";
    cin >> y;
    
    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //test x > y
    if (x > y) 
    {
        cout << x << ">" << y << endl;
    }

    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //test x < y
    if ( x< y) 
    {
        cout << x << "<" << y << endl;
    }

    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //test x = y
    if (x = y)
    {
        cout << x << "=" << y << endl;
    }
    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    x=10;
    //test x == y
    if (x == y)
    {
        cout << x << "==" << y << endl;
    }
    
    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //test x != y
    if (x != y)
    {
        cout << x << "!=" << y << endl;
    }
    //x=10;
    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //test x != y
    if (x != y)
    {
        cout << x << "!=" << y << endl;
    }
    
    cout << "current value of x: " << x << endl;
    cout << "current value of y: " << y << endl;
    //x=10;
    //test x >= y
    if (x >= y)
    {
        cout << x << ">=" << y << endl;
    }
    
    //cout << "current value of x: " << x << endl;
    //cout << "current value of y: " << y << endl;
    //x=10;
    //test x <= y
    if (x <= y)
    {
        cout << x << "<=" << y << endl;
    }

    cout << "Thanks for running this demonstration program." << endl;
}