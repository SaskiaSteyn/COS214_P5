#include "ThermoIterator.h"

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
