#include "DoorType.h"

DoorType::DoorType() {
    doorLocked = false;
}

void DoorType::toggleDoor() {

    if (doorLocked) {
        doorLocked = false;
        cout << "Door is now UNLOCKED" << endl;
    } else {
        doorLocked = true;
        cout << "Door is now LOCKED" << endl;
    }

}

bool DoorType::getDoor() {
    return doorLocked;
}
