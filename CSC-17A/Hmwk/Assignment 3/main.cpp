/*
 * File:   main.cpp
 * Author: Sili Guo
 * Created on October 18, 2016, 0:00 PM
 * Purpose: Assignment 1 (Gaddis_8th, Ch10,12.)
 */

#include <iostream>
#include<string>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//User's library
#include "Company.h"

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
int sLength(char *);
void backward(char *);
int count(char *);
float average(char *);
int vowel(char *);
int consonant(char *);
bool openFile(fstream &, string);
void arrayToFile(string, int*, int);
void fileToArray(string, int*, int);

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
    cout << " 1) String Length" << endl;
    cout << " 2) Backward String" << endl;
    cout << " 3) Word Count" << endl;
    cout << " 4) Average Number of Letters" << endl;
    cout << " 5) Vowels and Consonants" << endl;
    cout << " 6) File Head Program" << endl;
    cout << " 7) File Display Program" << endl;
    cout << " 8) Sentence Filter" << endl;
    cout << " 9) Array/File Functions" << endl;
    cout << " 10) Corporate Sales Data Output" << endl;
    cout << "Type 0 to exit \n" << endl;
    cout << "Please choose a number: ";
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void problem1() {//Gaddis 8th 10.1
    cout << "In problem # 1" << endl << endl;
    //Declare variables
    const int SIZE = 51;
    char input[SIZE];
    char *ptr = input;

    //Promote the value from user
    cout << "Enter a string that you want to count characters (No more than " << SIZE - 1 << " characters): ";
    cin.ignore();
    cin.getline(input, SIZE);

    //Calculate the string length and output the result
    cout << input << " contains " << sLength(ptr) << " characters.";

    cout << endl << endl;
}

void problem2() {//Gaddis 8th 10.2
    cout << "In problem # 2" << endl << endl;
    //Declare variables
    const int SIZE = 51;
    char input[SIZE];
    char *ptr = input;


    //Promote value from user
    cout << "Enter a string that you want to see its backward contents (No more than " << SIZE - 1 << " characters): ";
    cin.ignore();
    cin.getline(input, SIZE);

    //Convert to its backward contents and output the result
    cout << "The backward contents of " << input << " is: ";
    backward(ptr);


    cout << endl << endl;
}

void problem3() {//Gaddis 8th 10.3
    cout << "In problem # 3" << endl << endl;
    //Declare variables
    const int SIZE = 51;
    char input[SIZE];
    char *ptr = input;

    //Promote value from user
    cout << "Enter a string that you want to count words (No more than " << SIZE - 1 << " characters): ";
    cin.ignore();
    cin.getline(input, SIZE);

    //Count and output how many words contained in the string variable
    cout << input << " contains " << count(ptr) << " words." << endl;

    cout << endl << endl;
}

void problem4() {//Gaddis 8th 10.4
    cout << "In problem # 4" << endl << endl;
    //Declare variables
    const int SIZE = 51;
    char input[SIZE];
    char *ptr = input;

    //Promote value from user
    cout << "Enter a string that you want to count words and characters (No more than " << SIZE - 1 << " characters): ";
    cin.ignore();
    cin.getline(input, SIZE);

    //Count and output how many words contained in the string variable
    cout << input << " contains " << count(ptr) << " words." << endl;
    //Calculate and output the average number of letters
    cout << "The average number of letters in each word is: " << average(ptr) << endl;

    cout << endl << endl;
}

void problem5() {//Gaddis 8th 10.6
    cout << "In problem # 5" << endl << endl;
    //Declare variables
    const int SIZE = 51;
    char input[SIZE];
    char *ptr = input;
    char choiceMenu;

    //Promote value from user
    cout << "Enter a string you would like to count vowels and consonants (No more than " << SIZE - 1 << " characters): ";
    cin.ignore();
    cin.getline(input, SIZE);

    //Output the choice menu
    do {
        cout << endl << endl;
        cout << "*******************Choice Menu********************" << endl;
        cout << "A) Count the number of vowels in the string" << endl;
        cout << "B) Count the number of consonants in the string" << endl;
        cout << "C) Count both the vowels and consonants in the string" << endl;
        cout << "D) Enter another string" << endl;
        cout << "E) Exit the program" << endl;
        cout << "Please make your choice (in lower-case): ";
        cin >> choiceMenu;

        //Use switch case to make choices
        switch (choiceMenu) {
            case('a'):
                cout << "The number of vowels in the string is: " << vowel(ptr) << endl;
                break;
            case('b'):
                cout << "The number of consonants in the string is: " << consonant(ptr) << endl;
                break;
            case('c'):
                cout << "The number of vowels in the string is: " << vowel(ptr) << endl;
                cout << "The number of consonants in the string is: " << consonant(ptr) << endl;
                break;
            case('d'):
                cout << "Enter another string you would like to count vowels and consonants: ";
                cin.ignore();
                cin.getline(input, SIZE);
                break;
        }
    } while (choiceMenu != 'e');

    cout << endl << endl;
}

