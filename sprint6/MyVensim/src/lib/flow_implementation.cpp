#include "../flow_implementation.h"
#include "../system.h"

/// @brief This function returns the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     BaseFlow *flow1 = new BaseFlow(system1, system2);
///     flow1->getSource(); // returns system1
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
System* BaseFlow::getSource() const {
    return origin;
}
/// @brief This function returns the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     BaseFlow *flow1 = new BaseFlow(system1, system2);
///     flow1->getTarget(); // returns system2
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
System* BaseFlow::getTarget() const {
    return destination;
}
/// @brief This function sets the origin and destination of the flow
/// @param sOrigin    The origin of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseFlow *flow1 = new BaseFlow();
///     flow1->setSource(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseFlow::setSource(System *sOrigin) {
    origin = sOrigin;
}
/// @brief This function sets the origin and destination of the flow
/// @param sDestination     The destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseFlow *flow1 = new BaseFlow();
///     flow1->setTarget(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseFlow::setTarget(System *sDestination) {
    destination = sDestination;
}
/// @brief This function clears the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseFlow *flow1 = new BaseFlow(system1, system2);
///     flow1->clearFlow();
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseFlow::clearFlow(){
    origin = NULL;
    destination = NULL;
}

/// @brief This function copies the value and name of a system
/// @param flow     The flow to be copied
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     BaseFlow *flow1 = new BaseFlow(system1, system2);
///     BaseFlow *flow2 = new BaseFlow(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    double BaseFlow::run(){
        double result = 0*origin->getValue();
        return result;
    }

