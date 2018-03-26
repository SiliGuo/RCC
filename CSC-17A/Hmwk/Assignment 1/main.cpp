/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on September 27, 2016, 22:42 PM
 * Purpose: Assignment 1 (Gaddis_8th, Ch9.); Mean median mode problem
 */

#include <iostream>
using namespace std;

//Function prototype
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
int *allocate(int);
void sort(int *, int);
void average(int *, int);
void averageD(int *, int);
void sort(int *, string *, int);
int doSomething(int *, int *);
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);
void arrSelecSort(int *[], int);
int *reverse(int *, int);
float mean(int *, int);
float median(int *, int);
int *mode(int *, int);

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
            default: def(inN);
        }
    } while (inN > 0 && inN < 10);
    return 1;
}

void Menu() {
    cout << "********** Problem Menu **********" << endl;
    cout << " 1) 9.1 Array Allocator " << endl;
    cout << " 2) 9.2 Test Score #1" << endl;
    cout << " 3) 9.3 Drop Lowest Score" << endl;
    cout << " 4) 9.4 Test Score #2" << endl;
    cout << " 5) 9.5 Pointer Rewrite" << endl;
    cout << " 6) 9.6 Case Study Modification #1" << endl;
    cout << " 7) 9.7 Case Study Modification #2" << endl;
    cout << " 8) 9.10 Reverse Array" << endl;
    cout << " 9) Mean Median Mode Problem" << endl;
    cout << "Type 0 to exit \n" << endl;
    cout << "Please choose a number: ";
}

int getN() {
    int inN;
    cin>>inN;
    return inN;
}

void problem1() { //Gaddis 8th, 9.1
    cout << "In problem # 1" << endl << endl;

    //Declare variables
    int *ptr;
    int size;

    //Input the size of the array
    cout << "Enter a number for the size of the array: ";
    cin >> size;

    // Dynamic array
    ptr = allocate(size);

    //Output the array on screen
    cout << endl << "The array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }

    //Delete memory
    delete [] ptr;
    ptr = 0;
    cout << endl << endl;

}

void problem2() { //Gaddis 8th, 9.2
    cout << "In problem # 2" << endl << endl;
    
    //Declare variables
    int size;

    // Input the size of the array, make sure it is greater than 0
    do {
        cout << "Enter how many test scores you would like to input: ";
        cin >> size;
    } while (size < 1);

    //Declare a dynamic array
    int *ptr = new int[size];
    //Input numbers in dynamic array
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter the test score # " << i + 1 << ": ";
            cin >> *(ptr + i);
        } while (*(ptr + i) < 0);
    }

    //Output the array
    cout << endl << "The array for test score is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    //Sort the array with ascending order
    sort(ptr, size);
    cout << "The array of ascending order is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    //Find the average of test scores
    average(ptr, size);

    //Delete memory
    delete [] ptr;
    ptr = 0;
    cout << endl << endl;

}

void problem3() { //Gaddis 8th, 9.3
    cout << "In problem # 3" << endl << endl;
    
    //Declare variables
    int size;
    //Input the size of array
    do {
        cout << "Enter how many test scores you would like to input: ";
        cin >> size;
    } while (size < 1);

    //Declare dynamic array
    int *ptr = new int[size];
    //Input numbers in dynamic array
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter the test score # " << i + 1 << ": ";
            cin >> *(ptr + i);
        } while (*(ptr + i) < 0);
    }

    //Output the array on screen
    cout << endl << "The array for test score is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    //Sort the array of ascending order
    sort(ptr, size);
    cout << "The array of ascending order is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    //Output array after dropped the lowest score
    cout << "The array after dropped the lowest score is:" << endl;
    for (int i = 1; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    //Calculate the average of the array
    averageD(ptr, size);

    //Delete memory
    delete [] ptr;
    ptr = 0;
    cout << endl << endl;

}

