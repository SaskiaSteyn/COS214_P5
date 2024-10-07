#ifndef CODE_THERMOTYPE_H
#define CODE_THERMOTYPE_H

#include "Integrator.h"

class ThermoType : public Integrator{
    protected:
        float temp;
    public:
        ThermoType(float initialTemp);
        virtual void increaseTemp(float newTemp);
        virtual void decreaseTemp(float newTemp);
        float getTemp();

        bool getDoor() {return false;};
        bool getLight() {return false;};

        virtual void setLight() {};
        virtual void toggleDoor() {};
};


#endif //CODE_THERMOTYPE_H
