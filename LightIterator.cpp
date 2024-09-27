#include "LightIterator.h"

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
