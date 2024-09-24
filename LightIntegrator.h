#ifndef CODE_LIGHTINTEGRATOR_H
#define CODE_LIGHTINTEGRATOR_H

#include "Integrator.h"

class LightIntegrator : public Integrator{
    public:
        void addLight(Integrator* light);
};


#endif //CODE_LIGHTINTEGRATOR_H
