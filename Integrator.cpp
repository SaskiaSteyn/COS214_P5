/**
 * @file Integrator.cpp
 * @author Saskia
 * @brief Target of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Integrator.h"
#include <string>

/**
 * @brief Receive a message from the macro event
 * 
 * @param message 
 */

void Integrator::receiveMessage(string message) {
    cout << "Instructions received: " << message << endl;
}
