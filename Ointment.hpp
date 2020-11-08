#include "NonSolidDrug.hpp"

class Ointment : public NonSolidDrug
{
private:
    string applicationPlace;
public:
    Ointment(string name, string description, bool prescription);
    void setInfo(int volume, string applicationPlace);
    string toString() override;
};