#include <cassert>
using namespace std;

#include "unit_flow.h"
#include "../../test/exponencial.h"
#include "../../src/flow_implementation.h"
#include "../../src/flow.h"

void unit_flow_constructor(void){

    System *system1 = new BaseSystem("S1", 10);
    System *system2 = new BaseSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getSource() == system1);
    assert(flow1->getTarget() == system2);
    delete (BaseSystem*)(system1);
    delete (BaseSystem*)(system2);
    delete (BaseSystem*)(flow1);
    cout << "TESTE CONSTRUTOR FLOW - OK\n" << endl;
}

void unit_flow_setSource(void){
    System *system1 = new BaseSystem("S1", 10);
    System *system2 = new BaseSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    System *system3 = new BaseSystem("S3", 10);
    flow1->setSource(system3);
    assert(flow1->getSource() == system3);
    delete (BaseSystem*)system1;
    delete (BaseSystem*)(system2);
    delete (BaseSystem*)(system3);
    delete (BaseSystem*)(flow1);
    cout << "TESTE SET SOURCE FLOW - OK\n" << endl;
}

void unit_flow_setTarget(void){
    System *system1 = new BaseSystem("S1", 10);
    System *system2 = new BaseSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    System *system3 = new BaseSystem("S3", 10);
    flow1->setTarget(system3);
    assert(flow1->getTarget() == system3);
    delete(BaseSystem*)(system1);
    delete(BaseSystem*)(system2);
    delete(BaseSystem*)(system3);
    delete(Exp*)(flow1);
    cout << "TESTE SET TARGET FLOW - OK\n" << endl;
}

void unit_flow_getSource(void){
    System *system1 = new BaseSystem("S1", 10);
    System *system2 = new BaseSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getSource() == system1);
    delete(BaseSystem*)(system1);
    delete(BaseSystem*)(system2);
    delete(Exp*)(flow1);
    cout << "TESTE GET SOURCE FLOW - OK\n" << endl;
}

void unit_flow_getTarget(void){
    System *system1 = new BaseSystem("S1", 10);
    System *system2 = new BaseSystem("S2", 10);
    Flow *flow1 = new Exp(system1, system2);
    assert(flow1->getTarget() == system2);
    delete(BaseSystem*)(system1);
    delete(BaseSystem*)(system2);
    delete(Exp*)(flow1);
    cout << "TESTE GET TARGET FLOW - OK\n" << endl;
}

