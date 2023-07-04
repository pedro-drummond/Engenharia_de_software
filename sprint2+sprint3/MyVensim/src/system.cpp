#include "system.h"

// construtores e destrutor
System::System() {}
System::System(string name, double value) : value(value), name(name) {}
System::~System() {}

// getter and setter
/// @brief This function sets the value of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->setValue(100);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void System::setValue(double sValue) {
    value = sValue;
}
/// @brief This function returns the value of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->getValue(); // returns 100
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double System::getValue() const {
    return value;
}
/// @brief This function sets the name of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->setName("S1");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void System::setName(string sName) {
    name = sName;
}
/// @brief This function returns the name of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->getName(); // returns "S1"
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string System::getName() const {
    return name;
}

/// @brief This function copies the value and name of a system
/// @param system   The system to be copied
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System();
///     system2->copySystem(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

System::System(const System& system){
    value = system.getValue();
    name = system.getName();
}
/// @brief This function copies the value and name of a system
/// @param system   The system to be assigned
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System();
///     system2 = system1;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
System& System::operator=(const System& system){
    if (this == &system) return *this;
    value = system.getValue();
    name = system.getName();
    return *this;
}
