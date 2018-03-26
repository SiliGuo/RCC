/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on October 4, 2016, 19:07 PM
 * Purpose: Assignment 1 (Gaddis_8th, Ch11.)
 */

#include <iostream>
#include <iomanip>
using namespace std;

struct MovieData {
    string title; // movie tittle
    string director; // movie director
    unsigned short year; // the year released
    unsigned short time; // the movie running time(in minutes))
};

struct MovieProfit {
    string title; // movie tittle
    string director; // movie director
    unsigned short year; // the year released
    unsigned short time; // the movie running time(in minutes))
    float cost; // movie's production costs
    float revenue; // movie's first year revenue
};

struct Sales {
    string name; // Division Name (such as East, West, North, or South)
    float first; // First-Quarter Sales
    float second; // Second-Quarter Sales
    float third; // Third-Quarter Sales
    float fourth; // Fourth-Quarter Sales
    float total; // Total Annual Sales
    float average; // Average Quarterly Sales
};

struct Weather {
    float rainfall; // Total rainfall
    float high; // High temperature
    float low; // Low temperature
    float average; // Average temperature
};

enum Month {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

struct Soccer {
    string name; // Player's name
    int number; // Player's number
    int score; // points scored by player
};

struct account {
    string name; // customer's name
    string address; // customer's address
    string csz; // City, state, and zip code
    string phone; // Phone number
    float balance; // Balance in account
    string date; // Date of last payment
};

struct Bureau {
    string name; // Speaker's name
    string phone; // Telephone number
    string topic; // Speaking topic
    float fee; // Fee required
};

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void getInfo(MovieData &);
void print(MovieData);
void getInfoo(MovieProfit &);
void printt(MovieProfit);
void salesData(Sales &);
void salesPrint(Sales);
void display(Month);
int search(account, string);
int search(Bureau, string);

int main(int argv, char *argc[]) {
    int inN;
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
                break;
            case 8: problem8();
                break;
            case 9: problem9();
                break;
            case 10: problem10();
                break;
            default: def(inN);
        }
    } while (inN > 0 && inN < 11);
    return 1;
}

