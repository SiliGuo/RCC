// demonstrate allocating memory and deleting memory when done
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int *ptr = nullptr;

    ptr = new int;
    *ptr = 25;

    // should output 25
    cout << *ptr << endl;

    return 0;
}