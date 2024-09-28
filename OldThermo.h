#ifndef CODE_OLDTHERMO_H
#define CODE_OLDTHERMO_H

#include "ThermoType.h"

class OldThermo : public ThermoType{
    public:
        OldThermo(float initialTemp);
        void increaseTemp(float newTemp);
        void decreaseTemp(float newTemp);
};


#endif //CODE_OLDTHERMO_H
