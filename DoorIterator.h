#ifndef CODE_DOORITERATOR_H
#define CODE_DOORITERATOR_H

//#include "Integrator.h"
#include "DoorNode.h"

class DoorNode;

class DoorIterator {
    friend class DoorNode;
    protected:


    public:
        DoorNode* current;
        DoorNode* head;
        DoorIterator();
        DoorIterator(DoorNode *door);
        DoorNode* goToNext();
        void reset();
        void addNode(DoorNode* newNode);
};


#endif //CODE_DOORITERATOR_H
