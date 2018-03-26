/* 
 * File:   RetailItem.h
 * Author: siliguo
 *
 * Created on November 17, 2016, 9:55 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

class RetailItem {
private:
    string description;
    int unitsOnHand;
    float price;
public:
    RetailItem(string, int, float);
    string getDes() const;
    int getUnits() const;
    float getPrice() const;
    void ptnInfo();
};

#endif /* RETAILITEM_H */

