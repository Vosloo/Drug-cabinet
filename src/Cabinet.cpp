#include "Cabinet.hpp"
#include <iostream>
#include <algorithm>

template <class T>
void Cabinet<T>::addDrug(unique_ptr<T> drug) {
    this->drugs.push_back(move(drug));
}

template <class T>
void Cabinet<T>::removeDrug(string drugName) {
    for (auto& drug : this->drugs) {
        if (drug->getName() == drugName) {
            this->drugs.erase(
                remove(this->drugs.begin(), this->drugs.end(), drug), 
                this->drugs.end()
            );
            return;
        }
    }
    throw string("No drug with given name in the cabinet!");
}

template <class T>
string Cabinet<T>::getInside() {
    string output = "";
    for (auto& drug : this->drugs) {
        output += drug->toString() + "\n\n";
    }

    // For deleting last new newline characters from output;
    output.erase(output.size() - 2);
    return output;
}

template <class T>
string Cabinet<T>::getDrugsInfo() { 
    string output = this->getInside();
    return output;
}

template <class T>
string Cabinet<T>::toString() {
    if (this->drugs.empty()) {
        return "Cabinet is empty!";
    }
   
    string drugNames = "";
    for (auto& drug : this->drugs) {
        drugNames += drug->getName() + ", ";
    }

    // Remove last coma and white space;
    drugNames.erase(drugNames.size() - 2);

    return drugNames;
}

template <class T>
int Cabinet<T>::count() {
    return this->drugs.size();
}

template <class T>
Cabinet<T>& Cabinet<T>::operator+=(unique_ptr<T> drug) {
    this->addDrug(move(drug));
    return *this;
}

template <class T>
Cabinet<T>& Cabinet<T>::operator-=(string drugName) {
    this->removeDrug(drugName);
    return *this;
}