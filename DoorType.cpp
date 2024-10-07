/**
 * @file DoorType.cpp
 * @author Saskia
 * @brief Adaptee of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "DoorType.h"

/**
 * @brief Construct a new Door Type:: Door Type object
 * 
 */

DoorType::DoorType() {
    doorLocked = false;
}

/**
 * @brief toggles the door state
 * 
 */
void DoorType::toggleDoor() {

    if (doorLocked) {
        doorLocked = false;
        cout << "Door is now UNLOCKED" << endl;
    } else {
        doorLocked = true;
        cout << "Door is now LOCKED" << endl;
    }

}

/**
 * @brief returns the door state
 * 
 * @return true if the door is open 
 * @return false if the door is locked
 */

bool DoorType::getDoor() {
    return doorLocked;
}
