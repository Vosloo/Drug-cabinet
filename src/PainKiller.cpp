#include "PainKiller.hpp"

PainKiller::PainKiller(string name, string description, bool prescription, bool onlyAdults) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
    this->onlyAdults = onlyAdults;
}


void PainKiller::setInfo(int packageSize, int maxDailyDosage) {
    if (packageSize < 0) {
        throw string("Package size cannot be lower than zero!");
    }
    this->packageSize = packageSize;
    this->maxDailyDosage = maxDailyDosage;
}


string PainKiller::toString() {
    return (
        name + ": " + description + '\n' +
        "Only for adults: " + (onlyAdults ? "yes" : "no") + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Package size: " + to_string(packageSize) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}