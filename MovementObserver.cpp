#include "MovementObserver.h"

MovementObserver::MovementObserver() {}

MovementObserver::MovementObserver(Mediator* newMediator) {
    this->mediator = newMediator;
}

void MovementObserver::sendMessage() {
    if (seesMovement) {
        this->mediator->handleReceivedMessage("Turn on lights. Unlock doors. Set temperature to 18");
    }
    else {
        this->mediator->handleReceivedMessage("Turn off lights. Lock doors. Set temperature to 25");
    }
}

bool MovementObserver::getMovement() {
    return seesMovement;
}

void MovementObserver::toggleMovement() {
    seesMovement = !seesMovement;
    sendMessage();
}

void MovementObserver::sendCustomMessage(string message) {
    this->mediator->handleReceivedMessage(message);
}
