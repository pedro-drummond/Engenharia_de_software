#include "../src/model.h"

Model::Model() {}
Model::Model(string name) : name(name) {}
Model::~Model() {}

//getter and setter
/// @brief This function sets the name of the model
/// @param sName    The name to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model();
///     model->setName("Modelo");
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::setName(string sName) {
    name = sName;
}
/// @brief This function gets the name of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     cout << model->getName() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::string Model::getName() const {
    return name;
}
/// @brief This function sets the time and step of the model
/// @param sTime    The time to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model();
///     model->setTime(0);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::setTime(double sTime) {
    time = sTime;
}
/// @brief This function gets the time of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     cout << model->getTime() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double Model::getTime() const {
    return time;
}
/// @brief This function sets the step of the model
/// @param sStep    The step to be set
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model();
///     model->setStep(1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::setStep(double sStep) {
    step = sStep;
}
/// @brief This function gets the step of the model
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     cout << model->getStep() << endl;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double Model::getStep() const {
    return step;
}

/// @brief This function runs the simulation
/// @param iniTime  Initial time
/// @param endTime  Final time
/// @param step     Step
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     model->run(0, 10, 1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::run(double iniTime, double endTime, double step) {
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
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     model->add(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::add(System* system) {
    systems.push_back(system);
}
/// @brief This function adds a flow to the model
/// @param flow     The flow to be added
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::add(Flow* flow) {
    flows.push_back(flow);
}
/// @brief This function removes a system from the model
/// @param system   The system to be removed
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     model->add(system1);
///     model->remove(system1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::remove(System* system) {
    auto it = find(systems.begin(), systems.end(), system);
    if (it != systems.end()) {
        systems.erase(it);
    }
}
/// @brief This function removes a flow from the model
/// @param flow     The flow to be removed
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(flow1);
///     model->remove(flow1);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Model::remove(Flow* flow) {
    auto it = find(flows.begin(), flows.end(), flow);
    if (it != flows.end()) {
        flows.erase(it);
    }
}

/// @brief This is the copy constructor
/// @param model    The model to be copied
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     Model *model2 = new Model(*model);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Model::Model(const Model& model) {
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

///     Model *model = new Model("Modelo");
///     System *system1 = new System("S1", 100);
///     System *system2 = new System("S2", 10);
///     Logistic *flow1 = new Logistic(system1, system2);
///     model->add(system1);
///     model->add(system2);
///     model->add(flow1);
///     Model *model2 = new Model();
///     *model2 = *model;

/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Model& Model::operator=(const Model& model) {
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