void Menu() {
    cout << "********** Problem Menu **********" << endl;
    cout << " 1) 11.1 Movie Data" << endl;
    cout << " 2) 11.2 Movie Profit" << endl;
    cout << " 3) 11.3 Corporate Sales Data" << endl;
    cout << " 4) 11.4 Weather Statistic" << endl;
    cout << " 5) 11.5 Weather Statistics Modification" << endl;
    cout << " 6) 11.6 Soccer Scores" << endl;
    cout << " 7) 11.7 Customer Accounts" << endl;
    cout << " 8) 11.8 Search Function for Customer Accounts Program" << endl;
    cout << " 9) 11.9 Speakers’ Bureau" << endl;
    cout << " 10) 11.10 Search Function for the Speakers’ Bureau Program" << endl;
    cout << "Type 0 to exit \n" << endl;
    cout << "Please choose a number: ";
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void problem1() { //Gaddis 8th, 11.1
    cout << "In problem # 1" << endl << endl;

    //Declare variables from MovieData Structure
    MovieData movie1, movie2;

    //Get the information for two movies
    cout << "The first movie: " << endl << endl;
    getInfo(movie1);
    cout << endl;
    cout << "The second movie: " << endl << endl;
    getInfo(movie2);

    //Print the result on screen in format
    cout << "Movie Data Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "The first movie: " << endl << endl;
    print(movie1);
    cout << "-----------------------------------------" << endl;
    cout << "The second movie: " << endl << endl;
    print(movie2);

    cout << endl << endl;
}

void problem2() { //Gaddis 8th, 11.2
    cout << "In problem # 2" << endl << endl;

    //Declare variables from MovieData Structure
    MovieProfit movie1, movie2;

    //Get the information for two movies
    cout << "The first movie: " << endl << endl;
    getInfoo(movie1);
    cout << endl;
    cout << "The second movie: " << endl << endl;
    getInfoo(movie2);

    //Print the result on screen in format
    cout << "Movie Data Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "The first movie: " << endl << endl;
    printt(movie1);
    cout << "-----------------------------------------" << endl;
    cout << "The second movie: " << endl << endl;
    printt(movie2);

    cout << endl << endl;
}

void problem3() { //Gaddis 8th, 11.3
    cout << "In problem # 3" << endl << endl;

    //Declare variables
    Sales east, west, north, south;
    //store direction names in variables
    east.name = "East";
    west.name = "West";
    north.name = "North";
    south.name = "South";

    //Get information from user
    cout << "For " << east.name << ": " << endl;
    salesData(east);
    cout << endl;

    cout << "For " << west.name << ": " << endl;
    salesData(west);
    cout << endl;

    cout << "For " << north.name << ": " << endl;
    salesData(north);
    cout << endl;

    cout << "For " << south.name << ": " << endl;
    salesData(south);
    cout << endl;

    //Print the result in format
    cout << "Sales Data Report" << endl;
    cout << "-----------------------------------------" << endl;
    salesPrint(east);
    salesPrint(west);
    salesPrint(north);
    salesPrint(south);

    cout << endl << endl;
}

void problem4() {
    cout << "In problem # 4" << endl << endl;

    //Declare the size for the array of the structure
    const int MONTH = 12;
    //Declare an array of structure
    string month[MONTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    Weather yearArr[MONTH];
    for (int i = 0; i < MONTH; i++) {
        //Get information for each month
        cout << "For " << month[i] << "; " << endl;
        do {
            cout << "Enter the total rainfall(mm): ";
            cin >> yearArr[i].rainfall;
        } while (yearArr[i].rainfall < 0); //Rainfall cannot be negative
        do {
            cout << "Enter the highest temperature of the month(F˚): ";
            cin >> yearArr[i].high;
        } while (yearArr[i].high<-100 || yearArr[i].high > 140); //Temperature between -100F˚ and 140 F˚
        do {
            cout << "Enter the lowest temperature of the month(F˚): ";
            cin >> yearArr[i].low;
        } while (yearArr[i].low<-100 || yearArr[i].low > 140 || yearArr[i].low > yearArr[i].high); //Temperature between -100F˚ and 140 F˚
        yearArr[i].average = 0.5 * (yearArr[i].high + yearArr[i].low);
    }

    //Declare variables
    float rainTot, rainAve, tempSum, tempAve, highest = yearArr[0].high, lowest = yearArr[0].low;
    int indexh, indexl;
    //Calculate the total rainfall/temperature of the year and the average rainfall/temperature
    for (int i = 0; i < MONTH; i++) {
        rainTot += yearArr[i].rainfall;
        tempSum += yearArr[i].average;
    }
    rainAve = rainTot / MONTH;
    tempAve = tempSum / MONTH;

    //Calculate the highest and lowest temperature of the year
    for (int i = 0; i < MONTH; i++) {
        if (yearArr[i].high > highest) {
            highest = yearArr[i].high;
            indexh = i;
        } else if (yearArr[i].low < lowest) {
            lowest = yearArr[i].low;
            indexl = i;
        }//end of else if block
    }//end of for loop block

    //Output the result on screen
    cout << "Annual Weather Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    cout << "The average monthly rainfall is: " << rainAve << endl;
    cout << "The total rainfall for the year is: " << rainTot << endl;
    cout << "The highest temperature for the year is: " << highest << " in " << month[indexh] << endl;
    cout << "The lowest temperature for the year is: " << lowest << " in " << month[indexl] << endl;
    cout << "The average of all the monthly average temperatures is: " << tempAve << endl;

    cout << endl << endl;
}

void problem5() {
    cout << "In problem # 5" << endl << endl;

    //Declare the size for the array of the structure
    const int MONTH = 12;
    //Declare an array of structure
    Weather yearArr[MONTH];
    Month temp;

    for (temp = JANUARY; temp <= DECEMBER; temp = static_cast<Month> (temp + 1)) {
        //Get information for each month
        cout << "For ";
        display(temp);
        cout << ": " << endl;
        do {
            cout << "Enter the total rainfall(mm): ";
            cin >> yearArr[temp].rainfall;
        } while (yearArr[temp].rainfall < 0); //Rainfall cannot be negative
        do {
            cout << "Enter the highest temperature of the month(F˚): ";
            cin >> yearArr[temp].high;
        } while (yearArr[temp].high<-100 || yearArr[temp].high > 140); //Temperature between -100F˚ and 140 F˚
        do {
            cout << "Enter the lowest temperature of the month(F˚): ";
            cin >> yearArr[temp].low;
        } while (yearArr[temp].low<-100 || yearArr[temp].low > 140 || yearArr[temp].low > yearArr[temp].high); //Temperature between -100F˚ and 140 F˚
        yearArr[temp].average = 0.5 * (yearArr[temp].high + yearArr[temp].low);
    }

    //Declare variables
    float rainTot, rainAve, tempSum, tempAve, highest = yearArr[0].high, lowest = yearArr[0].low;
    Month indexh, indexl;
    //Calculate the total rainfall/temperature of the year and the average rainfall/temperature
    for (temp = JANUARY; temp <= DECEMBER; temp = static_cast<Month> (temp + 1)) {
        rainTot += yearArr[temp].rainfall;
        tempSum += yearArr[temp].average;
    }
    rainAve = rainTot / MONTH;
    tempAve = tempSum / MONTH;

    //Calculate the highest and lowest temperature of the year
    for (temp = JANUARY; temp <= DECEMBER; temp = static_cast<Month> (temp + 1)) {
        if (yearArr[temp].high > highest) {
            highest = yearArr[temp].high;
            indexh = temp;
        } else if (yearArr[temp].low < lowest) {
            lowest = yearArr[temp].low;
            indexl = temp;
        }//end of else if block
    }//end of for loop block

    //Output the result on screen
    cout << "Annual Weather Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    cout << "The average monthly rainfall is: " << rainAve << endl;
    cout << "The total rainfall for the year is: " << rainTot << endl;
    cout << "The highest temperature for the year is: " << highest << " in ";
    display(indexh);
    cout << endl;
    cout << "The lowest temperature for the year is: " << lowest << " in ";
    display(indexl);
    cout << endl;
    cout << "The average of all the monthly average temperatures is: " << tempAve << endl;

    cout << endl << endl;
}

void problem6() {
    cout << "In problem # 6" << endl << endl;

    //Declare a constant integer
    const int PLAYER = 12;
    //Declare an array
    Soccer score[PLAYER];

    //Get information for each player
    for (int i = 0; i < PLAYER; i++) {
        cout << "For player # " << i + 1 << ": " << endl;

        cout << "Enter the player's name: ";
        cin.ignore();
        getline(cin, score[i].name);

        do {
            cout << "Enter the player's number: ";
            cin >> score[i].number;
        } while (score[i].number < 0);

        do {
            cout << "Enter points scored by this player: ";
            cin >> score[i].score;
        } while (score[i].score < 0);
        cout << endl;
    }
    //Declare variables
    int scoreSum = 0, highest = score[0].score, indexh = 0;

    //Calculate the total points earned by the team
    for (int i = 0; i < PLAYER; i++) {
        scoreSum += score[i].score;

        if (score[i].score > highest) {
            highest = score[i].score;
            indexh = i;
        }//End of if block
    }

    //Output the report on screen
    cout << "Soccer Team Score Report" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < PLAYER; i++) {
        cout << "For player # " << i + 1 << ": " << endl << endl;
        cout << "Player's Name: " << score[i].name << endl;
        cout << "Player's Number: " << score[i].number << endl;
        cout << "Points Scored by Player: " << score[i].score << endl;
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "The total points earned by the team is: " << scoreSum << endl;
    cout << "# " << score[indexh].number << " player " << score[indexh].name << " has earned the most points of " << highest << " points." << endl;

    cout << endl << endl;
}

void problem7() {
    cout << "In problem # 7" << endl << endl;

    //Declare a constant integer
    const int SIZE = 10;

    //Declare variables
    int menu, menuSub;
    account arr[SIZE];
    int k;

    //Output the menu for customer
    do {
        cout << endl << "            Self Service Menu" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "    1. Create a new account." << endl;
        cout << "    2. Change personal information." << endl;
        cout << "    0. Exit by press 0." << endl;
        do {
            cout << "Please choose the service number(1,2,or 0): " << endl;
            cin >> menu;
        } while (menu < 0 || menu > 2);

        //Create a new account
        if (menu == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Please enter your name: ";
                cin.ignore();
                getline(cin, arr[i].name);

                cout << "Please enter your address: ";
                getline(cin, arr[i].address);

                cout << "Please enter your city, state, and zip code(with blank space between): ";
                getline(cin, arr[i].csz);

                cout << "Please enter the date of last payment of your account(mm/dd/yyyy): ";
                getline(cin, arr[i].date);

                cout << "Please enter your telephone number: ";
                cin >> arr[i].phone;

                cout << "Please enter your account balance: ";
                cin >> arr[i].balance;
                cout << endl;
            }
        } else if (menu == 2) {
            cout << endl << "            Self Service Menu" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "    1. Name." << endl;
            cout << "    2. Address." << endl;
            cout << "    3. City, State, and ZIP." << endl;
            cout << "    4. Telephone Number." << endl;
            cout << "    5. Account Balance." << endl;
            cout << "    6. Date of Last Payment." << endl;
            do {
                do {
                    cout << "Please enter the number for the record you would like to change: ";
                    cin >> k;
                } while (k < 0 || k > 10);

                cout << "Please choose the number you want to make changes:" << endl;
                cin >> menuSub;
            } while (menuSub < 1 || menuSub > 6);

            // Do the changes
            switch (menuSub) {
                case 1:
                    cout << "Please enter the name you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].name);
                    break;
                case 2:
                    cout << "Please enter the address you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].address);
                    break;
                case 3:
                    cout << "Please enter the city, state, and zip code(with blank space between) you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].csz);
                    break;
                case 4:
                    cout << "Please enter the telephone number your want to change to: ";
                    cin >> arr[k - 1].phone;
                    break;
                case 5:
                    cout << "Please enter the account balance you want to change to: ";
                    cin >> arr[k - 1].balance;
                    break;
                case 6:
                    cout << "Please enter the date of last payment of your account(mm/dd/yyyy): ";
                    cin.ignore();
                    getline(cin, arr[k - 1].date);
            }//End of switch block
            cout << endl;
        }//End of else if block
    } while (menu != 0);

    //Output the result
    cout << endl << "Customer Account Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(22) << left << "Name: " << arr[i].name << endl;
        cout << setw(22) << left << "Address: " << arr[i].address << endl;
        cout << setw(22) << left << "City, State, and ZIP: " << arr[i].csz << endl;
        cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
        cout << setw(22) << left << "Account Balance: " << arr[i].balance << endl;
        cout << setw(22) << left << "Date of Last Payment: " << arr[i].date << endl;
        cout << endl;
    }
    cout << endl << endl;
}

