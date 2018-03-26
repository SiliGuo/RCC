// demonstrate allocating memory and deleting memory when done
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int *ptr = nullptr;

    int n;
    cout << "Enter the size of the array you want to build (must be greater than 0): ";
    cin >> n;

    ptr = new int[n];

    for (int i = 0; i < n; i++)
        *(ptr + i) = i;

    for (int i = 0; i < n; i++)
        cout << ptr[i] << endl;

    // release the allocated memory back to the system
    ptr = nullptr;
    delete[] ptr;

    return 0;
}