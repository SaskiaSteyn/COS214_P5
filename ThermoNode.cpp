/**
 * @file ThermoNode.cpp
 * @author your name (you@domain.com)
 * @brief Concrete Aggregate of the Iterator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ThermoNode.h"

/**
 * @brief Construct a new Thermo Node:: Thermo Node object
 * 
 */
ThermoNode::ThermoNode() {

}

/**
 * @brief Construct a new Thermo Node:: Thermo Node object
 * 
 * @param thermo 
 */
ThermoNode::ThermoNode(Integrator *thermo) {
    this->thermo = thermo;
    this->next = nullptr;
    this->prev = nullptr;
}