void problem6() {//Gaddis 8th 12.1
    cout << "In problem # 6" << endl << endl;
    //Declare variables
    const int LINE = 10;
    int count = 0;
    string name, input;
    fstream readFile;

    //Promote the file name from user
    cout << "Enter the file name that you would like to read first 10 lines: ";
    cin >> name;

    //Open files
    if (openFile(readFile, name)) {
        cout << "File opened successfully." << endl;
        cout << "Now reading first 10 lines data from file..." << endl << endl;
        //Read an item from the file
        getline(readFile, input);

        //If it read successfully, then read the remain lines till 10.
        while (readFile && count < LINE) {
            //Output the line that has been read
            cout << input << endl;

            //Read the remain lines
            getline(readFile, input);
            //Count for loop times until 10
            count++;
        }

        //Close file
        readFile.close();
        cout << endl << "Done." << endl;
    } else {
        cout << "File open error!" << endl;
    }

    cout << endl << endl;
}

void problem7() {//Gaddis 8th 12.2
    cout << "In problem # 7" << endl << endl;
    //Declare variables
    string name, input;
    char again;
    fstream readFile;

    //Promote the file name from user
    cout << "Enter the file name that you would like to read: ";
    cin >> name;

    if (openFile(readFile, name)) {
        cout << "File opened successfully." << endl;
        cout << "Now reading data from file..." << endl << endl;
        //Read an item from the file
        getline(readFile, input);

        //If it read successfully, then read the remain lines till 10.
        while (readFile) {
            //Output the line that has been read
            cout << input << endl;

            //wait for user to press the enter key
            cout << endl << "Please press the enter key to see the next 24 lines." << endl;
            cin.get(again);

            //Read $ as a delimiter
            getline(readFile, input, '$');
            //Count for loop times until 10
        }

        //Close file
        readFile.close();
        cout << endl << "Here are all the data in the file." << endl;
    } else {
        cout << "File open error!" << endl;
    }

    cout << endl << endl;
}

void problem8() {//Gaddis 8th 12.7
    cout << "In problem # 8" << endl << endl;
    //Declare variables
    ifstream inFile;
    ofstream outFile;
    string input, output;
    char ch;
    int count = 0;

    //Promote user for output file names
    cout << "Enter a file name that you would like to output the data: ";
    cin >> output;

    //Open a file for output
    outFile.open(output);
    if (outFile) {
        cout << endl << "Open the output file successfully." << endl;
        cout << "Ready for writing data." << endl << endl;
    }

    //Promote user for input file names
    cout << "Enter the file name that you would like to read data from: ";
    cin >> input;

    //Open the file for input
    inFile.open(input);
    if (inFile) {
        cout << endl << "Open the input file successfully." << endl;
        cout << "Now, reading the data from the file..." << endl << endl;

        //Read a char from input file
        inFile.get(ch);

        //While last read operation was successful, continue.
        while (inFile) {

            //Write lower case char to output file
            if (count == 0 || count == 1) {
                outFile.put(toupper(ch));
            } else {
                outFile.put(tolower(ch));
            }//End block of else
            count++;
            if (ch == '.') {
                count = 0;
            }//End of if block

            //Read another char from input file
            inFile.get(ch);
        }

        //Close two files
        inFile.close();
        outFile.close();
        cout << "File conversion done." << endl;
    } else {
        cout << "File open error!" << endl;
    }


    cout << endl << endl;
}

void problem9() {//Gaddis 8th 12.8
    cout << "In problem # 9" << endl << endl;
    //Declare variables
    fstream file;
    string name;
    int *ptr, size;

    //Promote array size from user
    cout << "Enter a number of size for the array: ";
    cin >> size;

    ptr = new int[size];

    //Prompt user for the int numbers in the array
    cout << "Enter integer numbers for array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "# " << i + 1 << ": ";
        cin >> *(ptr + i);
    }
    cout << endl;

    //Promote user for the file name
    cout << "Enter a file name to store the array: ";
    cin >> name;

    //Write the contents of the array to the file
    arrayToFile(name, ptr, size);

    //Read the contents of the array from the file
    fileToArray(name, ptr, size);

    //Output the contents of the array on the screen
    cout << endl << "The contents of the array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }

    //Delete memory
    delete [] ptr;

    cout << endl << endl;
}

