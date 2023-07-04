#ifndef LOG_H
#define LOG_H
#include <iostream>
#include "../src/system_implementation.h"
#include "../src/flow_implementation.h"
/// @brief This class represents a flow in the system. The user can use this class or create a new one.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Logistic *flow1 = new Logistic(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Logistic : public BaseFlow{
    public:
        /// @brief Construct a new Logistic object
        /// @param origin   
        /// @param destination 
        Logistic(System *origin = NULL, System *destination = NULL): BaseFlow(origin, destination) {};
        virtual ~Logistic(){};

        /// @brief Use this function to run the flow
        double run(){
            double result = 0.01*destination->getValue()*(1-destination->getValue()/70);
            return result;
        }
};

#endif // LOG_H