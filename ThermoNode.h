#ifndef CODE_THERMONODE_H
#define CODE_THERMONODE_H

#include "Integrator.h"

class ThermoNode {

    public:
        Integrator* thermo;
        Integrator* next;
        Integrator* prev;

};


#endif //CODE_THERMONODE_H
