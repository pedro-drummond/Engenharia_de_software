#ifndef FLOW_INTERFACE_H
#define FLOW_INTERFACE_H

using namespace std;

class System;
class Flow {
    public:
    /// @brief This function runs the simulation of the model
    virtual ~Flow(){}

    /// @brief This function runs the simulation of the model
    /// @param iniTime  The initial time of the simulation
    virtual double run() = 0;

    /// @brief This function sets the name of the flow
    /// @param sName    The name to be set
    virtual void clearFlow() = 0;

    /// @brief This function gets the name of the flow
    /// @return string
    virtual void setSource(System *sOrigin) = 0;

    /// @brief This function sets the name of the flow
    /// @param sName    The name to be set
    virtual void setTarget(System *sDestination) = 0;

    /// @brief This function gets the name of the flow
    /// @return string
    virtual System* getSource() const = 0;

    /// @brief This function gets the name of the flow
    /// @return string
    virtual System* getTarget() const = 0;

};


#endif // FLOW_INTERFACE_H