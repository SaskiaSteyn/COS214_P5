#include "LightNode.h"

LightNode::LightNode() {

}

LightNode::LightNode(Integrator *node) {
    this->light = node;
}
