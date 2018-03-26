// demonstrate binary file i/o by prompting the user for a file name for an output file
// ask the user for the number of elements in an array of short integers they would like to create
// prompt the user to enter the individual elements of the array
// output the data in the array to a binary file in the following format:
//
//	{number of elements in array}{element0}{element1}....{elementN-1}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int elements;
    string filename;

    cout << "Enter the number of elements for your array of short integers: ";
    cin >> elements;

    cout << "Enter the name of the output file you would like to create: ";
    cin >> filename;

    short int *ptr = new short int[elements];

    for (int i = 0; i < elements; i++) {
        cout << "Enter a short integer value (-32,768 to 32,767) for element #" << i << ": ";
        cin >> *(ptr + i);
    }

    fstream outputFile;

    outputFile.open(filename.c_str(), ios::binary | ios::out);

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
    return 0;
}