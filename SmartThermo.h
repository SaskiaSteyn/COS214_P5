#ifndef CODE_SMARTTHERMO_H
#define CODE_SMARTTHERMO_H

#include "ThermoType.h"

class SmartThermo : public ThermoType{
    public:
        void increaseTemp(float temp);
        void decreaseTemp(float temp);
};


#endif //CODE_SMARTTHERMO_H
