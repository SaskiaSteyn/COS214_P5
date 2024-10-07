/**
 * @file TimeObserver.cpp
 * @author Johan
 * @brief Concrete Observer of the observer pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "TimeObserver.h"

/**
 * @brief Construct a new Time Observer:: Time Observer object
 * 
 */
TimeObserver::TimeObserver() {
    time = 0;
    this->mediator = nullptr;
}

/**
 * @brief Construct a new Time Observer:: Time Observer object
 * 
 * @param newMediator 
 */
TimeObserver::TimeObserver(Mediator* newMediator) {
    time = 0;
    this->mediator = newMediator;
    sendMessage();
}

/**
 * @brief Get the Time object
 * 
 * @return int 
 */
int TimeObserver::getTime() {
    return this->time;
}

/**
 * @brief Advance the time of the day
 * 
 */
void TimeObserver::advanceTime() {
    time++;
    if (this->time > 3) {
        time = 0;
    }

    sendMessage();
}

/**
 * @brief Send message to the integrator class to change the state of the devices
 * 
 */
void TimeObserver::sendMessage() {
    if (time == 0) {
        this->mediator->handleReceivedMessage("Time changed to morning");
    }
    else if (time == 1) {
        this->mediator->handleReceivedMessage("Time changed to afternoon");
    }
    else if (time == 2) {
        this->mediator->handleReceivedMessage("Time changed to evening");
    }
    else {
        this->mediator->handleReceivedMessage("Time changed to night");
    }
}