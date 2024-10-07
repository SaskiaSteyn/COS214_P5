#include "DoorIterator.h"

DoorIterator::DoorIterator() {}

DoorIterator::DoorIterator(DoorNode *door) {
    this->current = door;
    this->head = door;
}

DoorNode *DoorIterator::goToNext() {
    this->current = this->current->next;

    return current;
}

void DoorIterator::reset() {
    this->current = this->head;
}

void DoorIterator::addNode(DoorNode* newNode) {
    if (head == nullptr) {
        head = newNode;
    } else {
        DoorNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

DoorNode* DoorIterator::getCurrent() {return this->current;}
DoorNode* DoorIterator::getHead() {return this->head;}
