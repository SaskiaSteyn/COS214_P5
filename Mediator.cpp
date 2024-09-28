#include "Mediator.h"

void Mediator::notifyLights() {

    cout << "Notifying all light nodes..." << endl;

}

void Mediator::notifyThermo() {

    cout << "Notifying all thermo nodes..." << endl;

}

void Mediator::notifyDoor() {

    cout << "Notifying all door nodes..." << endl;
}

void Mediator::handleReceivedMessage(string &message) {

    cout << "Message has been recieved: " << message << endl;
    cout << "Notifying all smart and legacy devices to change state" << endl;

}
