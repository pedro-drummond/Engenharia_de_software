#ifndef FLOW_H
#define FLOW_H

#include "flow.h"
#include <iostream>
using namespace std;

/// @brief The BaseFlow class represents a flow between two systems. 
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseFlow *flow1 = new BaseFlow(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///@see Exp
///@see Logistic
class BaseFlow : public Flow{

    protected:
        /// @brief This attribute represents the origin of the flow

        System *origin;
        /// @brief This attribute represents the destination of the flow

        System *destination;
    public:
        // constructors and destructor
        BaseFlow();
        BaseFlow(System *origin, System *destination);
        virtual ~BaseFlow();

        // getter and setter
        System* getSource() const;
        System* getTarget() const;
        void setSource(System *sOrigin);
        void setTarget(System *sDestination);

        // functions
        virtual double run() = 0;
        void clearFlow();

        // overload of operators
        BaseFlow(const BaseFlow& flow);
        BaseFlow& operator=(const BaseFlow& flow);

};

#endif // FLOW_H
