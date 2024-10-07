#ifndef CODE_LIGHTNODE_H
#define CODE_LIGHTNODE_H

// #include "Mediator.h"
// #include "Integrator.h"
#include "LightIntegrator.h"

// class Mediator;
class LightIntegrator;

class LightNode {
    public:
        LightNode();
        LightNode(LightIntegrator *node);
        LightIntegrator* light;
        LightNode* next;
        LightNode* prev;

};


#endif //CODE_LIGHTNODE_H
