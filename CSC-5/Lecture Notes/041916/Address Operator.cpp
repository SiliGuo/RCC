#include <iostream>
using namespace std;

// function prototype for add function
int add(int, int);
float add(float = 0.0, float = 0.0);
float add(int, float);

bool isEven(int);
// int add(int &, int &);

// main function
int main()
{
    // declare two integer variables
    int x, y;
    
    cout << "Enter a value for X: ";
    cin >> x;
    
    cout << "Enter a value for Y: ";
    cin >> y;
    
    // declare two float variables
    float fx, fy;
    
    cout << "Enter a floating point value for X: ";
    cin >> fx;
    
    cout << "Enter a floating point value for Y: ";
    cin >> fy;
    
    int sum = add(x,y);
    float sum2 = add( fx, fy );
    float sum3 = add( x, fy );
    
    if (isEven(x))
    {
        cout << x << " is even!!!" << endl;
    }
    else cout << x << "is odd!!!" << endl;
    if (isEven(x-1))
    {
        cout << x-1 << " is even!!!" << endl;
    }
    else cout << x-1 << "is odd!!!" << endl;
    if (isEven(x+1))
    {
        cout << x+1 << " is even!!!" << endl;
    }
    else cout << x+1 << " is odd!!!" << endl;
    
    cout << "add(int,int): The sum of " << x << " and " << y << " is " << sum << endl;
    cout << "add(float,float): The sum of " << fx << " and " << fy << " is " << sum2 << endl;
    cout << "add(int,float): The sum of " << x << " and " << fy << " is " << sum3 << endl;
    
    cout << "add() is " << add() << endl;
    cout << "add(y) is " << add(y) << endl;
    return 0;
    
}

// function implementation
bool isEven(int x)
{
    static int count;
    count++;
    cout << "This function called " << count << " times." << endl;
    return ( x%2==0 );
}
int add(int a, int b)
{
    int result;
    
    result = a + b;
    return result;
    
}

float add(float a, float b)
{
    float result;
    
    result = a + b;
    return result;
    
}

float add (int a, float b)
{
    float result;
    
    result = a + b;
    return result;
    
}
//int add(int &a, int &b)
//{
//    int result;
//    
//    a=5;
//    
//    result = a + b;
//    return result;
//}