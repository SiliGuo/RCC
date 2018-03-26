/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 20, 2016, 7:35 PM
 * Purpose:  C++ Review (Gaddis_8th, 7.6)
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Execution Begin Here!

int main(int argc, char** argv) {
    //Declare  variables, constant variables, and a 2D-array
    const int MONTH = 3, DAY = 30;
    char weather[MONTH][DAY];
    int rainy = 0, cloudy = 0, sunny = 0, rainyT = 0, cloudyT = 0, sunnyT = 0, most = 0;
    string filename = "RainOrShine.txt";

    ifstream inputFile;
    
    //Open the file for reading
    inputFile.open(filename.c_str());

    if (inputFile) {
        //Read txt file row by row
        for (int r = 0; r < MONTH; r++) {
            for (int c = 0; c < DAY; c++) {
                inputFile >> weather[r][c];
            }
        }
    } else break;

    //Close file
    inputFile.close();

    //Output the report in format
    cout << setw(8) << " " << "Weather Report" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << setw(8) << left << "Month" << setw(8) << "Rainy" << setw(8) << "Cloudy" << setw(8) << "Sunny" << endl;

    //Use for loop to record the rainy, cloudy, and sunny days in each months
    for (int r = 0; r < MONTH; r++) {
        for (int c = 0; c < DAY; c++) {
            switch (weather[r][c]) {
                case 'R':rainy++;
                    break;
                case 'C':cloudy++;
                    break;
                case 'S':sunny++;
                    break;
            }//End of swith block
        }//End of column for loop block

        //Output the data for each month
        if (r == 0) {
            cout << setw(8) << "June";
        } else if (r == 1) {
            cout << setw(8) << "July";
        } else {
            cout << setw(8) << "August";
        }
        cout << setw(8) << left << rainy << setw(8) << cloudy << setw(8) << sunny << endl;

        //Record the total rainy, cloudy, and sunny days during the three months
        rainyT += rainy;
        cloudyT += cloudy;
        sunnyT += sunny;

        //Compare and figure out the month that has largest numbers of rainy days
        if (most < rainy) {
            most = r;
        }//End of if block
    }//End of row for loop block
    
    //Output the total report of the three months
    cout << "-----------------------------------------------------" << endl;
    cout << "Total: " << rainyT << "rainy days, " << cloudyT << "cloudy days, and " << sunnyT << "sunny days." << endl;
    
    //Output the month that has largest rainy days
    if (most == 0) {
        cout << "June";
    } else if (most == 1) {
        cout << "July";
    } else {
        cout << "August";
    }
    cout << " has the largest numbers of rainy days." << endl;

    //Exit stage right!
    return 0;
}