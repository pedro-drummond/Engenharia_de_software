#ifndef EXP_TEST_H
#define EXP_TEST_H

#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../src/model.h"
#include "../src/system.h"
#include "../test/exponencial.h"
#include "../src/flow.h"
#include "../test/logistic.h"
#include <cassert>
using namespace std;
/// @brief test for the exponential function
void exponential_funcional_test(){
    cout << "\nTESTE FUNÇÃO EXPONENCIAL\n" << endl;
    Model *model = new Model("Modelo");
    System *system1 = new System("S1", 100);
    System *system2 = new System("S2", 0);
    Exp *flow1 = new Exp(system1, system2);
    model->add(flow1);
    model->add(system1);
    model->add(system2);

    assert(system1->getValue() - 100 < 0.0001);
    assert(system2->getValue() - 0 < 0.0001);
    cout << "Valores iniciais - OK" << endl;

    model->run(0, 100, 1);
    assert(round(system1->getValue() - 36.6032) * 10000 == 0);
    assert(round(system2->getValue() - 63.3968) * 10000 == 0);

    cout << "Valores finais - OK" << endl;
    cout << "TESTE FUNÇÃO EXPONENCIAL - OK\n" << endl;
    delete(model);
    delete(system1);
    delete(system2);
    delete(flow1);

}
/// @brief test for the logistic function
void logistic_funcional_test(){
    cout << "\nTESTE FUNÇÃO LOGISTICA\n" << endl;
    Model *model = new Model("Modelo");
    System *system1 = new System("S1", 100);
    System *system2 = new System("S2", 10);
    Logistic *flow1 = new Logistic(system1, system2);
    model->add(flow1);
    model->add(system1);
    model->add(system2);
    assert(system1->getValue() - 100 < 0.0001);
    assert(system2->getValue() - 10 < 0.0001);
    cout << "Valores iniciais - OK" << endl;
    model->run(0, 100, 1);
    assert(round(system1->getValue() - 88.2167) * 10000 == 0);
    assert(round(system2->getValue() - 21.7833) * 10000 == 0);

    cout << "Valores finais - OK" << endl;
    cout << "TESTE FUNÇÃO LOGISTICA - OK\n" << endl;
    delete(model);
    delete(system1);
    delete(system2);
    delete(flow1);


}

/// @brief test for the exponential function in a system
void exponential_system_funcional_test(){
    cout << "\nTESTE SISTEMAS DE FUNÇÃO EXPONENCIAL\n" << endl;
    Model *model = new Model("Modelo");
    System *q1 = new System("q1", 100);
    System *q2 = new System("q2", 0);
    System *q3 = new System("q3", 100);
    System *q4 = new System("q4", 0);
    System *q5 = new System("q5", 0);
    Exp *f = new Exp(q1, q2);
    Exp *g = new Exp(q1,q3);
    Exp *u = new Exp(q3,q4);
    Exp *v = new Exp(q4,q1);
    Exp *t = new Exp(q2,q3);
    Exp *r = new Exp(q2,q5);
    model->add(f);
    model->add(g);
    model->add(u);
    model->add(v);
    model->add(t);
    model->add(r);
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);

    assert(q1->getValue() - 100 < 0.0001);
    assert(q2->getValue() - 0 < 0.0001);
    assert(q3->getValue() - 100 < 0.0001);
    assert(q4->getValue() - 0 < 0.0001);
    assert(q5->getValue() - 0 < 0.0001);
    cout << "Valores iniciais - OK" << endl;

    model->run(0, 100, 1);
    assert(round(q1->getValue() - 31.8513) * 10000 == 0);
    assert(round(q2->getValue() - 18.4003) * 10000 == 0);
    assert(round(q3->getValue() - 77.1143) * 10000 == 0);
    assert(round(q4->getValue() - 56.1728) * 10000 == 0);
    assert(round(q5->getValue() - 16.4612) * 10000 == 0);

    cout << "Valores finais - OK" << endl;
    cout << "TESTE SISTEMAS DE FUNÇÃO EXPONENCIAL - OK\n" << endl;
    delete model;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete f;
    delete g;
    delete u;
    delete v;
    delete t;
    delete r;
    
}

#endif // EXP_TEST_H
