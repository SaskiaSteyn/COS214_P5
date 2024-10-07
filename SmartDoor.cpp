#include "SmartDoor.h"

void SmartDoor::toggleDoor() {
    DoorType::toggleDoor();
    if (doorLocked) {
        // cout << "Smart door: The door is now LOCKED." << endl;
    } else {
        // cout << "Smart door: The door is now UNLOCKED." << endl;
    }
}
