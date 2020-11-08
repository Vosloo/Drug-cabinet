#include "SolidDrug.hpp"

class Antibiotic : public SolidDrug
{
private:
    string bacteria;
    int ageDestiny;
public:
    Antibiotic(string name, string description, bool prescription);
    void setInfo(string bacteria, int ageDestiny, int packageSize);
    string toString() override;
};