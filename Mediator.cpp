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

void Mediator::handleReceivedMessage(string message) {

    cout << "Message has been recieved: " << message << endl;
    cout << "Notifying all smart and legacy devices to change state" << endl;

}

void Mediator::addLightNode(LightNode* light) {
//    if (lightHead == nullptr) {
//        delete lightHead;
//        lightHead = light;
//    }
//    else {
//        LightNode *current = lightHead;
//        while (current->next != nullptr) {
//            current = current->next;
//        }
//        current->next = light;
//    }

    if (lightHead == nullptr) {
        lightHead = light;  // Just assign without deleting
    } else {
        LightNode *current = lightHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = light;
    }
}

void Mediator::addThermoNode(ThermoNode* thermo) {
    if (thermoHead == nullptr) {
        //the below line causes problems
//        delete thermoHead;
        thermoHead = thermo;
    }
    else {
        ThermoNode *current = thermoHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = thermo;
    }
}

void Mediator::addDoorNode(DoorNode* door){
    if (doorHead == nullptr) {
        //the below line causes problems
        // delete doorHead;
        doorHead = door;
    }
    else {
        DoorNode *current = doorHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = door;
    }
}
