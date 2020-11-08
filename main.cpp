#include <iostream>
#include "PainKiller.cpp"
#include "Antibiotic.cpp"
#include "Ointment.cpp"
#include "Syrup.cpp"


int main(int argc, char const *argv[])
{
    PainKiller pk("CovidKiller", "Drug for Covid", false, false);
    pk.setInfo(20, 3);
    pk.setPrice(14.99);
    cout << pk.toString() << endl;

    Antibiotic ab("Penicilin", "First antibio", false);
    ab.setInfo("bacterius infectus", 14, 6);
    ab.setPrice(120);
    cout << ab.toString() << endl;

    Ointment oi("Oi", "you cheeky wanker", true);
    oi.setInfo(99999999, "Butt");
    oi.setPrice(0.99);
    cout << oi.toString() << endl;

    Syrup sr("Syru", "Drink that", false);
    sr.setInfo(10, 25);
    sr.setPrice(25);
    cout << sr.toString() << endl;
    return 0;
}
