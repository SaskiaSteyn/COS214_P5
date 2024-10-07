/**
 * @file MorningEvent.cpp
 * @author Johan
 * @brief Concrete Colleague of the mediator pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MorningEvent.h"

/**
 * @brief Sends a message to the mediator to update the state of the devices
 * 
 * @return string 
 */
string MorningEvent::sendMessage() {
    return "Turn off lights. Unlock doors. Set temperature to 22";
}
