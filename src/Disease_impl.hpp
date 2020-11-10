#include <memory>
#include <iostream>
#include "Disease.hpp"


Disease::Disease(double pDisease, double pRecovery) {
    this->pDisease = pDisease;
    this->pRecovery = pRecovery;
}

double Disease::getDisease() {
    return this->pDisease;
}

double Disease::getRecovery() {
    return this->pRecovery;
}

template <class T>
int Disease::pandemic(unique_ptr<Cabinet<T>>& cabinet) {
    srand(time(NULL));
    
    int day = 0;
    while ((*cabinet).count() != 0)
    {
        day++;
        int randDelete = (rand() % 100) + 1;
        if (randDelete <= (int)(this->pDisease * 100)) {
            // Drug marked as to be deleted;

            int randRestore = (rand() % 100) + 1;
            if (randRestore <= (int)((1 - this->pRecovery) * 100)) {
                // Restore drug, so don't delete in the first place;
                // Nothing
            }
            else {
                // Delete drug permanently;
                string drugName = (*cabinet).getDrugName(0);
                (*cabinet) -= drugName;
            }
        }
        cout << "\nDay " + to_string(day) + ". of pandemic has passed!" << endl;
        cout << "Number of drugs in cabinet: " + to_string((*cabinet).count()) << endl;
        cout << "Drugs in cabinet: " + (*cabinet).toString() << endl;
    }
    return day;
}
