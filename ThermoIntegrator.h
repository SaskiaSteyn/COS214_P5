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
        float getTemp();
        virtual bool getDoor() {return false;};
        virtual bool getLight() {return false;}
        virtual void increaseTemp(float newTemp) {thermostat->increaseTemp(newTemp);};
        virtual void decreaseTemp(float newTemp) {thermostat->decreaseTemp(newTemp);};

};


#endif //CODE_THERMOINTEGRATOR_H
