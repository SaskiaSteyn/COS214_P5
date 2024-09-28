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

};


#endif //CODE_DOORTYPE_H
