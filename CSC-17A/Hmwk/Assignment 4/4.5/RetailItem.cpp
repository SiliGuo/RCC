/* 
 * File:   RetailItem.cpp
 * Author: siliguo
 * 
 * Created on November 17, 2016, 9:55 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "RetailItem.h"

RetailItem::RetailItem(string des, int un, float pr) {
    description = des;
    unitsOnHand = un;
    price = pr;
}

string RetailItem::getDes() const {
    return description;
}

int RetailItem::getUnits() const {
    return unitsOnHand;
}

float RetailItem::getPrice() const {
    return price;
}

void RetailItem::ptnInfo() {
   
        cout << setw(20) << description << setw(20) << unitsOnHand << setw(20) << price << endl;
}