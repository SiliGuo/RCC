// read the data in the array from a binary file in the following format:
//
//	{number of elements in array}{element0}{element1}....{elementN-1}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int elements;
    string filename;

    cout << "Enter the name of the input file you would like to read: ";
    cin >> filename;

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
    } else {
        cout << "Could not open the file: " << filename << endl;
        return 1;
    }

    cout << "The file " << filename << " was successfull read, here are the contents of the array:" << endl;

    for (int i = 0; i < elements; i++) {
        cout << *(ptr + i);
        if (i != elements - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}