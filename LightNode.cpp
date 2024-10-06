#include "LightNode.h"

LightNode::LightNode() {

}

LightNode::LightNode(Integrator *node) {
    this->light = node;
    this->next = nullptr;
    this->prev = nullptr;
}
