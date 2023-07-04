#include "../src/model_implementation.h"
#include "system.h"
#include "flow.h"

BaseModel::BaseModel() {}
BaseModel::BaseModel(string name) : name(name) {}
BaseModel::~BaseModel() {}

//getter and setter
/// @brief This function sets the name of the model
/// @param sName    The name to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel();
///     model->setName("Modelo");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::setName(string sName) {
    name = sName;
}
/// @brief This function gets the name of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     cout << model->getName() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::string BaseModel::getName() const {
    return name;
}
/// @brief This function sets the time and step of the model
/// @param sTime    The time to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel();
///     model->setTime(0);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::setTime(double sTime) {
    time = sTime;
}
/// @brief This function gets the time of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     cout << model->getTime() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double BaseModel::getTime() const {
    return time;
}
/// @brief This function sets the step of the model
/// @param sStep    The step to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel();
///     model->setStep(1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::setStep(double sStep) {
    step = sStep;
}
/// @brief This function gets the step of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     cout << model->getStep() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double BaseModel::getStep() const {
    return step;
}

/// @brief This function runs the simulation
/// @param iniTime  Initial time
/// @param endTime  Final time
/// @param step     Step
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     model->run(0, 10, 1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::run(double iniTime, double endTime, double step) {
    this->setTime(iniTime);
    this->setStep(step);
    vector<double> results;
    int count = 0;
    for (double i = iniTime; i < endTime; i += step) {
        for (Flow* it : flows) {
            double result = it->run();
            results.push_back(result);
        }

        count = 0;
        for (Flow* it : flows) {
            System* origin = it->getSource();
            origin->setValue(origin->getValue() - results[count]);
            //cout << origin->getName() << " " << origin->getValue() << endl;
            System* destination = it->getTarget();
            destination->setValue(destination->getValue() + results[count]);
            //cout << destination->getName() << " " << destination->getValue() << endl;
            count++;
        }

        results.clear();
    }
}
/// @brief This function adds a system to the model
/// @param system   The system to be added
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     model->add(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::add(System* system) {
    systems.push_back(system);
}
/// @brief This function adds a flow to the model
/// @param flow     The flow to be added
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::add(Flow* flow) {
    flows.push_back(flow);
}
/// @brief This function removes a system from the model
/// @param system   The system to be removed
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     model->add(system1);
///     model->remove(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::remove(System* system) {
    auto it = find(systems.begin(), systems.end(), system);
    if (it != systems.end()) {
        systems.erase(it);
    }
}
/// @brief This function removes a flow from the model
/// @param flow     The flow to be removed
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(flow1);
///     model->remove(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void BaseModel::remove(Flow* flow) {
    auto it = find(flows.begin(), flows.end(), flow);
    if (it != flows.end()) {
        flows.erase(it);
    }
}

/// @brief This is the copy constructor
/// @param model    The model to be copied
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     BaseModel *model2 = new BaseModel(*model);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BaseModel::BaseModel(const BaseModel& model) {
    name = model.getName();
    time = model.getTime();
    step = model.getStep();
    for (System* it : model.systems) {
        systems.push_back(it);
    }
    for (Flow* it : model.flows) {
        flows.push_back(it);
    }
}

/// @brief This is the assignment operator
/// @param model    The model to be assigned
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp

///     BaseModel *model = new BaseModel("Modelo");
///     BaseSystem *system1 = new BaseSystem("S1", 100);
///     BaseSystem *system2 = new BaseSystem("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     BaseModel *model2 = new BaseModel();
///     *model2 = *model;

/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BaseModel& BaseModel::operator=(const BaseModel& model) {
    if (this == &model)
        return *this;
    name = model.getName();
    time = model.getTime();
    step = model.getStep();
    systems.clear();
    flows.clear();
    for (System* it : model.systems) {
        systems.push_back(it);
    }
    for (Flow* it : model.flows) {
        flows.push_back(it);
    }
    return *this;
}

BaseModel::SystemIterator BaseModel::SystemBegin(void){
    return systems.begin();
}

BaseModel::SystemIterator BaseModel::SystemEnd(void){
    return systems.end();
}

BaseModel::FlowIterator BaseModel::FlowBegin(void){
    return flows.begin();
}

BaseModel::FlowIterator BaseModel::FlowEnd(void){
    return flows.end();
}