void problem8() {
    cout << "In problem # 8" << endl << endl;

    //Declare a constant integer
    const int SIZE = 10;

    //Declare variables
    int menu, menuSub;
    account arr[SIZE];
    int k;

    //Output the menu for customer
    do {
        cout << endl << "            Self Service Menu" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "    1. Create a new account." << endl;
        cout << "    2. Change personal information." << endl;
        cout << "    0. Exit by press 0." << endl;
        do {
            cout << "Please choose the service number(1,2,or 0): " << endl;
            cin >> menu;
        } while (menu < 0 || menu > 2);

        //Create a new account
        if (menu == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Please enter your name: ";
                cin.ignore();
                getline(cin, arr[i].name);

                cout << "Please enter your address: ";
                getline(cin, arr[i].address);

                cout << "Please enter your city, state, and zip code(with blank space between): ";
                getline(cin, arr[i].csz);

                cout << "Please enter the date of last payment of your account(mm/dd/yyyy): ";
                getline(cin, arr[i].date);

                cout << "Please enter your telephone number: ";
                cin >> arr[i].phone;

                cout << "Please enter your account balance: ";
                cin >> arr[i].balance;
                cout << endl;
            }
        } else if (menu == 2) {
            cout << endl << "            Self Service Menu" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "    1. Name." << endl;
            cout << "    2. Address." << endl;
            cout << "    3. City, State, and ZIP." << endl;
            cout << "    4. Telephone Number." << endl;
            cout << "    5. Account Balance." << endl;
            cout << "    6. Date of Last Payment." << endl;
            do {
                do {
                    cout << "Please enter the number for the record you would like to change: ";
                    cin >> k;
                } while (k < 0 || k > 10);

                cout << "Please choose the number you want to make changes:" << endl;
                cin >> menuSub;
            } while (menuSub < 1 || menuSub > 6);

            // Do the changes
            switch (menuSub) {
                case 1:
                    cout << "Please enter the name you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].name);
                    break;
                case 2:
                    cout << "Please enter the address you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].address);
                    break;
                case 3:
                    cout << "Please enter the city, state, and zip code(with blank space between) you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].csz);
                    break;
                case 4:
                    cout << "Please enter the telephone number your want to change to: ";
                    cin >> arr[k - 1].phone;
                    break;
                case 5:
                    cout << "Please enter the account balance you want to change to: ";
                    cin >> arr[k - 1].balance;
                    break;
                case 6:
                    cout << "Please enter the date of last payment of your account(mm/dd/yyyy): ";
                    cin.ignore();
                    getline(cin, arr[k - 1].date);
            }//End of switch block
            cout << endl;
        }//End of else if block
    } while (menu != 0);

    //Output the result
    cout << endl << "Customer Account Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(22) << left << "Name: " << arr[i].name << endl;
        cout << setw(22) << left << "Address: " << arr[i].address << endl;
        cout << setw(22) << left << "City, State, and ZIP: " << arr[i].csz << endl;
        cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
        cout << setw(22) << left << "Account Balance: " << arr[i].balance << endl;
        cout << setw(22) << left << "Date of Last Payment: " << arr[i].date << endl;
        cout << endl;
    }

    //Search by the name
    string sName;
    cout << "Enter the name you want to search: ";
    cin >> sName;
    for (int i = 0; i < SIZE; i++) {
        int check;
        check = search(arr[i], sName);
        if (check == 1) {
            cout << endl << "Customer Account Search" << endl;
            cout << "-----------------------------------------" << endl;
            cout << setw(22) << left << "Name: " << arr[i].name << endl;
            cout << setw(22) << left << "Address: " << arr[i].address << endl;
            cout << setw(22) << left << "City, State, and ZIP: " << arr[i].csz << endl;
            cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
            cout << setw(22) << left << "Account Balance: " << arr[i].balance << endl;
            cout << setw(22) << left << "Date of Last Payment: " << arr[i].date << endl;
            cout << endl;
        }
    }
    cout << endl << endl;
}

