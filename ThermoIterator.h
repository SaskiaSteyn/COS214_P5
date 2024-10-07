#ifndef CODE_THERMOITERATOR_H
#define CODE_THERMOITERATOR_H

//#include "Integrator.h"
#include "ThermoNode.h"

class Mediator;

class ThermoIterator{
    friend class Mediator;


protected:


public:
    ThermoNode* current;
    ThermoNode* head;
    ThermoIterator();
    ThermoIterator(ThermoNode *thermo);
    ThermoNode* goToNext();
    void reset();
    void addNode(ThermoNode* newNode);
};


#endif //CODE_THERMOITERATOR_H
