#ifndef CODE_THERMOTYPE_H
#define CODE_THERMOTYPE_H

#include "Integrator.h"

class ThermoType : public Integrator{
    private:
        float temp;
    public:
        virtual void increaseTemp(float temp);
        virtual void decreaseTemp(float temp);
        float getTemp();
};


#endif //CODE_THERMOTYPE_H
