/**
 * @file DoorIntegrator.cpp
 * @author Saskia
 * @brief Adapter of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "DoorIntegrator.h"

/**
 * @brief Construct a new Door Integrator:: Door Integrator object
 * 
 */

DoorIntegrator::DoorIntegrator() {
    this->door = nullptr;
}

/**
 * @brief Destroy the Door Integrator:: Door Integrator object
 * 
 */
DoorIntegrator::~DoorIntegrator() {
    delete door;
}

/**
 * @brief creates a new door object
 * 
 * @param newDoor 
 */

void DoorIntegrator::addDoor(DoorType *newDoor) {
    this->door = newDoor;
}

/**
 * @brief sets the door state
 * 
 */

void DoorIntegrator::setDoor() {
    door->toggleDoor();
}

/**
 * @brief returns the door state
 * 
 * @return true if the door is open 
 * @return false if the door is closed
 */

bool DoorIntegrator::getDoor() {
    return door->getDoor();
}
