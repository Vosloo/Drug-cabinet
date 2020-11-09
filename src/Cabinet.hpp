#include <vector>
#include <memory>
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
    int count();

    Cabinet<T>& operator+=(unique_ptr<T> drug);
    Cabinet<T>& operator-=(string drugName);
};