void problem10() {//Gaddis 8th 12.11
    cout << "In problem # 10" << endl << endl;
    //Declare variables
    const int SIZE = 16;
    Company *data = new Company[SIZE];
    Company *read = new Company[SIZE];
    fstream outFile, inFile;

    //Fill the array with name and quarter
    for (int i = 0; i < SIZE; i++) {
        if (i < 4) {
            data[i].name = "East";
        } else if (i < 8) {
            data[i].name = "West";
        } else if (i < 12) {
            data[i].name = "North";
        } else {
            data[i].name = "South";
        }
        if (i % 4 == 0) {
            data[i].quarter = 1;
        } else if (i % 4 == 1) {
            data[i].quarter = 2;
        } else if (i % 4 == 2) {
            data[i].quarter = 3;
        } else {
            data[i].quarter = 4;
        }
    }

    //Promote user to enter the quarter sales of each quarter
    cout << "Enter the following data: " << endl << endl;
    for (int i = 0; i < SIZE; i++) {
        do {
            cout << data[i].name << "_Quarter " << data[i].quarter << ": ";
            cin >> data[i].sale;
        } while (data[i].sale < 0);
    }
    cout << endl;

    //Write the data to a binary file
    outFile.open("Company Data.txt", ios::out | ios::binary);
    if (outFile) {
        outFile.write(reinterpret_cast<char *> (data), sizeof (Company)*SIZE);
    }
    outFile.close();

    //Open the binary file for reading the data
    inFile.open("Company Data.txt", ios::in | ios::binary);
    if (inFile) {
        inFile.read(reinterpret_cast<char *> (read), sizeof (Company)*SIZE);

        //Output the data on screen
        cout << "Data read from the binary file: " << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << cout << read[i].name << "_Quarter " << read[i].quarter << ": " << read[i].sale << endl;
        }
        inFile.close();
    }

    //delete memory
    delete [] data;
    delete [] read;
    data = 0;
    read = 0;

    cout << endl << endl;
}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}

int sLength(char *str) {
    //Return value
    return strlen(str);
}

void backward(char *str) {
    //Declare variables
    char *back = str;
    while (*back != '\0') {
        back++;
    }
    while (back != str) {
        back--;
        cout << *back;
    }
}

int count(char *str) {
    //Declare variables
    int count = 1;

    //Loop though the string, and add 1 to count when there's a white space
    while (*str != '\0') {
        if (*str == ' ') {
            count++;
        }
        str++;
    }

    //Return count to the main function
    return count;
}

float average(char *str) {
    //Declare variables
    int count = 0, word = 1;
    float ave;

    //Loop though the string, and add 1 to count when there's a white space
    while (*str != '\0') {
        if (*str == ' ') {
            word++;
        } else {
            count++;
        }
        str++;
    }

    ave = static_cast<float> (count) / word;

    return ave;
}

int vowel(char *str) {
    //Declare variables
    int count = 0;

    //Loop through the string, add 1 to count if there's a vowel
    while (*str != '\0') {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    //Return number of vowels to main function
    return count;
}

int consonant(char *str) {
    //Declare variables
    int count = 0;

    //Loop through the string
    while (*str != '\0') {
        if (isalpha(*str)) {
            if (*str != 'a' && *str != 'e' && *str != 'i' && *str != 'o' && *str != 'u' && *str != 'A' && *str != 'E' && *str != 'I' && *str != 'O' && *str != 'U') {
                count++;
            }//end block of long if 
        }//end block of if isalpha
        str++;
    }//end block of while loop

    //Return number of consonants to main function
    return count;
}

bool openFile(fstream &file, string name) {
    //Test if open file successfully
    file.open(name, ios::in);
    if (file.fail()) {
        return false;
    } else {
        return true;
    }
}

void arrayToFile(string name, int *arr, int size) {
    //Declare variables
    fstream file;

    //Open file for output in binary mode
    file.open(name, ios::out | ios::binary);

    //Write the contents of the array to the file
    if (file) {
        cout << "Writing the contents to the file..." << endl;
        file.write(reinterpret_cast<char *> (arr), sizeof (int)*size);
    }
    //Close the file
    file.close();
}

void fileToArray(string name, int *arr, int size) {
    //Declare variables
    fstream file;

    //Open file for input in binary mode
    file.open(name, ios::in | ios::binary);

    //Read the contents of the array from the file
    if (file) {
        cout << "Reading the contents of the array from the file..." << endl;
        file.read(reinterpret_cast<char*> (arr), sizeof (int)*size);
    }
    //Close the file
    file.close();
}