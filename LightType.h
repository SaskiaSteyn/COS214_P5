#ifndef CODE_LIGHTTYPE_H
#define CODE_LIGHTTYPE_H

#include "Integrator.h"

class LightType : public Integrator{
    protected:
        bool lightOnOff;

    public:
        LightType();
        virtual void setLight();
        bool getLight();

};


#endif //CODE_LIGHTTYPE_H
