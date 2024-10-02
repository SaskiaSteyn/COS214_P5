#ifndef CODE_DOORNODE_H
#define CODE_DOORNODE_H

#include "Mediator.h"

class Mediator;

class DoorNode {

    public:
        DoorNode();
        DoorNode(Mediator *door);
        Mediator* door;
        DoorNode* next;
        DoorNode* prev;

};


#endif //CODE_DOORNODE_H
