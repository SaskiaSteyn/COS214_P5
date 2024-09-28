#ifndef CODE_LIGHTNODE_H
#define CODE_LIGHTNODE_H

#include "Integrator.h"

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
