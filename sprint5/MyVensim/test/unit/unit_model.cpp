#include "../../src/model_implementation.h"
//#include "../../src/system_implementation.h"
//#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../test/exponencial.h"
//#include "../../src/flow_implementation.h"
#include "../../test/logistic.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;


void unit_model_constructor(void){
    Model *m1 = new BaseModel("M1");
    assert(m1->getName() == "M1");
    cout << "unit_model_constructor passed" << endl;
    delete m1;
}

void unit_model_destructor(void){

}

void unit_model_getName(void){
    Model *mod = new BaseModel("M1");
    assert(mod->getName() == "M1");
    delete mod;

    cout << "unitModelGetName passed" << endl;
}

void unit_model_setName(void){
    Model *mod = new BaseModel("M1");
    mod->setName("M2");
    assert(mod->getName() == "M2");
    delete mod;

    cout << "unitModelSetName passed" << endl;
}

void unit_model_get_time(void){
    Model *mod = new BaseModel("M1");
    mod->setTime(0);
    assert(mod->getTime() == 0);
    delete mod;

    cout << "unit_model_get_time passed" << endl;
}

void unit_model_set_time(void){
    Model *mod = new BaseModel("M1");
    mod->setTime(0);
    assert(mod->getTime() == 0);
    mod->setTime(1);
    assert(mod->getTime() == 1);
    delete mod;

    cout << "unit_model_set_time passed" << endl;
}

void unit_model_get_step(void){
    Model *mod = new BaseModel("M1");
    mod->setStep(0);
    assert(mod->getStep() == 0);
    delete mod;

    cout << "unit_model_get_step passed" << endl;
}

void unit_model_set_step(void){
    Model *mod = new BaseModel("M1");
    mod->setStep(0);
    assert(mod->getStep() == 0);
    mod->setStep(1);
    assert(mod->getStep() == 1);
    delete mod;

    cout << "unit_model_set_step passed" << endl;
}

void unit_model_add(void){
    System *sys = NULL;
    Flow *flow = NULL;
    Model *mod = new BaseModel("M1");

    mod->add(sys);
    mod->add(flow);
    
    assert(find(mod->SystemBegin(), mod->SystemEnd(), sys) != mod->SystemEnd());
    assert(find(mod->FlowBegin(), mod->FlowEnd(), flow) != mod->FlowEnd());

    delete sys;
    delete flow;
    delete mod;

    cout << "unitModelAdd passed" << endl;
}

void unit_model_run(void){
    Model *mod = new BaseModel("Model");
    mod->setTime(0);
    mod->run(0, 1, 1);
    assert(fabs(round(mod->getTime()*10000) - 0) < 1);

    mod->run(100, 101, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    delete mod;

    cout << "unit_model_run passed" << endl;
}