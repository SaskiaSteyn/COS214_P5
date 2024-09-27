#ifndef CODE_THERMONODE_H
#define CODE_THERMONODE_H

#include "Integrator.h"

class ThermoNode {

    public:
        ThermoNode();
        ThermoNode(Integrator *thermo);
        Integrator* thermo;
        ThermoNode* next;
        ThermoNode* prev;

};


#endif //CODE_THERMONODE_H
