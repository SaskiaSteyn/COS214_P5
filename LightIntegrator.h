#ifndef CODE_LIGHTINTEGRATOR_H
#define CODE_LIGHTINTEGRATOR_H

#include "Integrator.h"
#include "LightType.h"

class LightType;

class LightIntegrator : public Integrator{
    protected:
        LightType *light;
    public:
        LightIntegrator();
        void addLight(LightType* newLight);
        void setLight();
        bool getLight();
};


#endif //CODE_LIGHTINTEGRATOR_H