void problem9() {
    cout << "In problem # 9" << endl << endl;

    //Declare a constant integer
    const int SIZE = 10;

    //Declare variables
    int menu, menuSub;
    Bureau arr[SIZE];
    int k;

    //Output the menu for customer
    do {
        cout << endl << "        Speakers' Bureau Track" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "    1. Enter new data." << endl;
        cout << "    2. Change old data." << endl;
        cout << "    0. Exit by press 0." << endl;
        do {
            cout << "Please choose the service number(1,2,or 0): " << endl;
            cin >> menu;
        } while (menu < 0 || menu > 2);

        //Create a new account
        if (menu == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Please enter speaker's name: ";
                cin.ignore();
                getline(cin, arr[i].name);

                cout << "Please enter speaker's telephone number: ";
                cin >> arr[i].phone;

                cout << "Please enter the speaking topic: ";
                getline(cin, arr[i].topic);

                cout << "Please enter the fee required: ";
                cin >> arr[i].fee;
                cout << endl;
            }
        } else if (menu == 2) {
            cout << endl << "        Speakers' Bureau Track" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "    1. Name." << endl;
            cout << "    2. Telephone Number." << endl;
            cout << "    3. Speaking Topic." << endl;
            cout << "    4. Fee Required." << endl;
            do {
                do {
                    cout << "Please enter the number for the record you would like to change: ";
                    cin >> k;
                } while (k < 0 || k > 10);

                cout << "Please choose the number you want to make changes:" << endl;
                cin >> menuSub;
            } while (menuSub < 1 || menuSub > 6);

            // Do the changes
            switch (menuSub) {
                case 1:
                    cout << "Please enter the name you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].name);
                    break;
                case 2:
                    cout << "Please enter the telephone number you want to change to: ";
                    cin >> arr[k - 1].phone;
                    break;
                case 3:
                    cout << "Please enter the speaking topic you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].topic);
                    break;
                case 4:
                    cout << "Please enter the fee required your want to change to: ";
                    cin >> arr[k - 1].fee;
            }//End of switch block
            cout << endl;
        }//End of else if block
    } while (menu != 0);

    //Output the result
    cout << endl << "Speakers' Bureau Track Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(22) << left << "Name: " << arr[i].name << endl;
        cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
        cout << setw(22) << left << "Speaking Topic: " << arr[i].topic << endl;
        cout << setw(22) << left << "Fee Required: " << arr[i].fee << endl;
        cout << endl;
    }
    cout << endl << endl;
}

