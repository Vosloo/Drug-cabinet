#pragma once
#include <string>

using namespace std;

class Drug
{
protected:
    string name;
    string description;
    double price;
    bool prescription;
public:
    virtual string toString() = 0;
    void setPrice(double price) { 
        if (price < 0) {
            throw string("Price cannot be lower than zero!\n");
        }
        this->price = price; 
    }
};
