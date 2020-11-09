#include "Ointment.hpp"

Ointment::Ointment(string name, string description, bool prescription) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
}

void Ointment::setInfo(int volume, string applicationPlace) {
    if (volume <= 0) {
        throw string("Volume must be greater than zero!");
    }
    this->volume = volume;
    this->applicationPlace = applicationPlace;
}

string Ointment::toString() {
    return (
        name + ": " + description + '\n' +
        "Application place: " + applicationPlace + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Volume: " + to_string(volume) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}