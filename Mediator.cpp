/**
 * @file Mediator.cpp
 * @author Johan
 * @brief Mediator of the mediator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Mediator.h"

/**
 * @brief Construct a new Mediator:: Mediator object
 * 
 */
Mediator::Mediator() {
    lightIteratorLivingArea = new LightIterator();
    lightIteratorBedrooms = new LightIterator();

    thermoIteratorLivingArea = new ThermoIterator();
    thermoIteratorBedrooms = new ThermoIterator();

    doorIteratorLivingArea = new DoorIterator();
    doorIteratorBedrooms = new DoorIterator();
}


/**
 * @brief Notify the lights to change state
 * 
 * @param state 
 */
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

    // cout << "Notifying all light nodes..." << endl;
}

/**
 * @brief Notify the thermo to change state
 * 
 * @param temp 
 */
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

    // cout << "Notifying all thermo nodes..." << endl;

}

/**
 * @brief Notify the doors to change state
 * 
 * @param state 
 */
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

    // cout << "Notifying all door nodes..." << endl;
}

/**
 * @brief Handle the received message
 * 
 * @param message 
 */
void Mediator::handleReceivedMessage(string message) {

    // cout << "Message has been recieved: " << message << endl;
    // cout << "Notifying all smart and legacy devices to change state" << endl;

    // Time Messages
    if (message == "Time changed to morning") {
        this->notifyLights(false);
        this->notifyThermo(19.0);
        this->notifyDoor(false);
    }
    else if (message == "Time changed to afternoon") {
        this->notifyThermo(20.0);
    }
    else if (message == "Time changed to evening") {
        this->notifyLights(true);
        this->notifyThermo(22.5);
        this->notifyDoor(true);
    }
    else if (message == "Time changed to night") {
        this->notifyThermo(24.0);
    }


    // Movement Messages
    else if (message == "Turn on lights. Unlock doors. Set temperature to 18") {
        notifyLights(true);
        notifyDoor(false);
        notifyThermo(18.0);
    }

    // Custom Movement Messages
    else if (message == "Walked into the living room") {
        notifyLights(false);
        lightIteratorLivingArea->reset();
        lightIteratorLivingArea->goToNext();
        lightIteratorLivingArea->goToNext();
        if (!lightIteratorLivingArea->current->light->getLight()) {
            lightIteratorLivingArea->current->light->setLight();
        }
        lightIteratorLivingArea->reset();
    }
    else if (message == "Walked into the kitchen") {
        notifyLights(false);
        lightIteratorLivingArea->reset();
        lightIteratorLivingArea->goToNext();
        lightIteratorLivingArea->goToNext();
        lightIteratorLivingArea->goToNext();
        if (!lightIteratorLivingArea->current->light->getLight()) {
            lightIteratorLivingArea->current->light->setLight();
        }
        lightIteratorLivingArea->reset();
    }
    if (message == "Walked into the bedroom") {
        notifyLights(false);
        lightIteratorBedrooms->reset();
        if (!lightIteratorBedrooms->current->light->getLight()) {
            lightIteratorBedrooms->current->light->setLight();
        }
    }
    if (message == "Walked into the bathroom") {
        notifyLights(false);
        lightIteratorLivingArea->reset();
        lightIteratorLivingArea->goToNext();
        if (!lightIteratorLivingArea->current->light->getLight()) {
            lightIteratorLivingArea->current->light->setLight();
        }
        lightIteratorLivingArea->reset();
    }
    if (message == "Walked into the master bedroom") {
        notifyLights(false);
        lightIteratorBedrooms->reset();
        lightIteratorBedrooms->goToNext();
        if (!lightIteratorBedrooms->current->light->getLight()) {
            lightIteratorBedrooms->current->light->setLight();
        }
        lightIteratorBedrooms->reset();
    }
}

/**
 * @brief Add a new living area light node
 * 
 * @param light 
 */
void Mediator::addLivingAreaLightNode(LightNode* light) {
    lightIteratorLivingArea->addNode(light);
}

/**
 * @brief Add a new bedrooms light node
 * 
 * @param light 
 */
void Mediator::addBedroomsLightNode(LightNode* light) {
    lightIteratorBedrooms->addNode(light);
}

/**
 * @brief Add a new living area thermo node
 * 
 * @param thermo 
 */
void Mediator::addLivingAreaThermoNode(ThermoNode* thermo) {
    thermoIteratorLivingArea->addNode(thermo);
}

/**
 * @brief Add a new bedrooms thermo node
 * 
 * @param thermo 
 */
void Mediator::addBedroomsThermoNode(ThermoNode* thermo) {
    thermoIteratorBedrooms->addNode(thermo);
}

/**
 * @brief Add a new living area door node
 * 
 * @param door 
 */
void Mediator::addLivingAreaDoorNode(DoorNode* door) {
    doorIteratorLivingArea->addNode(door);
}

/**
 * @brief Add a new bedrooms door node
 * 
 * @param door 
 */
void Mediator::addBedroomsDoorNode(DoorNode* door) {
    doorIteratorBedrooms->addNode(door);
}
