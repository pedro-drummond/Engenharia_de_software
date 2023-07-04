#include "flow.h"

// construtores e destrutor
Flow::Flow() {}
Flow::Flow(System *origin, System *destination): origin(origin), destination(destination) {}
Flow::~Flow() {}

/// @brief This function returns the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Flow *flow1 = new Flow(system1, system2);
///     flow1->getSource(); // returns system1
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
System* Flow::getSource() const {
    return origin;
}
/// @brief This function returns the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Flow *flow1 = new Flow(system1, system2);
///     flow1->getTarget(); // returns system2
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
System* Flow::getTarget() const {
    return destination;
}
/// @brief This function sets the origin and destination of the flow
/// @param sOrigin    The origin of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     Flow *flow1 = new Flow();
///     flow1->setSource(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Flow::setSource(System *sOrigin) {
    origin = sOrigin;
}
/// @brief This function sets the origin and destination of the flow
/// @param sDestination     The destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     Flow *flow1 = new Flow();
///     flow1->setTarget(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Flow::setTarget(System *sDestination) {
    destination = sDestination;
}
/// @brief This function clears the origin and destination of the flow
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     Flow *flow1 = new Flow(system1, system2);
///     flow1->clearFlow();
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Flow::clearFlow(){
    origin = NULL;
    destination = NULL;
}

/// @brief This function copies the value and name of a system
/// @param flow     The flow to be copied
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Flow *flow1 = new Flow(system1, system2);
///     Flow *flow2 = new Flow(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Flow::Flow(const Flow& flow){
    origin = flow.getSource();
    destination = flow.getTarget();
}

/// @brief This function copies the value and name of a system
/// @param flow    The flow to be assigned
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Flow *flow1 = new Flow(system1, system2);
///     Flow *flow2 = new Flow();
///     flow2 = flow1;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Flow& Flow::operator=(const Flow& flow){
    if (this == &flow) return *this;
    origin = flow.getSource();
    destination = flow.getTarget();
    return *this;
}