#ifndef CODE_DOORINTEGRATOR_H
#define CODE_DOORINTEGRATOR_H

#include "Integrator.h"

class DoorIntegrator : public Integrator{
public:
    void addDoor(Integrator* door);
};


#endif //CODE_DOORINTEGRATOR_H
