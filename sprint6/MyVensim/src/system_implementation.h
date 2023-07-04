#ifndef SYSTEM_H
#define SYSTEM_H

#include "system.h"
#include <iostream>
#include <string>
#include "handleBodySemDebug.h"
using namespace std;
/// The BaseSystem class represents a simulation system with properties for value and name.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseSystem *system1 = new BaseSystem("S1", 100);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class BaseSystem : public Body{

    protected:
        /// @brief This attribute represents the value of the system

        double value;
        /// @brief This attribute represents the name of the system
        string name;
    public:
        // getter and setter
        virtual void setValue(double sValue);
        virtual double getValue() const;
        virtual void setName(string sName);
        virtual string getName() const;

};

class SystemHandle : public System, public Handle<BaseSystem>
{
    public:
        SystemHandle(string name, double value){
            pImpl_->setName(name);
            pImpl_->setValue(value);
        }
        double getValue() const{
            return pImpl_->getValue();
        }
        void setValue(double value){
            pImpl_->setValue(value);
        }
        string getName() const{
            return pImpl_->getName();
        }
        void setName(string name){
            pImpl_->setName(name);
        }
};



#endif // SYSTEM_H
