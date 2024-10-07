#include "DoorIterator.h"

DoorIterator::DoorIterator() {
    current = nullptr;
    head = nullptr;
}

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
        current = newNode;
    } else {
        DoorNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
