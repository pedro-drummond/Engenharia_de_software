#ifndef EXP_H
#define EXP_H

#include <iostream>
#include "../src/system.h"
#include "../src/flow_implementation.h"
/// @brief This class represents a flow in the system. The user can use this class or create a new one.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Exp *flow1 = new Exp(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Exp : public BaseFlow{
    public:
        /// @brief Construct a new Exp object
        /// @param origin 
        /// @param destination 
        Exp(System *origin = NULL, System *destination = NULL): BaseFlow(origin, destination) {};

        virtual ~Exp(){};
        
        /// @brief Use this function to run the flow

        double run(){
            double result = 0.01*origin->getValue();
            return result;
        }
};

#endif // EXP_H