#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/// The Model class represents a simulation model with methods for running simulations and manipulating its components.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Model *model = new Model("Modelo");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Model {
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


public:
    Model();
    Model(string name);
    virtual ~Model();

    // Getter and setter
    void setName(string sName);
    string getName() const;
    void setTime(double sTime);
    double getTime() const;
    void setStep(double sStep);
    double getStep() const;

    // Functions
    void run(double iniTime, double endTime, double step);
    void add(System* system);
    void add(Flow* flow);
    void remove(System* system);
    void remove (Flow* flow);

    // Private copy constructor and assignment operator to prevent cloning
    Model(const Model& model);
    Model& operator=(const Model& model);
};

#endif // MODEL_H

