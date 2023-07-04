#include <cassert>
using namespace std;

#include "unit_flow.h"
#include "../../test/exponencial.h"
#include "../../src/flow_implementation.h"
#include "../../src/flow.h"
#include "../../src/model.h"

void unit_flow_constructor(void){
    Model * model = Model::createModel("Modelo");

    System *system1 = model->createSystem("S1", 10);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getSource() == system1);
    assert(flow1->getTarget() == system2);

    delete model;
    cout << "TESTE CONSTRUTOR FLOW - OK\n" << endl;
}

void unit_flow_setSource(void){
    Model * model = Model::createModel("Modelo");

    System *system1 = model->createSystem("S1", 10);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    System *system3 = model->createSystem("S3", 10);
    flow1->setSource(system3);
    assert(flow1->getSource() == system3);
    delete model;
    cout << "TESTE SET SOURCE FLOW - OK\n" << endl;
}

void unit_flow_setTarget(void){
    Model * model = Model::createModel("Modelo");
    System *system1 = model->createSystem("S1", 10);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    System *system3 = model->createSystem("S3", 10);
    flow1->setTarget(system3);
    assert(flow1->getTarget() == system3);
    delete model;
    cout << "TESTE SET TARGET FLOW - OK\n" << endl;
}

void unit_flow_getSource(void){
    Model * model = Model::createModel("Modelo");
    System *system1 = model->createSystem("S1", 10);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getSource() == system1);
    delete model;
    cout << "TESTE GET SOURCE FLOW - OK\n" << endl;
}

void unit_flow_getTarget(void){
    Model * model = Model::createModel("Modelo");
    System *system1 = model->createSystem("S1", 10);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getTarget() == system2);
    delete model;
    cout << "TESTE GET TARGET FLOW - OK\n" << endl;
}

