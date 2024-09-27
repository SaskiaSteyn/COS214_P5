#ifndef CODE_DOORITERATOR_H
#define CODE_DOORITERATOR_H

//#include "Integrator.h"
#include "DoorNode.h"

class Mediator;

class DoorIterator {
    friend class Mediator;
    protected:
        DoorNode* current;
        DoorNode* head;

    public:
        DoorIterator(DoorNode *door);
        DoorNode* goToNext();
        void reset();
};


#endif //CODE_DOORITERATOR_H
