// Programming Competition "Gas Mileage"

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float miles, gallons, mpg, tmiles = 0, tgallons = 0, total = 0;

    do {
        do {
            cout << "Enter miles driven (-1 to quit): ";
            cin >> miles;
        } while (miles <= 0 & miles != -1);
        
        if (miles == -1) break;
        
        do {
            cout << "Enter gallons used: ";
            cin >> gallons;
        } while (gallons <= 0);

        mpg = miles / gallons;
        cout << "MPG this tankful: " << setprecision(3) << fixed << mpg << showpoint << endl;

        tmiles += miles;
        tgallons += gallons;
        total = tmiles / tgallons;
        cout << "Total MPG: " << setprecision(3) << fixed << total << showpoint << endl;
        cout << endl;
    } while (miles != -1);
    return 0;
}