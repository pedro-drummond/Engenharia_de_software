#include "../system_implementation.h"

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

