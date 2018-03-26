
// (Exercise 2.5, pg 80 in Gaddis Text)
// This program is for calculating the average of five numbers
#include <iostream>
using namespace std;

int main(){
    
    // Declare five variables of floating point type
    float number1, number2, number3, number4, number5, sum, ave;
    
    number1 = 28;
    number2 = 32;
    number3 = 37;
    number4 = 24;
    number5 = 33;
    
    // Total up number1, number2, ..., number5 and store the result 
    // in a variable called sum
    sum = number1 + number2 + number3 + number4 + number5;
    
    // Divide sum by 5 and store result in variable called average
    ave = sum / 5;
    
    // Output the average to the screen
    cout << "The average of these five numbers is " << ave << endl;
    return 0;
}