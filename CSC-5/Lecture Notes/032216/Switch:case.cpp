#include <iostream>
using namespace std;

int main()
{
    int choice;    
    bool validInput=false;
    
    while ( !validInput )
    {
    
        // output a simple menu
        cout << "Calculator" << endl;
        cout << "1. Add Two Numbers" << endl;
        cout << "2. Subtract Two Numbers" << endl;
        cout << "3. Multiply Two Numbers" << endl;
        cout << "4. Divide Two Numbers" << endl;
        cout << "5. Quit" << endl;
        cout << endl;
    
        // prompt for choice and get choice from user
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // demonstrate usage of switch/case
        switch(choice)
        {
            // user chooses choice 1
            case 1:
                cout << "You want to add two numbers?" << endl;
                validInput=true;
                break;
            
            // user chooses choice 2
            case 2:
                cout << "You want to subtract two numbers?" << endl;
                validInput=true;
                break;
            
            // user choose choice 3
            case 3:
                cout << "You want to multiply two numbers?" << endl;
                validInput=true;
                break;
            
            // user choose choice 4
            case 4:
                cout << "You want to divide two numbers?" << endl;
                validInput=true;
                break;
            
            // user chooses choice 5
            case 5:
                cout << "Your really want to quit this awesome program???" << endl;
                validInput=true;
                break;
            
            default:
                cout << "You must choose a number between 1 and 5, try again?????" << endl;
                validInput=false;
        } // end of switch block
    } // end of while loop
} // end of main function