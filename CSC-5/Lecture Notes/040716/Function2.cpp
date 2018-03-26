#include <iostream>
using namespace std;

// function prototypes
float fahrenheitToCelsius(float);
float celsiusToFahrenheit(float);

// main function here
int main()
{
    float f=-40.0;
    
    while( f <= 104) // 104˚F = 40˚C
    {
        float celsius = fahrenheitToCelsius(f);
        float fahrenheit = celsiusToFahrenheit(celsius);
        cout << f << "˚F = " << fahrenheitToCelsius(f) << "˚C" << ", ";
        cout << celsius << "˚C = " << fahrenheit << "˚F" << endl;
        f=f+5;
    }
    return 0; // this line is optional
}

// convert from fahrenheit to celsius, return the result to the calling code
float fahrenheitToCelsius(float fahr)
{
    float celsius;
    celsius = 5*(fahr-32)/9;
    return celsius;
}

// convert form celsius to fahrenheit, return the result to the calling code
float celsiusToFahrenheit(float cels)
{
    float fahr;
    fahr = 1.8*cels+32;
}