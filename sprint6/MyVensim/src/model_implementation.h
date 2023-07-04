#ifndef MODEL_H
#define MODEL_H

#include "model.h"
#include <algorithm>
#include "handleBodySemDebug.h"

using namespace std;
/// The BaseModel class represents a simulation model with methods for running simulations and manipulating its components.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseModel *model = new BaseModel("Modelo");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class BaseModel : public Body {
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
/*
    BaseModel();
    BaseModel(string name);

    virtual ~BaseModel();
*/
    // Getter and setter
    virtual string getName() const;
    virtual void setTime(double sTime);
    virtual double getTime() const;
    virtual void setStep(double sStep);
    virtual double getStep() const;
    virtual void setName(string sName);

    // Functions
    virtual void run(double iniTime, double endTime, double step);
    virtual void add(Model* model);
    virtual void add(System* system);
    virtual void add(Flow* flow);
    virtual void remove(System* system);
    virtual void remove (Flow* flow);
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

    static Model* createModel(string);
    //virtual Model* createModel(string);
    virtual System* createSystem(string, double);
};

class ModelHandle : public Model, public Handle<BaseModel> {
    public:
        ModelHandle(string name){
            pImpl_->setName(name);
        }

         void run(double iniTime, double endTime, double Increment){
            pImpl_->run(iniTime, endTime, Increment);
        }

        double getTime() const{
            return pImpl_->getTime();
        }

        double getStep()const {
            return pImpl_->getStep();
        }

        void setTime(double sTime){
            pImpl_->setTime(sTime);
        }

        void setStep(double sIncrement){
            pImpl_->setStep(sIncrement);
        }

        void add(System* system){
            pImpl_->add(system);
        }

        void add(Flow* flow){
            pImpl_->add(flow);
        }

        void add(Model* model){
            pImpl_->add(model);
        }

        void remove(System* system){
            pImpl_->remove(system);
        }

        void remove(Flow* flow){
            pImpl_->remove(flow);
        }

        string getName() const {
            return pImpl_->getName();
        }

        void setName(string sName){
            pImpl_->setName(sName);
        }

        vector<System*>::iterator SystemBegin(void){
            return pImpl_->SystemBegin();
        }

        vector<System*>::iterator SystemEnd(void){
            return pImpl_->SystemEnd();
        }

        vector<Flow*>::iterator FlowBegin(void){
            return pImpl_->FlowBegin();
        }

        vector<Flow*>::iterator FlowEnd(void){
            return pImpl_->FlowEnd();
        }

        System* createSystem(string name, double value){
            return pImpl_->createSystem(name, value);
        }

};

#endif // MODEL_H

