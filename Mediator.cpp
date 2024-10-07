#include "Mediator.h"

void Mediator::notifyLights() {

    cout << "Notifying all light nodes..." << endl;

}

void Mediator::notifyThermo() {

    cout << "Notifying all thermo nodes..." << endl;

}

void Mediator::notifyDoor() {

    cout << "Notifying all door nodes..." << endl;
}

void Mediator::handleReceivedMessage(string message) {

    cout << "Message has been recieved: " << message << endl;
    cout << "Notifying all smart and legacy devices to change state" << endl;

}

void Mediator::addLightNode(LightNode* light) {
//    if (lightHead == nullptr) {
//        delete lightHead;
//        lightHead = light;
//    }
//    else {
//        LightNode *current = lightHead;
//        while (current->next != nullptr) {
//            current = current->next;
//        }
//        current->next = light;
//    }

    if (lightHead == nullptr) {
        lightHead = light;  // Just assign without deleting
    } else {
        LightNode *current = lightHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = light;
    }
}

void Mediator::addThermoNode(ThermoNode* thermo) {
    if (thermoHead == nullptr) {
        //the below line causes problems
//        delete thermoHead;
        thermoHead = thermo;
    }
    else {
        ThermoNode *current = thermoHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = thermo;
    }
}

void Mediator::addDoorNode(DoorNode* door){
    if (doorHead == nullptr) {
        //the below line causes problems
        // delete doorHead;
        doorHead = door;
    }
    else {
        DoorNode *current = doorHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = door;
    }
}

void Mediator::addOutdoorLightNode(LightNode* light) {
    if (outdoorLightHead == nullptr) {
        outdoorLightHead = light;
    } else {
        LightNode *current = outdoorLightHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = light;
    }
}

void Mediator::addLivingAreaLightNode(LightNode* light) {
    if (livingAreaLightHead == nullptr) {
        livingAreaLightHead = light;
    } else {
        LightNode *current = livingAreaLightHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = light;
    }
}

void Mediator::addBedroomsLightNode(LightNode* light) {
    if (bedroomsLightHead == nullptr) {
        bedroomsLightHead = light;
    } else {
        LightNode *current = bedroomsLightHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = light;
    }
}

void Mediator::addLivingAreaThermoNode(ThermoNode* thermo) {
    if (livingAreaThermoHead == nullptr) {
        livingAreaThermoHead = thermo;
    } else {
        ThermoNode *current = livingAreaThermoHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = thermo;
    }
}

void Mediator::addBedroomsThermoNode(ThermoNode* thermo) {
    if (bedroomsThermoHead == nullptr) {
        bedroomsThermoHead = thermo;
    } else {
        ThermoNode *current = bedroomsThermoHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = thermo;
    }
}

void Mediator::addLivingAreaDoorNode(DoorNode* door) {
    if (livingAreaDoorHead == nullptr) {
        livingAreaDoorHead = door;
    } else {
        DoorNode *current = livingAreaDoorHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = door;
    }
}

void Mediator::addBedroomsDoorNode(DoorNode* door) {
    if (bedroomsDoorHead == nullptr) {
        bedroomsDoorHead = door;
    } else {
        DoorNode *current = bedroomsDoorHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = door;
    }
}
