/**
 * @file DoorIterator.cpp
 * @author Johan
 * @brief Concrete Iterator of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "DoorIterator.h"

/**
 * @brief Construct a new Door Iterator:: Door Iterator object
 * 
 */
DoorIterator::DoorIterator() {
    current = nullptr;
    head = nullptr;
}

/**
 * @brief Construct a new Door Iterator:: Door Iterator object
 * 
 * @param door 
 */
DoorIterator::DoorIterator(DoorNode *door) {
    this->current = door;
    this->head = door;
}

/**
 * @brief go to the next door in the room/section
 * 
 * @return DoorNode* 
 */
DoorNode *DoorIterator::goToNext() {
    this->current = this->current->next;

    return current;
}

/**
 * @brief reset the iterator to the first door in the room/section
 * 
 */
void DoorIterator::reset() {
    this->current = this->head;
}

/**
 * @brief Adds a new door to the room/section
 * 
 * @param newNode 
 */

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
