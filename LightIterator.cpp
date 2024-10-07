/**
 * @file LightIterator.cpp
 * @author Johan
 * @brief Iterator of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "LightIterator.h"

/**
 * @brief Construct a new Light Iterator:: Light Iterator object
 * 
 */
LightIterator::LightIterator() {
    head = nullptr;
    current = nullptr;
}

/**
 * @brief Construct a new Light Iterator:: Light Iterator object
 * 
 * @param node 
 */
LightIterator::LightIterator(LightNode *node) {
    this->current = node;
    this->head = node;
}

/**
 * @brief go to the next light in the room/section
 * 
 * @return LightNode* 
 */
LightNode *LightIterator::goToNext() {
    current = current->next;

    return current;
}

/**
 * @brief reset the iterator to the first light in the room/section
 * 
 */
void LightIterator::reset() {
    current = head;
}

/**
 * @brief adds a new light to the room/section
 * 
 * @param newNode 
 */
void LightIterator::addNode(LightNode* newNode) {
    if (head == nullptr) {
        head = newNode;
        current = newNode;
    } else {
        LightNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}