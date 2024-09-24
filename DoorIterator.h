#ifndef CODE_DOORITERATOR_H
#define CODE_DOORITERATOR_H

#include "Integrator.h"

class Mediator;

class DoorIterator {
    friend class Mediator;
    protected:
        Integrator* current;
        Integrator* head;

    public:
        DoorIterator();
        Integrator* goToNext();
        void reset();
};


#endif //CODE_DOORITERATOR_H
