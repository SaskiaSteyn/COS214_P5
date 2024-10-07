#ifndef CODE_MOVEMENTOBSERVER_H
#define CODE_MOVEMENTOBSERVER_H

#include "MacroEvent.h"
#include "Mediator.h"

class MovementObserver {
    protected:
        bool seesMovement;
        Mediator *mediator;
    public:
        MovementObserver();
        MovementObserver(Mediator *newMediator);
        bool getMovement();
        void toggleMovement();
        void sendMessage();
};


#endif //CODE_MOVEMENTOBSERVER_H
