/**
 * @file OldDoor.cpp
 * @author Saskia
 * @brief Concrete Product of the template class (DoorType)
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "OldDoor.h"

/**
 * @brief Toggle the door state
 * 
 */
void OldDoor::toggleDoor() {
    DoorType::toggleDoor();

    if (doorLocked) {
        // cout << "Legacy door: The door is now LOCKED." << endl;
    } else {
        // cout << "Legacy door: The door is now UNLOCKED." << endl;
    }
}
