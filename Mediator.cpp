#include "Mediator.h"

Mediator::Mediator() {
    lightIteratorLivingArea = new LightIterator();
    lightIteratorBedrooms = new LightIterator();

    thermoIteratorLivingArea = new ThermoIterator();
    thermoIteratorBedrooms = new ThermoIterator();

    doorIteratorLivingArea = new DoorIterator();
    doorIteratorBedrooms = new DoorIterator();
}


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

void Mediator::addLivingAreaLightNode(LightNode* light) {
    lightIteratorLivingArea->addNode(light);
}

void Mediator::addBedroomsLightNode(LightNode* light) {
    lightIteratorBedrooms->addNode(light);
}

void Mediator::addLivingAreaThermoNode(ThermoNode* thermo) {
    thermoIteratorLivingArea->addNode(thermo);
}

void Mediator::addBedroomsThermoNode(ThermoNode* thermo) {
    thermoIteratorBedrooms->addNode(thermo);
}

void Mediator::addLivingAreaDoorNode(DoorNode* door) {
    doorIteratorLivingArea->addNode(door);
}

void Mediator::addBedroomsDoorNode(DoorNode* door) {
    doorIteratorBedrooms->addNode(door);
}
