#include "Syrup.hpp"

Syrup::Syrup(string name, string description, bool prescription) {
    this->name = name;
    this->description = description;
    this->prescription = prescription;
}

void Syrup::setInfo(int volume, int density) {
    if (volume <= 0 || density <= 0) {
        throw string("Volume and density must be greater than zero!");
    }
    this->volume = volume;
    this->density = density;
}

string Syrup::toString() {
    return (
        name + " (Syrup): " + description + '\n' +
        "Only on prescription: " + (prescription ? "yes" : "no") + '\n' +
        "Density: " + to_string(density) + '\n' +
        "Volume: " + to_string(volume) + '\n' +
        "Price: " + to_string(price) + "$"
    );
}