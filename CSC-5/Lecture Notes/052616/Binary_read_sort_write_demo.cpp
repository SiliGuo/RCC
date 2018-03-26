// read the data in the array from a binary file in the following format:
//
//	{number of elements in array}{element0}{element1}....{elementN-1}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void bubble(short int*, const int);
void outputArray(short int *, const int);

int main() {
    int elements;
    string filename, sortedFilename;

    cout << "Enter the name of the input file you would like to read: ";
    cin >> filename;

    cout << "Enter the name of the output file you would like to store sorted array: ";
    cin >> sortedFilename;

    short int *ptr = 0;

    fstream inputFile;

    inputFile.open(filename.c_str(), ios::binary | ios::in);

    if (inputFile) // if successfully opened this will be true
    {
        // read in the size of the array
        inputFile.read((char *) &elements, sizeof (int)); // get the number of elements from binary file
        ptr = new short int[elements];

        // read in the actual array of short int
        inputFile.read((char *) ptr, sizeof (short int)*elements);
        bubble(ptr, elements);

        cout << "The sorted array:" << endl;
        outputArray(ptr, elements);

        fstream outputFile;

        outputFile.open(sortedFilename.c_str(), ios::binary | ios::out);

        if (outputFile) // if successfully opened this will be true
        {
            // write out the array
            outputFile.write((char *) &elements, sizeof (int)); // write out the size of the array in # of elements

            // write out the actual array of short int
            outputFile.write((char *) ptr, sizeof (short int)*elements);
        } else {
            cout << "Could not open the file: " << filename << endl;
            return 1;
        }

        cout << "The file " << filename << " was successfull written." << endl;

    } else {
        cout << "Could not open the file: " << filename << endl;
        return 1;
    }

    return 0;
}

void outputArray(short int *a, int sz) {
    for (int i = 0; i < sz; i++) {
        cout << setw(4) << *(a + i);
        if (i != sz - 1) cout << ",";
    }
    cout << endl;
}

void bubble(short int *a, int sz) {
    for (int pass = 1; pass < sz; pass++) {
        for (int count = 0; count < sz - 1; count++)
            if (a[count] > a[count + 1]) {
                int temp = a[count];
                a[count] = a[count + 1];
                a[count + 1] = temp;
            }
    }
}