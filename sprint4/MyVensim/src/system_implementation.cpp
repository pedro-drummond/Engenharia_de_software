#include "system_implementation.h"

// construtores e destrutor
BaseSystem::BaseSystem() {

}
BaseSystem::BaseSystem(string name = NULL, double value = 0) : value(value), name(name) {}
BaseSystem::~BaseSystem() {}

// getter and setter
/// @brief This function sets the value of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->setValue(100);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseSystem::setValue(double sValue) {
    value = sValue;
}
/// @brief This function returns the value of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->getValue(); // returns 100
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double BaseSystem::getValue() const {
    return value;
}
/// @brief This function sets the name of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->setName("S1");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void BaseSystem::setName(string sName) {
    name = sName;
}
/// @brief This function returns the name of the system
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system = new System();
///     system->getName(); // returns "S1"
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string BaseSystem::getName() const {
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

BaseSystem::BaseSystem(const System& system){
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
BaseSystem& BaseSystem::operator=(const System& system){
    if (this == &system) return *this;
    value = system.getValue();
    name = system.getName();
    return *this;
}
