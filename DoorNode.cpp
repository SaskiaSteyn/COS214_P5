/**
 * @file DoorNode.cpp
 * @author Johan
 * @brief Concrete Aggregate of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "DoorNode.h"

/**
 * @brief (default) Construct a new Door Node:: Door Node object
 * 
 */
DoorNode::DoorNode() {

}

/**
 * @brief Construct a new Door Node:: Door Node object
 * 
 * @param door 
 */
DoorNode::DoorNode(Integrator *door) {
    this->door = door;
    this->next = nullptr;
    this->prev = nullptr;
}
