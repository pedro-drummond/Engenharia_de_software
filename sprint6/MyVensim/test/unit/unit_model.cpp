#include "../../src/model_implementation.h"
#include "../../src/flow.h"
#include "../../test/exponencial.h"
#include "../../test/logistic.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;


void unit_model_constructor(void){
    Model *m1 = m1->createModel("M1");
    assert(m1->getName() == "M1");
    cout << "\nUNIT MODEL CONSTRUTOR - OK\n" << endl;
    delete m1;
}

void unit_model_destructor(void){

}

void unit_model_getName(void){
    Model *mod = mod->createModel("M1");
    assert(mod->getName() == "M1");
    delete mod;

    cout << "\nUNIT MODEL GET NAME - OK\n" << endl;
}

void unit_model_setName(void){
    Model *mod = mod->createModel("M1");
    mod->setName("M2");
    assert(mod->getName() == "M2");
    delete mod;

    cout << "\nUNIT MODEL SET NAME - OK\n" << endl;
}

void unit_model_get_time(void){
    Model *mod = mod->createModel("M1");
    mod->setTime(0);
    assert(mod->getTime() == 0);
    delete mod;
    cout << "\nUNIT MODEL GET TIME - OK\n" << endl;
}

void unit_model_set_time(void){
    Model *mod = mod->createModel("M1");
    mod->setTime(0);
    assert(mod->getTime() == 0);
    mod->setTime(1);
    assert(mod->getTime() == 1);
    delete mod;
    cout << "\nUNIT MODEL SET TIME - OK\n" << endl;

}

void unit_model_get_step(void){
    Model *mod = mod->createModel("M1");
    mod->setStep(0);
    assert(mod->getStep() == 0);
    delete mod;

    cout << "\nUNIT MODEL GET STEP - OK\n" << endl;

}

void unit_model_set_step(void){
    Model *mod = mod->createModel("M1");
    mod->setStep(0);
    assert(mod->getStep() == 0);
    mod->setStep(1);
    assert(mod->getStep() == 1);
    delete mod;
    cout << "\nUNIT MODEL SET STEP - OK\n" << endl;
}

void unit_model_add(void){
    System *sys = NULL;
    Flow *flow = NULL;
    Model *mod = mod->createModel("M1");

    mod->add(sys);
    mod->add(flow);
    
    assert(find(mod->SystemBegin(), mod->SystemEnd(), sys) != mod->SystemEnd());
    assert(find(mod->FlowBegin(), mod->FlowEnd(), flow) != mod->FlowEnd());

    delete sys;
    delete flow;
    delete mod;
    cout << "\nUNIT MODEL ADD - OK\n" << endl;
}

void unit_model_run(void){
    Model *mod = mod->createModel("Model");
    mod->setTime(0);
    mod->run(0, 1, 1);
    assert(fabs(round(mod->getTime()*10000) - 0) < 1);

    mod->run(100, 101, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    delete mod;

    cout << "\nUNIT MODEL RUN - OK\n" << endl;
}