#pragma once
#include <vector>
#include "Drug.hpp"


template <class T>
class Cabinet
{
private:
    vector<unique_ptr<T>> drugs;
    string getInside();
    void addDrug(unique_ptr<T> drug);
    void removeDrug(string drugName);
public:
    string toString();
    string getDrugsInfo();
    string getDrugName(int index);
    int count();

    Cabinet<T>& operator+=(unique_ptr<T> drug);
    Cabinet<T>& operator-=(string drugName);
};

#include "Cabinet_impl.hpp"
