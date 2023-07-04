#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H


#include <vector>

template <typename T>
struct ModelIterator {
    typename std::vector<T>::iterator begin;
    typename std::vector<T>::iterator end;
};
class System;
class Flow;
using namespace std;
class Model{
    public:
    /// @brief This function runs the simulation of the model
    virtual ~Model(){}

    /// @brief This function runs the simulation of the model
    /// @param iniTime  The initial time of the simulation
    /// @param endTime  The end time of the simulation
    /// @param step     The step of the simulation

    virtual void run(double iniTime, double endTime, double step) = 0;
    /// @brief This function adds a system to the model
    /// @param system   The system to be added
    virtual void add(System* system) = 0;

    /// @brief This function adds a flow to the model
    /// @param flow     The flow to be added
    virtual void add(Flow* flow) = 0;

    /// @brief This function removes a system from the model
    /// @param system   The system to be removed
    virtual void remove(System* system) = 0;

    /// @brief This function removes a flow from the model
    /// @param flow     The flow to be removed
    virtual void remove (Flow* flow) = 0;

    /// @brief This function returns the name of the model
    /// @return string
    virtual void setName(string sName) = 0;

    /// @brief This function returns the name of the model
    /// @return string
    virtual string getName() const = 0;

    /// @brief This function returns the time of the model
    /// @return double
    virtual void setTime(double sTime) = 0;

    /// @brief This function returns the time of the model
    /// @return double
    virtual double getTime() const = 0;

    /// @brief This function returns the step of the model
    /// @return double
    virtual void setStep(double sStep) = 0;

    /// @brief This function returns the step of the model
    /// @return double
    virtual double getStep() const = 0;

    ///@brief Get the First Iterator of the System Interface container
    ///@return vector<System*>::iterator
    virtual vector<System*>::iterator SystemBegin(void) = 0;

    ///@brief Get the Last Iterator of the System Interface container
    ///@return vector<System*>::iterator 
    virtual vector<System*>::iterator SystemEnd(void) = 0;

    ///@brief Get the First Iterator of the Flow container
    ///@return vector<Flow*>::iterator 
    virtual vector<Flow*>::iterator FlowBegin(void) = 0;

    ///@brief Get the Last Iterator of the Flow container
    ///@return vector<Flow*>::iterator 
    virtual vector<Flow*>::iterator FlowEnd(void) = 0;    
};
#endif // MODEL_INTERFACE_H