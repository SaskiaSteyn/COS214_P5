#include "Mediator.h"

Mediator::Mediator() {
    lightIteratorLivingArea = new LightIterator();
    lightIteratorBedrooms = new LightIterator();

    thermoIteratorLivingArea = new ThermoIterator();
    thermoIteratorBedrooms = new ThermoIterator();

    doorIteratorLivingArea = new DoorIterator();
    doorIteratorBedrooms = new DoorIterator();
}


void Mediator::notifyLights(bool state) {

    lightIteratorLivingArea->reset();
    while (lightIteratorLivingArea->current != nullptr) {
        if (state && !lightIteratorLivingArea->current->light->getLight()) {
            lightIteratorLivingArea->current->light->setLight();
        }
        else if (!state && lightIteratorLivingArea->current->light->getLight()) {
            lightIteratorLivingArea->current->light->setLight();
        }

        lightIteratorLivingArea->goToNext();
    }
    lightIteratorLivingArea->reset();

    lightIteratorBedrooms->reset();
    while (lightIteratorBedrooms->current != nullptr) {
        if (state && !lightIteratorBedrooms->current->light->getLight()) {
            lightIteratorBedrooms->current->light->setLight();
        }
        else if (!state && lightIteratorBedrooms->current->light->getLight()) {
            lightIteratorBedrooms->current->light->setLight();
        }

        lightIteratorBedrooms->goToNext();
    }
    lightIteratorBedrooms->reset();

    cout << "Notifying all light nodes..." << endl;
}

void Mediator::notifyThermo(float temp) {

    float newTemp = temp - thermoIteratorLivingArea->head->thermo->getTemp();
    if (newTemp > 0) {
        thermoIteratorLivingArea->head->thermo->increaseTemp(temp);
        thermoIteratorBedrooms->head->thermo->increaseTemp(abs(temp - 2));
    }
    else {
        thermoIteratorLivingArea->head->thermo->decreaseTemp(temp);
        thermoIteratorBedrooms->head->thermo->decreaseTemp(abs(temp - 2));
    }

    cout << "Notifying all thermo nodes..." << endl;

}

void Mediator::notifyDoor(bool state) {

    doorIteratorBedrooms->reset();
    while (doorIteratorBedrooms->current != nullptr) {
        if (state && !doorIteratorBedrooms->current->door->getDoor()) {
            doorIteratorBedrooms->current->door->toggleDoor();
        }
        else if (!state && doorIteratorBedrooms->current->door->getLight()) {
            doorIteratorBedrooms->current->door->toggleDoor();
        }

        doorIteratorBedrooms->goToNext();
    }
    doorIteratorBedrooms->reset();

    doorIteratorLivingArea->reset();
    while (doorIteratorLivingArea->current != nullptr) {
        if (state && !doorIteratorLivingArea->current->door->getDoor()) {
            doorIteratorLivingArea->current->door->toggleDoor();
        }
        else if (!state && doorIteratorLivingArea->current->door->getLight()) {
            doorIteratorLivingArea->current->door->toggleDoor();
        }

        doorIteratorLivingArea->goToNext();
    }
    doorIteratorLivingArea->reset();

    cout << "Notifying all door nodes..." << endl;
}

void Mediator::handleReceivedMessage(string message) {

    cout << "Message has been recieved: " << message << endl;
    cout << "Notifying all smart and legacy devices to change state" << endl;

    // Time Messages
    if (message == "Time changed to afternoon") {
        this->notifyThermo(18.0);
    }



    // Movement Messages
    if (message == "Turn on lights. Unlock doors. Set temperature to 18") {
        notifyLights(true);
        notifyDoor(false);
        notifyThermo(18.0);
    }
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
