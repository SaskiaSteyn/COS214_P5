#ifndef CODE_DOORTYPE_H
#define CODE_DOORTYPE_H

#include "Integrator.h"

class DoorType : public Integrator{
    private:
        bool doorLocked;
    public:
        virtual void toggleDoor();
        bool getDoor();

};


#endif //CODE_DOORTYPE_H
