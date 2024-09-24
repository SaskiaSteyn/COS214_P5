#ifndef CODE_DOORNODE_H
#define CODE_DOORNODE_H

#include "Integrator.h"

class DoorNode {

    public:
        Integrator* door;
        Integrator* next;
        Integrator* prev;

};


#endif //CODE_DOORNODE_H
