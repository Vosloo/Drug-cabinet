#pragma once
#include "Cabinet.hpp"

class Disease
{
private:
    double pRecovery;
    double pDisease;
public:
    Disease(double pDisease, double pRecovery);
    double getRecovery();
    double getDisease();

    template <class T>
    int pandemic(unique_ptr<Cabinet<T>>& cabinet);
};

#include "Disease_impl.hpp"