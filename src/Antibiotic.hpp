#pragma once
#include "SolidDrug.hpp"

class Antibiotic : public SolidDrug
{
private:
    int ageDestiny;
public:
    Antibiotic(string name, string description, bool prescription);
    void setInfo(int ageDestiny, int packageSize);
    string toString() override;
};