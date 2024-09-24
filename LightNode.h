#ifndef CODE_LIGHTNODE_H
#define CODE_LIGHTNODE_H

#include "Integrator.h"

class LightNode {
    public:
        Integrator* light;
        Integrator* next;
        Integrator* prev;

};


#endif //CODE_LIGHTNODE_H
