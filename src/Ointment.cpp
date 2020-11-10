#include "Ointment.hpp"

Ointment::Ointment(string name, string description,
                    bool prescription, string applicationPlace) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
    this->applicationPlace = applicationPlace;
}

void Ointment::setInfo(int volume) {
    if (volume <= 0) {
        throw string("Volume must be greater than zero!");
    }
    this->volume = volume;
}

string Ointment::toString() {
    return (
        name + " (Ointment): " + description + '\n' +
        "Application place: " + applicationPlace + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Volume: " + to_string(volume) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}