#include "unit_tests.h"


void unit_system(void){
    unit_system_constructor();
    unit_system_setValue();
    unit_system_setName();
    unit_system_getValue();
    unit_system_getName();
}

void model_test(void){
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getName();
    unit_model_setName();
    unit_model_get_time();
    unit_model_set_time();
    unit_model_get_step();
    unit_model_set_step();
    unit_model_add();
    unit_model_run();

}

void unit_flow(void){
    unit_flow_constructor();
    unit_flow_setSource();
    unit_flow_setTarget();
    unit_flow_getSource();
    unit_flow_getTarget();
}

void unit_tests(void){
    cout << "\n------------------------\nUNIT TEST - FLOW\n------------------------" <<endl; 
    unit_flow();
    cout << "\n------------------------\nUNIT TEST - SYSTEM\n------------------------" <<endl; 
    unit_system();
    cout << "\n------------------------\nUNIT TEST - MODEL\n------------------------" <<endl; 
    model_test();
}