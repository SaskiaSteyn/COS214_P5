#ifndef CODE_LIGHTITERATOR_H
#define CODE_LIGHTITERATOR_H

//#include "Integrator.h"
#include "LightNode.h"

class LightNode;

class LightIterator{
    friend class LightNode;
    protected:


    public:
        LightIterator();
        LightIterator(LightNode *node);
        LightNode* goToNext();
        void reset();
        void addNode(LightNode *newNode);
        LightNode* current;
        LightNode* head;
};


#endif //CODE_LIGHTITERATOR_H
