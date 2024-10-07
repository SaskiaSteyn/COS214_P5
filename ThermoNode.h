#ifndef CODE_THERMONODE_H
#define CODE_THERMONODE_H

// #include "Mediator.h"
// #include "Integrator.h"
#include "ThermoIntegrator.h"

class ThermoIntegrator;
// class Mediator;

class ThermoNode {

    public:
        ThermoNode();
        ThermoNode(ThermoIntegrator *thermo);
        ThermoIntegrator* thermo;
        ThermoNode* next;
        ThermoNode* prev;

};


#endif //CODE_THERMONODE_H
