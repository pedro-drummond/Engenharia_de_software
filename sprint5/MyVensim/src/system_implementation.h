#ifndef SYSTEM_H
#define SYSTEM_H

#include "system.h"
#include <iostream>
#include <string>

using namespace std;
/// The BaseSystem class represents a simulation system with properties for value and name.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseSystem *system1 = new BaseSystem("S1", 100);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class BaseSystem : public System{

    protected:
        /// @brief This attribute represents the value of the system

        double value;
        /// @brief This attribute represents the name of the system
        string name;
    public:
        // constructors and destructor
        BaseSystem();
        BaseSystem(string name, double value);
        virtual ~BaseSystem();

        // getter and setter
        void setValue(double sValue);
        double getValue() const;
        void setName(string sName);
        string getName() const;
        // overload of operators
        BaseSystem(const System& system);
        BaseSystem& operator=(const System& system);

};

#endif // SYSTEM_H
