#ifndef CODE_LIGHTNODE_H
#define CODE_LIGHTNODE_H

// #include "Mediator.h"
#include "Integrator.h"

// class Mediator;
class Integrator;

class LightNode {
    public:
        LightNode();
        LightNode(Integrator *node);
        Integrator* light;
        LightNode* next;
        LightNode* prev;

};


#endif //CODE_LIGHTNODE_H
