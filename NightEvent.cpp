/**
 * @file NightEvent.cpp
 * @author Johan
 * @brief Concrete Colleague of the mediator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "NightEvent.h"

/**
 * @brief Sends a message to the macro event to update the state of the devices
 * 
 * @return string 
 */
string NightEvent::sendMessage() {
    return "Turn off lights. Lock doors. Set temperature to 18";
}