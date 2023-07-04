#ifndef FLOW_H
#define FLOW_H

#include "system.h"
#include <iostream>
using namespace std;

/// @brief The Flow class represents a flow between two systems. 
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Flow *flow1 = new Flow(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///@see Exp
///@see Logistic
class Flow {

    protected:
        /// @brief This attribute represents the origin of the flow

        System *origin;
        /// @brief This attribute represents the destination of the flow

        System *destination;
    public:
        // constructors and destructor
        Flow();
        Flow(System *origin, System *destination);
        virtual ~Flow();

        // getter and setter
        System* getSource() const;
        System* getTarget() const;
        void setSource(System *sOrigin);
        void setTarget(System *sDestination);

        // functions
        virtual double run() = 0;
        void clearFlow();

        // overload of operators
        Flow(const Flow& flow);
        Flow& operator=(const Flow& flow);

};

#endif // FLOW_H