void problem10() {
    cout << "In problem # 10" << endl << endl;

    //Declare a constant integer
    const int SIZE = 10;

    //Declare variables
    int menu, menuSub;
    Bureau arr[SIZE];
    int k;

    //Output the menu for customer
    do {
        cout << endl << "        Speakers' Bureau Track" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "    1. Enter new data." << endl;
        cout << "    2. Change old data." << endl;
        cout << "    0. Exit by press 0." << endl;
        do {
            cout << "Please choose the service number(1,2,or 0): " << endl;
            cin >> menu;
        } while (menu < 0 || menu > 2);

        //Create a new account
        if (menu == 1) {
            for (int i = 0; i < SIZE; i++) {
                cout << "Please enter speaker's name: ";
                cin.ignore();
                getline(cin, arr[i].name);

                cout << "Please enter speaker's telephone number: ";
                cin >> arr[i].phone;

                cout << "Please enter the speaking topic: ";
                getline(cin, arr[i].topic);

                cout << "Please enter the fee required: ";
                cin >> arr[i].fee;
                cout << endl;
            }
        } else if (menu == 2) {
            cout << endl << "        Speakers' Bureau Track" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "    1. Name." << endl;
            cout << "    2. Telephone Number." << endl;
            cout << "    3. Speaking Topic." << endl;
            cout << "    4. Fee Required." << endl;
            do {
                do {
                    cout << "Please enter the number for the record you would like to change: ";
                    cin >> k;
                } while (k < 0 || k > 10);

                cout << "Please choose the number you want to make changes:" << endl;
                cin >> menuSub;
            } while (menuSub < 1 || menuSub > 6);

            // Do the changes
            switch (menuSub) {
                case 1:
                    cout << "Please enter the name you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].name);
                    break;
                case 2:
                    cout << "Please enter the telephone number you want to change to: ";
                    cin >> arr[k - 1].phone;
                    break;
                case 3:
                    cout << "Please enter the speaking topic you want to change to: ";
                    cin.ignore();
                    getline(cin, arr[k - 1].topic);
                    break;
                case 4:
                    cout << "Please enter the fee required your want to change to: ";
                    cin >> arr[k - 1].fee;
            }//End of switch block
            cout << endl;
        }//End of else if block
    } while (menu != 0);

    //Output the result
    cout << endl << "Speakers' Bureau Track Report" << endl;
    cout << "-----------------------------------------" << endl;
    cout << setprecision(2) << showpoint << fixed;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(22) << left << "Name: " << arr[i].name << endl;
        cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
        cout << setw(22) << left << "Speaking Topic: " << arr[i].topic << endl;
        cout << setw(22) << left << "Fee Required: " << arr[i].fee << endl;
        cout << endl;
    }

    //Search by the name
    string sName;
    cout << "Enter the name you want to search: ";
    cin >> sName;
    for (int i = 0; i < SIZE; i++) {
        int check;
        check = search(arr[i], sName);
        if (check == 1) {
            cout << endl << "Speakers' Bureau Track Report" << endl;
            cout << "-----------------------------------------" << endl;
            cout << setw(22) << left << "Name: " << arr[i].name << endl;
            cout << setw(22) << left << "Telephone Number: " << arr[i].phone << endl;
            cout << setw(22) << left << "Speaking Topic: " << arr[i].topic << endl;
            cout << setw(22) << left << "Fee Required: " << arr[i].fee << endl;
            cout << endl;
        }
    }
    cout << endl << endl;
}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}

