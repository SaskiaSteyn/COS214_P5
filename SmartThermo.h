#ifndef CODE_SMARTTHERMO_H
#define CODE_SMARTTHERMO_H

#include "ThermoType.h"

class SmartThermo : public ThermoType{
    public:
        SmartThermo(float initialTemp);
        void increaseTemp(float newTemp) override;
        void decreaseTemp(float newTemp) override;
};


#endif //CODE_SMARTTHERMO_H
