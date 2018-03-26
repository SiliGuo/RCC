#include <iostream>
using namespace std;

int main()
{
    int x; // some integer x
    
    // prompt for a value of x and fetch the value from the keyboard
    cout << "Enter an integer value for X: ";
    cin >> x;
    
    int y; // some integer y
    int z; // some integer z
    
    // if x > 0 we set y to 10, otherwise set y to 5.
//    if ( x>0 )
//    {
//        if ( x%2==0 )
//        {
//            y=3;
//            z=2;
//        }
//        else
//        {
//            y=10;
//            z=4;
//        }
//        
//    }
//    else 
//    {
//        if ( x%11==0 )
//        {
//            y=5;
//            z=1;  
//        }
//        else
//        {
//            y=15;
//            z=31;
//        }
//        
//    }
    
    // demonstrate using conditional operator ?: to do the same thing as line 14 through 22
//    x>0? y=10: y=5;
//    x>0? z=4: z=1;
//    x>0? (y=10, z=4): (y=5,z=1);
//    y= x>0? 10:5;
    x>0 ? x%2==0 ? (y=3, z=2) : (y=10, z=4) : x%11==0 ? (y=5, z=1) : (y=15,z=31);
    
    // output results
    cout << "x is " << x << ", and y is " << y;
    cout << ", and z is " << z << endl;
}