//Function Implementation
//Function that get the movie information

void getInfo(MovieData &movie) {

    //Get information of movie from user
    cout << "Enter the movie name: ";
    cin.ignore();
    getline(cin, movie.title);

    cout << "Enter the director of the movie: ";
    getline(cin, movie.director);

    cout << "Enter the release year of the movie: ";
    cin >> movie.year;

    cout << "How long is the movie(in minutes): ";
    cin >> movie.time;
}
//Function that print the result on screen

void print(MovieData movie) {

    //Print the result in format
    cout << setw(27) << left << "Title: " << movie.title << endl;
    cout << setw(27) << left << "Director: " << movie.director << endl;
    cout << setw(27) << left << "Year Released: " << movie.year << endl;
    cout << setw(27) << left << "Running Time (in minutes): " << movie.time << endl;
}
//Function that get the movie information

void getInfoo(MovieProfit &movie) {

    //Get information of movie from user
    cout << "Enter the movie name: ";
    cin.ignore();
    getline(cin, movie.title);

    cout << "Enter the director of the movie: ";
    getline(cin, movie.director);

    cout << "Enter the release year of the movie: ";
    cin >> movie.year;

    cout << "How long is the movie(in minutes): ";
    cin >> movie.time;

    cout << "Enter the movie's production costs: ";
    cin >> movie.cost;

    cout << "Enter the movie's first-year revenue: ";
    cin >> movie.revenue;
}
//Function that print the result on screen

