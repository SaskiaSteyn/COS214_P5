#ifndef CODE_DOORNODE_H
#define CODE_DOORNODE_H

// #include "Mediator.h"
#include "Integrator.h"
// class Mediator;
class Integrator;

class DoorNode {

    public:
        DoorNode();
        DoorNode(Integrator *door);
        Integrator* door;
        DoorNode* next;
        DoorNode* prev;

};


#endif //CODE_DOORNODE_H