void problem4() { //Gaddis 8th, 9.4
    cout << "In problem # 4" << endl << endl;
    
    //Declare variables
    int size;
    //Input the size of the array
    do {
        cout << "Enter how many test scores you would like to input: ";
        cin >> size;
    } while (size < 1);

    //Declare dynamic arrays
    int *ptr = new int[size];
    string *str = new string[size];
    //Input the score and name, store separately in two dynamic arrays
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter the test score # " << i + 1 << "and the name follow: ";
            cin >> *(ptr + i) >> *(str + i);
        } while (*(ptr + i) < 0);
    }

    //Output the score array with the name followed
    cout << endl << "The array for test score is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << "," << *(str + i) << " ";
    }
    cout << endl;

    //Sort numbers in array in ascending order
    sort(ptr, size);
    cout << "The array of ascending order is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << "," << *(str + i) << " ";
    }
    cout << endl;
    //Calculate the average of the numbers in array
    average(ptr, size);

    //Delete memory
    delete [] ptr;
    ptr = 0;
    cout << endl << endl;

}

void problem5() { //Gaddis 8th, 9.5
    cout << "In problem # 5" << endl << endl;

    //Declare variables
    int x, y;

    //Input numbers for x and y
    cout << "Enter a number for x: ";
    cin >> x;
    cout << "Enter a number for y: ";
    cin >> y;

    //Do the calculation by function, and output the result
    cout << "10 times (x+y) is: " << doSomething(&x, &y) << endl;

    cout << endl << endl;
}

void problem6() { //Gaddis 8th, 9.6
    cout << "In problem # 6" << endl << endl;
    
    //Declare variables
    int size;
    //Input the size of the array
    do {
        cout << "Enter a number for the size of the array: ";
        cin >> size;
    } while (size < 1);
    
    //Declare dynamic array
    int *array = new int[size];
    //Input numbers in the dynamic array
    for (int i = 0; i < size; i++) {
        cout << "Enter the number of donation amount # " << i + 1 << ": ";
        cin >> *(array + i);
    }

    // An array of pointers to int.
    int *arrPtr[size];

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int i = 0; i < size; i++)
        arrPtr[i] = &(*(array + i));

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, size);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, size);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(array, size);
    
    //Delete memory
    delete [] array;
    array = 0;
    cout << endl << endl;
}

void problem7() { //Gaddis 8th, 9.7
    cout << "In problem # 7" << endl << endl;

    const int NUM_DONATIONS = 15;

    // An array containing the donation amounts.
    int donations[NUM_DONATIONS] = {5, 100, 5, 25, 10,
                                    5, 25, 5, 5, 100,
                                    10, 15, 10, 5, 10};

    // An array of pointers to int.
    int *arrPtr[NUM_DONATIONS] = {nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr};

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelecSort(arrPtr, NUM_DONATIONS);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);

    cout << endl << endl;
}

void problem8() { //Gaddis 8th, 9.10
    cout << "In problem # 8" << endl << endl;
    
    //Declare variables
    int size;
    //Input the size of the array
    do {
        cout << "Enter the size of the array: ";
        cin >> size;
    } while (size < 1);
    
    //Declare dynamic arrays
    int *arr = new int[size];
    int *rev = new int[size];
    //Input numbers in original array
    cout << "Enter the numbers for array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "# " << i + 1 << ": ";
        cin >> *(arr + i);
    }
    
    //Output the array on the screen
    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    //Use reverse function to reverse the numbers in the array
    rev = reverse(arr, size);

    //Output the array after reversed
    cout << "The array after reversed is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(rev + i) << " ";
    }
    cout << endl;

    //Delete memory
    delete [] arr;
    delete [] rev;
    arr = 0;
    rev = 0;
    cout << endl << endl;
}

