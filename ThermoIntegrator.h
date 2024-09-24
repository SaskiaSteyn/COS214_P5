#ifndef CODE_THERMOINTEGRATOR_H
#define CODE_THERMOINTEGRATOR_H

#include "Integrator.h"

class ThermoIntegrator : public Integrator{

public:
    void addThermo(Integrator* thermo);

};


#endif //CODE_THERMOINTEGRATOR_H
