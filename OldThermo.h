#ifndef CODE_OLDTHERMO_H
#define CODE_OLDTHERMO_H

#include "ThermoType.h"

class OldThermo : public ThermoType{
    public:
        void increaseTemp(float temp);
        void decreaseTemp(float temp);
};


#endif //CODE_OLDTHERMO_H
