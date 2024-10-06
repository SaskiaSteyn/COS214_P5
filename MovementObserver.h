#ifndef CODE_MOVEMENTOBSERVER_H
#define CODE_MOVEMENTOBSERVER_H

#include "MacroEvent.h"

class MovementObserver: public MacroEvent {
    protected:
        bool seesMovement;
    public:
        MovementObserver(): seesMovement(false) {};
        bool getMovement();
        void toggleMovement();
        string sendMessage();
};


#endif //CODE_MOVEMENTOBSERVER_H
