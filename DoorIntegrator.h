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
    virtual bool getLight() {return false;};
    virtual float getTemp() {return 0.0;};
    virtual void setLight() {};
    virtual void toggleDoor() {};
    virtual void increaseTemp(float newTemp) {};
    virtual void decreaseTemp(float newTemp) {};
};


#endif //CODE_DOORINTEGRATOR_H
