#ifndef CODE_THERMOINTEGRATOR_H
#define CODE_THERMOINTEGRATOR_H

#include "Integrator.h"
#include "ThermoType.h"

class ThermoIntegrator : public Integrator{

public:
    protected:
        ThermoType *thermostat;
    public:
        ThermoIntegrator();
        ~ThermoIntegrator();
        void addThermo(ThermoType* newThermo);
        void setThermo(float oldTemp, float newTemp);
        float getThermo();

};


#endif //CODE_THERMOINTEGRATOR_H
