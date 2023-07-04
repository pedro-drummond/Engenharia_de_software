#include <cmath>
#include <algorithm>
#include "../../src/model.h"
#include "../../test/exponencial.h"
#include "../../test/logistic.h"
#include "functional_tests.h"
#include <cassert>
using namespace std;
/// @brief test for the exponential function

int numHandleDeleted = 0;
int numHandleCreated = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

void exponential_funcional_test(){
    
    cout << "\nTESTE FUNÇÃO EXPONENCIAL\n" << endl;
    Model *model = Model::createModel("Modelo");
    System *system1 = model->createSystem("S1", 100);
    System *system2 = model->createSystem("S2", 0);
    Flow *flow1 = model->createFlow<Exp>(system1, system2);
    
    assert(system1->getValue() - 100 < 0.0001);
    assert(system2->getValue() - 0 < 0.0001);
    cout << "Valores iniciais - OK" << endl;

    model->run(0, 100, 1);
    assert(round(system1->getValue() - 36.6032) * 10000 == 0);
    assert(round(system2->getValue() - 63.3968) * 10000 == 0);
    
    cout << "Valores finais - OK" << endl;
    cout << "TESTE FUNÇÃO EXPONENCIAL - OK\n" << endl;
    delete(model);

}

/// @brief test for the logistic function
void logistic_funcional_test(){
    cout << "\nTESTE FUNÇÃO LOGISTICA\n" << endl;
    Model *model = Model::createModel("Modelo");
    System *system1 = model->createSystem("S1", 100);
    System *system2 = model->createSystem("S2", 10);
    Flow *flow1 = model->createFlow<Logistic>(system1, system2);

    assert(system1->getValue() - 100 < 0.0001);
    assert(system2->getValue() - 10 < 0.0001);
    cout << "Valores iniciais - OK" << endl;
    model->run(0, 100, 1);
    assert(round(system1->getValue() - 88.2167) * 10000 == 0);
    assert(round(system2->getValue() - 21.7833) * 10000 == 0);

    cout << "Valores finais - OK" << endl;
    cout << "TESTE FUNÇÃO LOGISTICA - OK\n" << endl;
    delete(model);

}

/// @brief test for the exponential function in a system
void exponential_system_funcional_test(){
    cout << "\nTESTE SISTEMAS DE FUNÇÃO EXPONENCIAL\n" << endl;
    Model *model = model->createModel("Modelo");
    System *q1 = model->createSystem("q1", 100);
    System *q2 = model->createSystem("q2", 0);
    System *q3 = model->createSystem("q3", 100);
    System *q4 = model->createSystem("q4", 0);
    System *q5 = model->createSystem("q5", 0);

    Flow *g = model->createFlow<Exp>(q1,q3);
    Flow *u = model->createFlow<Exp>(q3,q4);
    Flow *v = model->createFlow<Exp>(q4,q1);
    Flow *t = model->createFlow<Exp>(q2,q3);
    Flow *r = model->createFlow<Exp>(q2,q5);
    Flow *f = model->createFlow<Exp>(q1, q2);


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

}
