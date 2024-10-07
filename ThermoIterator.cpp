/**
 * @file ThermoIterator.cpp
 * @author Johan
 * @brief Iterator of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ThermoIterator.h"

/**
 * @brief Construct a new Thermo Iterator:: Thermo Iterator object
 * 
 */
ThermoIterator::ThermoIterator() {
    head = nullptr;
    current = nullptr;
}

/**
 * @brief Construct a new Thermo Iterator:: Thermo Iterator object
 * 
 * @param thermo 
 */
ThermoIterator::ThermoIterator(ThermoNode *thermo) {
    this->current = thermo;
    this->head = thermo;
}

/**
 * @brief go to the next thermostat in the room/section
 * 
 * @return ThermoNode* 
 */
ThermoNode *ThermoIterator::goToNext() {
    this->current = this->current->next;

    return this->current;
}

/**
 * @brief reset the iterator to the first thermostat in the room/section
 * 
 */
void ThermoIterator::reset() {
    this->current = this->head;
}

/**
 * @brief adds a new thermostat to the room/section
 * 
 * @param newNode 
 */
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
