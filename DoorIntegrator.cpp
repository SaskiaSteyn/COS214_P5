#include "DoorIntegrator.h"

DoorIntegrator::DoorIntegrator() {
    this->door = nullptr;
}

DoorIntegrator::~DoorIntegrator() {
    delete door;
}

void DoorIntegrator::addDoor(DoorType *newDoor) {
    this->door = newDoor;
}

void DoorIntegrator::setDoor() {
    door->toggleDoor();
}

bool DoorIntegrator::getDoor() {
    return door->getDoor();
}
