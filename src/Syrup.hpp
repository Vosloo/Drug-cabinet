#pragma once
#include "NonSolidDrug.hpp"

class Syrup : public NonSolidDrug
{
private:
    int density;
public:
    Syrup(string name, string description, bool prescription);
    void setInfo(int volume, int density);
    string toString() override;
};