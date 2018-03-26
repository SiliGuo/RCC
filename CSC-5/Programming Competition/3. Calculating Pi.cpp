// programming competition "Calculating Pi"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double pi=0;
    const int SIZE = 1000000;
    cout << "Accuracy set at: 1000000" << endl;
    cout << endl;

    cout << setw(16) << left << "term" << setprecision(8) << fixed << showpoint << "pi" << endl;

    for (int i = 1; i <= SIZE; i++) {
        pi += (4 * pow(-1, (i + 1))) / (2*i - 1);
        if (i%100000==0)
            cout << setw(16) << i << setprecision(8) << fixed << showpoint << pi << endl;
    }
}