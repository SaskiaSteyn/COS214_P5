#ifndef CODE_LIGHTNODE_H
#define CODE_LIGHTNODE_H

#include "Mediator.h"

class Mediator;

class LightNode {
    public:
        LightNode();
        LightNode(Mediator *node);
        Mediator* light;
        LightNode* next;
        LightNode* prev;

};


#endif //CODE_LIGHTNODE_H
