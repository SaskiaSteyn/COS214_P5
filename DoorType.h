#ifndef CODE_DOORTYPE_H
#define CODE_DOORTYPE_H

#include "Integrator.h"

class DoorType : public Integrator{
    protected:
        bool doorLocked;
    public:
        DoorType();
        virtual void toggleDoor();
        bool getDoor();

        float getTemp() {return 0.0;};
        bool getLight() {return false;};

        virtual void setDoor() {};
        virtual void setLight() {};
        virtual void increaseTemp(float newTemp) {};
        virtual void decreaseTemp(float newTemp) {};
};


#endif //CODE_DOORTYPE_H
