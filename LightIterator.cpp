#include "LightIterator.h"

LightIterator::LightIterator() {}

LightIterator::LightIterator(LightNode *node) {
    this->current = node;
    this->head = node;
}

LightNode *LightIterator::goToNext() {
    current = current->next;

    return current;
}

void LightIterator::reset() {
    current = head;
}

void LightIterator::addNode(LightNode* newNode) {
    if (head == nullptr) {
        head = newNode;
    } else {
        LightNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

LightNode* LightIterator::getCurrent() {return this->current;}
LightNode* LightIterator::getHead() {return this->head;}
