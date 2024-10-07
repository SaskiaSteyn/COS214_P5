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
        ~LightIntegrator();
        void addLight(LightType* newLight);
        void setLight();
        bool getLight();
        virtual bool getDoor() {return false;};
        virtual float getTemp()  {return 0.0;};
        virtual void toggleDoor() {};
        virtual void increaseTemp(float newTemp) {};
        virtual void decreaseTemp(float newTemp) {};
};


#endif //CODE_LIGHTINTEGRATOR_H
