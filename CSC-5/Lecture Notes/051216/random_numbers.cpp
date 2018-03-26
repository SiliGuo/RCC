#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cout<<rand()%90+10<<" ";
        }
        cout<<endl;
    }
    
    
    unsigned seed = time(0);
    cout << "seed =" << seed << endl;
    
    srand(0);
    
    for(int i=0;i<20;i++)
    {
        cout << rand()%90+10 << endl;
    }
    
    return 0;
}