#include "Antibiotic.hpp"

Antibiotic::Antibiotic(string name, string description, bool prescription) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
}


void Antibiotic::setInfo(string bacteria, int ageDestiny, int packageSize) {
    if (packageSize < 0) {
        throw string("Package size cannot be lower than zero!\n");
    }
    this->bacteria = bacteria;
    this->ageDestiny = ageDestiny;
    this->packageSize = packageSize;
}


string Antibiotic::toString() {
    return (
        name + ": " + description + '\n' +
        "Kills bacteria: " + bacteria + '\n' +
        "Age destiny: " + (ageDestiny > 0 ? to_string(ageDestiny) + "+" : "all ages") + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Package size: " + to_string(packageSize) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}