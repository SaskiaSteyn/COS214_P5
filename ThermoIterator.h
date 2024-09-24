#ifndef CODE_THERMOITERATOR_H
#define CODE_THERMOITERATOR_H

#include "Integrator.h"

class Mediator;

class ThermoIterator{
    friend class Mediator;


protected:
    Integrator* current;
    Integrator* head;

public:
    ThermoIterator();
    Integrator* goToNext();
    void reset();
};


#endif //CODE_THERMOITERATOR_H
