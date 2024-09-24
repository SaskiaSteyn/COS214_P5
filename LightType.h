#ifndef CODE_LIGHTTYPE_H
#define CODE_LIGHTTYPE_H

#include "Integrator.h"

class LightType : public Integrator{
    private:
        bool lightOnOff;

    public:
        virtual void setLight();
        bool getLight();

};


#endif //CODE_LIGHTTYPE_H
