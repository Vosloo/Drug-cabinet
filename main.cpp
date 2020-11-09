#include "Cabinet.cpp"
#include "PainKiller.cpp"
#include "Antibiotic.cpp"
#include "Ointment.cpp"
#include "Syrup.cpp"


int main(int argc, char const *argv[])
{
    auto cabinet = make_unique<Cabinet<PainKiller>>();

    // TODO: Move all parameters to constructor??
    auto pk = make_unique<PainKiller>("CovidKiller", "Drug for Covid", false, false);
    pk->setInfo(20, 3);
    pk->setPrice(14.99);

    auto pk1 = make_unique<PainKiller>("Sleeper", "Drug for sleep", false, false);
    pk1->setInfo(5, 1);
    pk1->setPrice(2.99);

    auto ab = make_unique<Antibiotic>("Penicilin", "First antibio", false);
    ab->setInfo("bacterius infectus", 14, 6);
    ab->setPrice(120);

    auto oi = make_unique<Ointment>("Oi", "you cheeky wanker", true);
    oi->setInfo(99999999, "Butt");
    oi->setPrice(0.99);

    auto sr = make_unique<Syrup>("Syru", "Drink that", false);
    sr->setInfo(10, 25);
    sr->setPrice(25);

    *cabinet += move(pk);
    *cabinet += move(pk1);

    cout << "Number of drugs in cabinet: " +
            to_string(cabinet->count()) + '\n' << endl;
    cout << cabinet->toString() << endl;

    // TODO: Think about removing Drug object maybe?
    try {
        *cabinet -= "Sleeper";
    }
    catch(string caught){
        std::cerr << "\n" + caught << endl;
    }
    
    cout << "\nNumber of drugs in cabinet: " +
            to_string(cabinet->count()) + '\n' << endl;
    cout << cabinet->toString() << endl;

    return 0;
}
