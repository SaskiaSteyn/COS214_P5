#include "MovementObserver.h"

string MovementObserver::sendMessage() {
    if (seesMovement) {
        return "Turn on lights. Unlock doors. Set temperature to 18";
    }
    else {
        return "Turn off lights. Lock doors. Set temperature to 25";
    }
}

bool MovementObserver::getMovement() {
    return seesMovement;
}

void MovementObserver::toggleMovement() {
    seesMovement = !seesMovement;
    sendMessage();
}