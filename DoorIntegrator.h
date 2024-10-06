#ifndef CODE_DOORINTEGRATOR_H
#define CODE_DOORINTEGRATOR_H

#include "Integrator.h"
#include "DoorType.h"

class DoorIntegrator : public Integrator{
public:
protected:
    DoorType *door;
public:
    DoorIntegrator();
    ~DoorIntegrator();
    void addDoor(DoorType* newDoor);
    void setDoor();
    bool getDoor();
};


#endif //CODE_DOORINTEGRATOR_H
