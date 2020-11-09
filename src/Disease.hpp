#include "Cabinet.hpp"

class Disease
{
private:
    double pRecovery;
    double pDisease;
    vector<unique_ptr<Drug>> drugs;
public:
    Disease(double pDisease, double pRecovery);

    template <class T>
    void pandemic(unique_ptr<Cabinet<T>>& cabinet);
};