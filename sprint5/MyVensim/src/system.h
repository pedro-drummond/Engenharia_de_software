#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include <string>

using namespace std;

class System{
    public:
    /// @brief This function sets the value of the system
    virtual ~System(){}

    /// @brief This function sets the value of the system
    /// @param sValue   The value to be set
    virtual void setValue(double sValue) = 0;

    /// @brief This function gets the value of the system
    /// @return double
    virtual double getValue() const = 0;

    /// @brief This function sets the name of the system
    /// @param sName    The name to be set
    virtual void setName(string sName) = 0;

    /// @brief This function gets the name of the system
    /// @return string
    virtual string getName() const = 0;
};

#endif // SYSTEM_INTERFACE_H