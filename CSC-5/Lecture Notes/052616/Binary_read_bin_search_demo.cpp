// read the data in the array from a binary file in the following format:
//
//	{number of elements in array}{element0}{element1}....{elementN-1}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void outputArray(short int *, int);
int binary_search(short int *, int, short int);

int main() {
    int elements;
    string filename;

    cout << "Enter the name of the input file you would like to read (must have data already sorted): ";
    cin >> filename;

    cout << "Enter the value to search for: ";
    int search_value;
    cin >> search_value;

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

    cout << "Contents of the array loaded from file:" << endl;
    outputArray(ptr, elements);
    int index = binary_search(ptr, elements, search_value);

    if (index != -1) cout << "Found " << search_value << " at index " << index << endl;
    else cout << search_value << " was not found!" << endl;

    return 0;
}

int binary_search(short int *a, int sz, short int search_value) {
    int first = 0, last = sz - 1;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (a[mid] == search_value) return mid;
        else if (a[mid] > search_value) last = mid - 1;
        else first = mid + 1;
    }
    return -1;
}

void outputArray(short int *a, int sz) {
    for (int i = 0; i < sz; i++) {
        cout << setw(4) << *(a + i);
        if (i != sz - 1) cout << ",";
    }
    cout << endl;
}