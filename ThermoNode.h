#ifndef CODE_THERMONODE_H
#define CODE_THERMONODE_H

#include "Mediator.h"

class Mediator;

class ThermoNode {

    public:
        ThermoNode();
        ThermoNode(Mediator *thermo);
        Mediator* thermo;
        ThermoNode* next;
        ThermoNode* prev;

};


#endif //CODE_THERMONODE_H
