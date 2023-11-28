#include <iostream>
#include "System.h"

using namespace std;

// ---------- CONSTRUCTORS AND DESTRUCTOR ----------

System::System(double value):
    value(value) {}

System::~System() {}

System::System(const System& system) {

    if(this == &system)
        return;

    value = system.getValue();
}

// ---------- GETTERS AND SETTERS ----------

double System::getValue() const {
    return value;
}

bool System::setValue(double value) {
    
    this->value = value;

    if(this->value == value)
        return true;

    return false;
}

// ---------- CRUD METHODS ----------

bool System::update(double value) {

    this->value = value;

    if(this->value == value)
        return true;

    return false;
}

// ---------- OVERLOAD ----------

System& System::operator= (const System& system) {

    if(this == &system) {
        return *this;
    }

    value = system.getValue();

    return *this;
}
