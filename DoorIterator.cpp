#include "DoorIterator.h"

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
