/* 
 * File:   main.cpp
 * Author: siliguo
 *
 * Created on November 17, 2016, 9:31 PM
 */

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

int main(int argc, char** argv) {

    Person me("Sili", "4420 Lenord Ct", 20, "(951)-654-321");
    Person chen("Hank", "4420 Lenord Ct", 20, "(909)-789-123");
    Person father("Hanhua", "1203 Zhongshan Rd", 40, "13912345678");
    
    //Output result
    cout << "My information: " << endl;
    me.ptnInfo();
    cout << endl;
    
    cout << "My friend's information: " << endl;
    chen.ptnInfo();
    cout << endl;
    
    cout << "My father's information: " << endl;
    father.ptnInfo();
    cout << endl;
    
    return 0;
}

