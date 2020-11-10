#include <iostream>
#include <algorithm>
#include <memory>
#include "Cabinet.hpp"
#include "Disease.hpp"
#include "PainKiller.hpp"
#include "Antibiotic.hpp"
#include "Ointment.hpp"
#include "Syrup.hpp"



template <class T>
void createDrug(string name, int curRand, Cabinet<T>& cabinet) {
    string randDesc = "Drug used for ...";
    vector<string> places = {"Leg", "Hand", "Back", "Head"};

    int classType = curRand % 4;
    switch (classType)
        {
        case 0: {
        // Antibiotic
            auto drug = make_unique<Antibiotic>(name, randDesc, true);
            drug->setInfo((curRand % 50) + 1, (curRand % 20) + 1);
            drug->setPrice((curRand % 200) + 1);

            cabinet += move(drug);
            break;
        }
        case 1: {
        // Painkiller
            auto drug = make_unique<PainKiller>(name, randDesc, true, false);
            drug->setInfo((curRand % 20) + 1, (curRand % 6) + 1);
            drug->setPrice((curRand % 200) + 1);

            cabinet += move(drug);
            break;
        }
        case 2: {
        // Ointment
            auto drug = make_unique<Ointment>(name, randDesc, true, places.at(rand() % 4));
            drug->setInfo((curRand % 651) + 100);
            drug->setPrice((curRand % 200) + 1);

            cabinet += move(drug);
            break;
        }
        case 3: {
        // Syrup
            auto drug = make_unique<Syrup>(name, randDesc, false);
            drug->setInfo((curRand % 651) + 100, (curRand % 101) + 100);
            drug->setPrice((curRand % 200) + 1);

            cabinet += move(drug);
            break;
        }}
}

template <typename type>
void getInput(type* var, string probability) {
    if (is_same<type, int>::value) {
        // int - number of drugs
        cout << "How many drugs do you want to create?" << '\n';
        cout << "Number: ";
        cin >> *var;
    
        while (!cin.good() || *var <= 0) {
            cout << "Supplied value is invalid. Valid range: (0; inf)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Number: ";
            cin >> *var;
        }
    }
    else if (is_same<type, double>::value) {
        // double - probabilities
        cout << "What is the probability of " << probability + "?" << '\n';
        cout << "Number: ";
        cin >> *var;

        while (!cin.good() || *var < 0 || *var > 1) {
            cout << "Supplied value is invalid. Valid range: <0; 1>" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Number: ";
            cin >> *var;
        }
    }
    else {
        throw string("Wrong type!");
    }
}


int main(int argc, char const *argv[])
{
    int drugCount;
    double pRecovery;
    double pDisease;
    getInput(&drugCount, "");
    getInput(&pDisease, "disease");
    getInput(&pRecovery, "recovery");

    auto cabinet = make_unique<Cabinet<Drug>>();

    // Creating drugCount number of drugs;
    srand(time(NULL));
    for (int i = 0; i < drugCount; i++) {
        auto curRand = rand();
        string name = "Drug" + to_string(i);
        
        createDrug(name, curRand, *cabinet);
    }

    cout.clear();
    cout << "\nNumber of drugs in cabinet: " + to_string(cabinet->count()) << endl;
    cout << "Drugs in cabinet: " + cabinet->toString() << '\n' << endl;

    auto disease = make_unique<Disease>(pDisease, pRecovery);

    cout << "Pandemic time has come! Currently set parameters:\n" <<
            "Probability of disease: " + to_string(disease->getDisease()) + "\n" <<
            "Probability of recovery: " + to_string(disease->getRecovery()) << endl;

    // Start pandemic
    int daysSurvived = disease->pandemic(cabinet);
    cout << "\nThe day the drugs ran out: " + to_string(daysSurvived) <<
            ".\nBetter luck next time!" << endl;

    return 0;
}
