#pragma once
#include "NonSolidDrug.hpp"

class Ointment : public NonSolidDrug
{
private:
    string applicationPlace;
public:
    Ointment(string name, string description, 
             bool prescription, string applicationPlace);
    void setInfo(int volume);
    string toString() override;
};