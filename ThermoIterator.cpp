#include "ThermoIterator.h"

ThermoIterator::ThermoIterator() {
    head = nullptr;
    current = nullptr;
}

ThermoIterator::ThermoIterator(ThermoNode *thermo) {
    this->current = thermo;
    this->head = thermo;
}

ThermoNode *ThermoIterator::goToNext() {
    this->current = this->current->next;

    return this->current;
}

void ThermoIterator::reset() {
    this->current = this->head;
}


void ThermoIterator::addNode(ThermoNode* newNode) {
    if (head == nullptr) {
        head = newNode;
        current = newNode;
    } else {
        ThermoNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
