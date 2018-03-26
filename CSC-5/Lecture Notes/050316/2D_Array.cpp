#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 4;

void showArray(int [][COLS], int);

int main()
{
    int m[ROWS][COLS]={ {  8, 3,22,23 }, // row 0
                        { 29,10, 5,24 }, // row 1
                        { 20,19,12, 7 }, // row 2
                        { 17,18,11,14 }, // row 3
                        { 37,13,16,31 } }; // row 4
    
    showArray(m,ROWS);
}

void showArray(int m[][COLS], int ROWS)
{
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0;c<COLS;c++)
        {
            cout << m[r][c];
            if (c != COLS-1) cout << ", ";
        }
        cout << endl;
    }
}