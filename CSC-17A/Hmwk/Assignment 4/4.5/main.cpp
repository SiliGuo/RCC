/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 17, 2016, 9:54 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "RetailItem.h"

int main(int argc, char** argv) {

    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);
    
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << " " << setw(20) << "Description" << setw(20) << "Units On Hand" << setw(20) << "Price" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
        cout << setw(20) << "Item #1";
        item1.ptnInfo();
        cout << setw(20) << "Item #2";
        item2.ptnInfo();
        cout << setw(20) << "Item #3";
        item3.ptnInfo();
    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

