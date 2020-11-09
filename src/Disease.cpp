#include "Disease.hpp"


Disease::Disease(double pDisease, double pRecovery) {
    this->pDisease = pDisease;
    this->pRecovery = pRecovery;
}

template <class T>
void Disease::pandemic(unique_ptr<Cabinet<T>>& cabinet) {
    // TODO: how to access drugs???
}
