#include "OldDoor.h"

void OldDoor::toggleDoor() {
    DoorType::toggleDoor();

    if (doorLocked) {
        // cout << "Legacy door: The door is now LOCKED." << endl;
    } else {
        // cout << "Legacy door: The door is now UNLOCKED." << endl;
    }
}
