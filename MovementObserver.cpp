/**
 * @file MovementObserver.cpp
 * @author Johan
 * @brief Concrete Observer of the observer pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MovementObserver.h"

/**
 * @brief Construct a new Movement Observer:: Movement Observer object
 * 
 */
MovementObserver::MovementObserver() {}

/**
 * @brief Construct a new Movement Observer:: Movement Observer object
 * 
 * @param newMediator 
 */
MovementObserver::MovementObserver(Mediator* newMediator) {
    this->mediator = newMediator;
}

/**
 * @brief Send message to the integrator class to change the state of the devices
 * 
 */
void MovementObserver::sendMessage() {
    if (seesMovement) {
        this->mediator->handleReceivedMessage("Turn on lights. Unlock doors. Set temperature to 18");
    }
    else {
        this->mediator->handleReceivedMessage("Turn off lights. Lock doors. Set temperature to 25");
    }
}

/**
 * @brief Get the Movement object
 * 
 * @return true if movement is detected
 * @return false if no movement is detected
 */
bool MovementObserver::getMovement() {
    return seesMovement;
}

/**
 * @brief Toggle the movement state
 * 
 */
void MovementObserver::toggleMovement() {
    seesMovement = !seesMovement;
    sendMessage();
}

/**
 * @brief Send a custom message to the mediator
 * 
 * @param message 
 */
void MovementObserver::sendCustomMessage(string message) {
    this->mediator->handleReceivedMessage(message);
}
