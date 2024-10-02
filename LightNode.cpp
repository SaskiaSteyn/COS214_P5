#include "LightNode.h"

LightNode::LightNode() {

}

LightNode::LightNode(Mediator *node) {
    this->light = node;
}
