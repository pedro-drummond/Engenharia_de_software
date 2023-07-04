//unit tests
#include <cassert>
using namespace std;

#include "unit_system.h"
#include "../../src/system_implementation.h"
#include "../../src/system.h"

void unit_system_constructor(void){
    System *system1 = new BaseSystem();
    assert(system1->getValue() == 0);
    System *system2 = new BaseSystem("S2", 10);
    assert(system2->getValue() == 10);
    assert(system2->getName() == "S2");
    delete(system1);
    delete(system2);
    cout << "TESTE CONSTRUTOR SYSTEM - OK\n" << endl;
}

void unit_system_setValue(void){
    System *system1 = new BaseSystem();
    system1->setValue(10);
    assert(system1->getValue() == 10);
    delete(system1);
    cout << "TESTE SET VALUE SYSTEM - OK\n" << endl;
}

void unit_system_setName(void){
    System *system1 = new BaseSystem();
    system1->setName("S1");
    assert(system1->getName() == "S1");
    delete(system1);
    cout << "TESTE SET NAME SYSTEM - OK\n" << endl;
}

void unit_system_getValue(void){
    System *system1 = new BaseSystem();
    assert(system1->getValue() == 0);
    delete(system1);
    cout << "TESTE GET VALUE SYSTEM - OK\n" << endl;
}

void unit_system_getName(void){
    System *system1 = new BaseSystem("S1", 10);
    assert(system1->getName() == "S1");
    delete(system1);
    cout << "TESTE GET NAME SYSTEM - OK\n" << endl;
}