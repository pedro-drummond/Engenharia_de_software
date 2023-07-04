#ifndef LOG_H
#define LOG_H
#include <iostream>
#include "../src/system.h"
#include "../src/flow_implementation.h"
/// @brief This class represents a flow in the system. The user can use this class or create a new one.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Logistic *flow1 = new Logistic(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Logistic : public FlowHandle{
    public:
        /// @brief Construct a new Logistic object
        /// @param origin   
        /// @param destination 
        Logistic(System *origin = NULL, System *destination = NULL): FlowHandle(origin, destination) {};
        virtual ~Logistic(){};

        /// @brief Use this function to run the flow
        double run(){
            double result = 0.01*getTarget()->getValue()*(1-getTarget()->getValue()/70);
            return result;
        }
};

#endif // LOG_H