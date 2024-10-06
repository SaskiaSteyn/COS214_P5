#include "DoorNode.h"

DoorNode::DoorNode() {

}

DoorNode::DoorNode(Integrator *door) {
    this->door = door;
    this->next = nullptr;
    this->prev = nullptr;
}
