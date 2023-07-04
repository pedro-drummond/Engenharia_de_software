#ifndef MODEL_H
#define MODEL_H

#include "model.h"
#include <algorithm>

using namespace std;
/// The BaseModel class represents a simulation model with methods for running simulations and manipulating its components.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseModel *model = new BaseModel("Modelo");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class BaseModel : public Model {
protected:
    /// @brief This attribute represents the name of the model

    string name;
    /// @brief This attribute represents the time of the model

    double time;
    /// @brief  This attribute represents the step of the model

    double step;

    /// @brief This attribute represents the systems of the model

    vector<System*> systems;
    /// @brief This attribute represents the flows of the model

    vector<Flow*> flows;

    /// @brief This attribute represents the models of the model
    static vector<Model*> models;


public:
    BaseModel();
    BaseModel(string name);
    virtual ~BaseModel();

    // Getter and setter
    void setName(string sName);
    string getName() const;
    void setTime(double sTime);
    double getTime() const;
    void setStep(double sStep);
    double getStep() const;

    // Functions
    void run(double iniTime, double endTime, double step);
    void add(Model* model);
    void add(System* system);
    void add(Flow* flow);
    void remove(System* system);
    void remove (Flow* flow);
    typedef vector<System*>::iterator SystemIterator;
    
    ///@brief typedef a container for the Flow pointers
    ///@return FlowIterator
    typedef vector<Flow*>::iterator FlowIterator;

    ///@brief Get the First Iterator of System the container
    ///@return SystemIterator : First Iterator
    SystemIterator SystemBegin(void);

    
    ///@brief Get the Last Iterator of the System container
    ///@return SystemIterator 
    SystemIterator SystemEnd(void);

    
    ///@brief Get the First Iterator of the Flow container
    ///@return FlowIterator 
    FlowIterator FlowBegin(void);

    
    ///@brief Get the Last Iterator of the Flow container
    ///@return FlowIterator 
    FlowIterator FlowEnd(void);

    // Private copy constructor and assignment operator to prevent cloning
    BaseModel(const BaseModel& model);
    BaseModel& operator=(const BaseModel& model);


    static Model* createModel(string);
    //virtual Model* createModel(string);
    virtual System* createSystem(string, double);
};

#endif // MODEL_H