void problem9() { // Mean, median, mode problem
    cout << "In problem # 9" << endl << endl;

    //Declare variables
    int size;
    //Input the size of the array
    do {
        cout << "Enter the size of the array: ";
        cin >> size;
    } while (size < 1);
    
    //Declare pointers and dynamic arrays
    int *ptr;
    int *arr = new int[size];
    //Input numbers in the array
    cout << "Enter the numbers for the array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "# " << i + 1 << ": ";
        cin >> *(arr + i);
    }
    //Use mean function calculate the mean
    cout << "The mean of the array is: " << mean(arr, size) << endl;
    //Use median function calculate the median
    cout << "The median of the array is: " << median(arr, size) << endl;

    //Use mode function calculate the number, frequency and the mode, and stored in an array
    ptr = mode(arr, size);
    if (*(ptr + 1) == 1) {
        cout << "Mode does not exist." << endl;//Mode should exist more than once
    } else {
        cout << "The number of modes in the array is: " << *ptr << endl;
        cout << "The frequency of modes is: " << *(ptr + 1) << endl;
        cout << "The modes are: ";
        for (int i = 1; i <= *ptr; i++) {
            cout << *(ptr + i + 1) << " ";
        }
        cout << endl;
    }

    //Delete memory
    delete [] ptr;
    delete [] arr;
    ptr = 0;
    arr = 0;
    cout << endl << endl;
}

//Function implementation
//Function of exiting program
void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}

//Allocate numbers function
int *allocate(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the number " << i + 1 << ": ";
        cin >> *(arr + i);
    }
    return arr;
}

//Sort function for ascending order
void sort(int * arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i)> *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

//Function for calculating average
void average(int *arr, int size) {

    float ave = 0;
    //Calculate the sum first
    for (int i = 0; i < size; i++) {
        ave += *(arr + i);
    }
    //Calculate the average
    ave = ave / size;
    //Output the average on screen
    cout << "The average of the test scores is: " << ave << endl;
}

//Function for calculating the average after drop the lowest number
void averageD(int *arr, int size) {

    float ave = 0;
    for (int i = 1; i < size; i++) {
        ave += *(arr + i);
    }

    ave = ave / size;
    cout << "The average of the test scores is: " << ave << endl;
}

//Sort function for both int and string array
void sort(int * arr, string * name, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i)> *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
                string tem = *(name + i);
                *(name + i) = *(name + j);
                *(name + j) = tem;

            }
        }
    }
}

//Function for exchange the value of x and y, then both times 10, and calculate the sum
int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    
    //Return pointer to the main function
    return *x + *y;
}

//Select sort function of ascending order
void arrSelectSort(int *arr[], int size) {

    int startScan, minIndex;
    int *minElem;
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) < *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

// Function for showing the content of arr on screen
void showArray(const int arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

//Function for showing the pointer that point to content of arr
void showArrPtr(int *arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}

//Select sort function of descending order
void arrSelecSort(int *arr[], int size) {

    int startScan, minIndex;
    int *minElem;
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) > *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//Reverse function
int *reverse(int * arr, int size) {
    int *rev = new int[size];

    //exchange the value symmetrically
    for (int i = 0; i < size; i++) {
        *(rev + i) = *(arr + size - i - 1);
    }
    return rev;
}

//Mean function
float mean(int * arr, int size) {
    float ave = 0;
    for (int i = 0; i < size; i++) {
        ave += *(arr + i);
    }

    ave = ave / size;

    return ave;
}

//Median function
float median(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i)>*(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    if (size % 2 == 1) { // if size is odd
        return *(arr + size / 2);
    } else { // if size is even
        //declare variables
        float med;
        med = *(arr + size / 2 - 1) + *(arr + size / 2);
        med /= 2;
        return med;
    }
}

// Mode function that create the array mode, store the value of number, frequency, and mode
int *mode(int * arr, int size) {
    
    //Sort the array first
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i)>*(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    
    //Declare variables
    int *mode = new int[size];
    int num = *arr;
    int count = 0;
    *mode = *arr;
    *(mode + 1) = 0;
    
    //Count and record the numbers exist most times in array
    for (int i = 0; i <= size; i++) {
        if (*(arr + i) == num && i != size) { //if two numbers are same, add count
            count++;
        } else { // if they are not same...
            if (count>*(mode + 1)) { // if count more, store the number, frequency, and mode in array
                *mode = 1;
                *(mode + 1) = count;
                *(mode + 2) = *(arr + i - 1);
            } else if (count == *(mode + 1)) { // if same, keep both
                *mode += 1;
                *(mode + (*mode) + 1) = *(arr + i - 1);
            }
            num = *(arr + i);
            count = 1;
        }
    }
    //Return array
    return mode;
}