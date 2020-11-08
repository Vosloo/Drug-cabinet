#include "SolidDrug.hpp"

class PainKiller : public SolidDrug
{
private:
    int maxDailyDosage;
    bool onlyAdults;
public:
    PainKiller(string name, string description, bool prescription, bool onlyAdults);
    void setInfo(int packageSize, int maxDailyDosage);
    string toString() override;
};
