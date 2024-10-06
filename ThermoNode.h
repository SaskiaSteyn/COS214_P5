#ifndef CODE_THERMONODE_H
#define CODE_THERMONODE_H

// #include "Mediator.h"
#include "Integrator.h"

class Integrator;
// class Mediator;

class ThermoNode {

    public:
        ThermoNode();
        ThermoNode(Integrator *thermo);
        Integrator* thermo;
        ThermoNode* next;
        ThermoNode* prev;

};


#endif //CODE_THERMONODE_H
