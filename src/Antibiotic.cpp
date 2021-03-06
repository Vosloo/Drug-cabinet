#include "Antibiotic.hpp"

Antibiotic::Antibiotic(string name, string description, bool prescription) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
}


void Antibiotic::setInfo(int ageDestiny, int packageSize) {
    if (packageSize < 0) {
        throw string("Package size cannot be lower than zero!");
    }
    this->ageDestiny = ageDestiny;
    this->packageSize = packageSize;
}


string Antibiotic::toString() {
    return (
        name + " (Antibiotic): " + description + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Age destiny: " + (ageDestiny > 0 ? to_string(ageDestiny) + "+" : "all ages") + '\n' +
        "Package size: " + to_string(packageSize) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}