#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
using namespace std;
/// The System class represents a simulation system with properties for value and name.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// System *system1 = new System("S1", 100);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class System {

    protected:
        /// @brief This attribute represents the value of the system

        double value;
        /// @brief This attribute represents the name of the system
        string name;
    public:
        // constructors and destructor
        System();
        System(string name, double value);
        virtual ~System();

        // getter and setter
        void setValue(double sValue);
        double getValue() const;
        void setName(string sName);
        string getName() const;

        // overload of operators
        System(const System& system);
        System& operator=(const System& system);

};

#endif // SYSTEM_H