void printt(MovieProfit movie) {

    //Print the result in format
    cout << setprecision(2) << showpoint << fixed;
    cout << setw(27) << left << "Title: " << movie.title << endl;
    cout << setw(27) << left << "Director: " << movie.director << endl;
    cout << setw(27) << left << "Year Released: " << movie.year << endl;
    cout << setw(27) << left << "Running Time (in minutes): " << movie.time << endl;
    cout << setw(27) << left << "First year's profit/loss: " << movie.revenue - movie.cost << endl;
}
//Function that get sales information from user

void salesData(Sales &input) {

    //Get the sales from data
    do {
        cout << "Enter the first-quarter sale: ";
        cin >> input.first;
    } while (input.first < 0);

    do {
        cout << "Enter the second-quarter sale: ";
        cin >> input.second;
    } while (input.second < 0);

    do {
        cout << "Enter the third-quarter sale: ";
        cin >> input.third;
    } while (input.third < 0);

    do {
        cout << "Enter the fourth-quarter sale: ";
        cin >> input.fourth;
    } while (input.fourth < 0);

    input.total = input.first + input.second + input.third + input.fourth;
    input.average = input.total / 4;
}
//Function that print the result on screen in format

void salesPrint(Sales input) {

    //Print the result in format
    cout << setprecision(2) << showpoint << fixed;
    cout << "For " << input.name << endl;
    cout << setw(25) << left << "First-Quarter Sales: " << input.first << endl;
    cout << setw(25) << left << "Second-Quarter Sales: " << input.second << endl;
    cout << setw(25) << left << "Third-Quarter Sales: " << input.third << endl;
    cout << setw(25) << left << "Fourth-Quarter Sales: " << input.fourth << endl;
    cout << setw(25) << left << "Total Annual Sales: " << input.total << endl;
    cout << setw(25) << left << "Average Quarterly Sales: " << input.average << endl;
    cout << endl;
}

// Function to display the month names

void display(Month m) {
    switch (m) {
        case JANUARY:
            cout << "January";
            break;
        case FEBRUARY:
            cout << "February";
            break;
        case MARCH:
            cout << "March";
            break;
        case APRIL:
            cout << "April";
            break;
        case MAY:
            cout << "May";
            break;
        case JUNE:
            cout << "June";
            break;
        case JULY:
            cout << "July";
            break;
        case AUGUST:
            cout << "August";
            break;
        case SEPTEMBER:
            cout << "September";
            break;
        case OCTOBER:
            cout << "October";
            break;
        case NOVEMBER:
            cout << "November";
            break;
        case DECEMBER:
            cout << "December";
    }
}

//Function that search for names

int search(account ser, string str) {
    if (str.compare(ser.name) == 0) {
        return 1;
    } else {
        return 0;
    }
}
//Function that search for names

int search(Bureau ser, string str) {
    if (str.compare(ser.name) == 0) {
        return 1;
    } else {
        return 0;
    }
}