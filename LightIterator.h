#ifndef CODE_LIGHTITERATOR_H
#define CODE_LIGHTITERATOR_H

#include "Integrator.h"

class Mediator;

class LightIterator{
    friend class Mediator;
    protected:
        Integrator* current;
        Integrator* head;

    public:
        LightIterator();
        Integrator* goToNext();
        void reset();

};


#endif //CODE_LIGHTITERATOR_H
