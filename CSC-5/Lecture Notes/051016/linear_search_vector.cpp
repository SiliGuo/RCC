#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a { 5,3,8,6,4,1,7,9 };
	
    int search_value;
    int iterations = 0;
	
    cout << "Enter a value to find: ";
    cin >> search_value;
	
    bool found = false;
	
    for(int i=0;i<8;i++)
    {
	iterations++;
	if ( a[i]==search_value )
	{
            found = true;
            break;
	}
    }
	
    cout << search_value << " was ";
    if ( !found ) cout << "not ";
    cout << "found!" << endl;
    cout << "It took " << iterations << " iterations to execute." << endl;
	
    return 0;
}