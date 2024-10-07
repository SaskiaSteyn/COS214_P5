/**
 * @file LightNode.cpp
 * @author Saskia
 * @brief Concrete Aggregate of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "LightNode.h"

/**
 * @brief Construct a new Light Node:: Light Node object
 * 
 */
LightNode::LightNode() {

}

/**
 * @brief Construct a new Light Node:: Light Node object
 * 
 * @param node 
 */
LightNode::LightNode(Integrator *node) {
    this->light = node;
    this->next = nullptr;
    this->prev = nullptr;
}
