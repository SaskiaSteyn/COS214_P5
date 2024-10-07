#ifndef CODE_LIGHTITERATOR_H
#define CODE_LIGHTITERATOR_H

//#include "Integrator.h"
#include "LightNode.h"

class Mediator;

class LightIterator{
    friend class Mediator;
    protected:
        LightNode* current;
        LightNode* head;

    public:
        LightIterator();
        LightIterator(LightNode *node);
        LightNode* goToNext();
        void reset();
        void addNode(LightNode *newNode);
};


#endif //CODE_LIGHTITERATOR_H
