#include "Cabinet.cpp"
#include "PainKiller.cpp"
#include "Antibiotic.cpp"
#include "Ointment.cpp"
#include "Syrup.cpp"


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


int main(int argc, char const *argv[])
{
    int drugCount;
    cout << "How many drugs do you want to create?" << '\n';
    cout << "Number: ";
    cin >> drugCount;

    while (!cin.good() || drugCount <= 0) {
        cout << "Supplied value is invalid, try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Number: ";
        cin >> drugCount;
    }

    auto cabinet = make_unique<Cabinet<Drug>>();

    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for (int i = 0; i < drugCount; i++) {
        auto curRand = rand();
        string name = "";
        
        for (int i = 0; i < 8; i++) {
            char x = letters[rand() % 26];
            name += x;
        }
        createDrug(name, curRand, *cabinet);
    }

    cout << "Number of drugs in cabinet: " +
            to_string(cabinet->count()) << endl;
    cout << "Drugs in cabinet: " + cabinet->toString() << endl;

    return 0;
}
