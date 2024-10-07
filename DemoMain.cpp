#include <iostream>

#include "LightIntegrator.h"
#include "DoorIntegrator.h"
#include "ThermoIntegrator.h"

#include "Mediator.h"

#include "SmartLight.h"
#include "OldLight.h"
#include "SmartDoor.h"
#include "OldDoor.h"
#include "SmartThermo.h"
#include "OldThermo.h"

#include "LightNode.h"
#include "DoorNode.h"
#include "ThermoNode.h"

#include "TimeObserver.h"
#include "MovementObserver.h"

using namespace std;

int chooseOption() {
    int option = -1;

    while (option < 1 || option > 7) {
        cout << "Choose: (1)Living Room | (2)Kitchen | (3)Bedroom | 4(Bathroom) | (5)Master Bedroom | (6)Advance Time | (7)Exit House" << endl << "Choose you option(number only): ";
        cin >> option;

        if (option < 1 || option > 7) {
            cout << "Please give a valid input (A number between 1 and 7)" << endl;
        }
    }

    return option;
}

void printMap(Mediator smartHomeSystem, TimeObserver time) {
    smartHomeSystem.thermoIteratorLivingArea->reset();
    smartHomeSystem.thermoIteratorBedrooms->reset();
    smartHomeSystem.lightIteratorLivingArea->reset();
    smartHomeSystem.lightIteratorBedrooms->reset();
    smartHomeSystem.doorIteratorLivingArea->reset();
    smartHomeSystem.doorIteratorBedrooms->reset();

    float bedroomTemp = smartHomeSystem.thermoIteratorBedrooms->head->thermo->getTemp(); // Fahrenheit
    float livingAreaTemp = smartHomeSystem.thermoIteratorLivingArea->head->thermo->getTemp(); // Fahrenheit

    // Light statuses
    bool bedroomLight = smartHomeSystem.lightIteratorBedrooms->current->light->getLight();  // true = on, false = off
    smartHomeSystem.lightIteratorBedrooms->goToNext();
    bool masterBedroomLight = smartHomeSystem.lightIteratorBedrooms->current->light->getLight();
    bool hallwayLight = smartHomeSystem.lightIteratorLivingArea->current->light->getLight();
    smartHomeSystem.lightIteratorLivingArea->goToNext();
    bool bathroomLight = smartHomeSystem.lightIteratorLivingArea->current->light->getLight();
    smartHomeSystem.lightIteratorLivingArea->goToNext();
    bool livingRoomLight = smartHomeSystem.lightIteratorLivingArea->current->light->getLight();
    smartHomeSystem.lightIteratorLivingArea->goToNext();
    bool kitchenLight = smartHomeSystem.lightIteratorLivingArea->current->light->getLight();
    smartHomeSystem.lightIteratorLivingArea->goToNext();
    bool outdoorLight = smartHomeSystem.lightIteratorLivingArea->current->light->getLight();

    // Door statuses
    bool masterDoor = smartHomeSystem.doorIteratorBedrooms->current->door->getDoor();
    cout << "Master door is " << masterDoor << endl;
    smartHomeSystem.doorIteratorBedrooms->goToNext();
    bool bedroomDoor = smartHomeSystem.doorIteratorBedrooms->current->door->getDoor();
    cout << "Bedroom door is " << bedroomDoor << endl;
    bool bathroomDoor = smartHomeSystem.doorIteratorLivingArea->current->door->getDoor();
    cout << "Bathroom door is " << bathroomDoor << endl;
    smartHomeSystem.doorIteratorLivingArea->goToNext();
    bool frontDoor = smartHomeSystem.doorIteratorLivingArea->current->door->getDoor();
    cout << "Front door is " << frontDoor<< endl;

    cout << "\n\n\nUser's House:\n";
    cout << "Time of Day: ";
    if (time.getTime() == 0) {
        cout << "Morning\n\n";
    }
    else if (time.getTime() == 1) {
        cout << "Afternoon\n\n";
    }
    else if (time.getTime() == 2) {
        cout << "Evening\n\n";
    }
    else if (time.getTime() == 3) {
        cout << "Night\n\n";
    }

    // Bedroom Area with hallway, bedrooms, and bathroom
    cout << "  +---------------------------+        Thermostat          : " << bedroomTemp << "°C\n";
    cout << "  |                           |\n";
    cout << "  |     Master Bedroom        | \n";
    cout << "  |     Lights: " << (masterBedroomLight ? "On" : "Off") << "           |\n";
    cout << "  |     [" << (masterDoor ? "Open" : "Closed") << "]              | \n";
    cout << "  +---------------------------| \n";
    cout << "                +-------------+\n";
    cout << "                | Hallway     |     \n";
    cout << "                + Lights: " << (hallwayLight ? "On" : "Off") << " | \n";
    cout << "  +-------------+             +--------------+ \n";
    cout << "  | Bedroom     |             |  Bathroom    | \n";
    cout << "  | Lights: " << (bedroomLight ? "On" : "Off") << " |             |  Lights: " << (bathroomLight ? "On" : "Off") << " |   \n";
    cout << "  | [" << (bedroomDoor ? "Open" : "Closed") << "]    |             |  [" << (bathroomDoor ? "Open" : "Closed") << "]    | \n";
    cout << "  +-------------+             +--------------+ \n";
    cout << "                |             |           \n";
    cout << "                |             |\n";
    cout << "                |             |\n";
    cout << "                |             |\n";
    cout << "  +-------------+-------------+--------------------+      Thermostat: " << livingAreaTemp << "°C\n";
    cout << "  |                           |                    |\n";
    cout << "  |       Living Room         |      Kitchen       |\n";
    cout << "  |       Lights: " << (livingRoomLight ? "On " : "Off") << "         |     Lights: " << (kitchenLight ? "On " : "Off") << "    |\n";
    cout << "  |                           |                    |\n";
    cout << "  +-------------+ Front Door  +--------------------+\n";
    cout << "                | [" << (frontDoor ? "Open" : "Closed") << "]    |\n";
    cout << "                +-------------+\n";
    cout << endl;
    cout << "              Lights: " << (outdoorLight ? "On" : "Off") << " \n";

    smartHomeSystem.thermoIteratorLivingArea->reset();
    smartHomeSystem.thermoIteratorBedrooms->reset();
    smartHomeSystem.lightIteratorLivingArea->reset();
    smartHomeSystem.lightIteratorBedrooms->reset();
    smartHomeSystem.doorIteratorLivingArea->reset();
    smartHomeSystem.doorIteratorBedrooms->reset();
}

int main() {

    Mediator smartHomeSystem;

    auto *smartLight1 = new LightIntegrator();
    smartLight1->addLight(new SmartLight());

    auto *smartLight2 = new LightIntegrator();
    smartLight2->addLight(new SmartLight());

    auto *smartLight3 = new LightIntegrator();
    smartLight3->addLight(new SmartLight());

    auto *smartLight4 = new LightIntegrator();
    smartLight4->addLight(new SmartLight());

    auto *smartLight5 = new LightIntegrator();
    smartLight5->addLight(new SmartLight());

    auto *smartLight6 = new LightIntegrator();
    smartLight6->addLight(new SmartLight());

    auto *legacyLight1 = new LightIntegrator();
    legacyLight1->addLight(new OldLight());

    auto *legacyLight2 = new LightIntegrator();
    legacyLight2->addLight(new OldLight());

    auto *smartDoor1 = new DoorIntegrator();
    smartDoor1->addDoor(new SmartDoor());

    auto *smartDoor2 = new DoorIntegrator();
    smartDoor2->addDoor(new SmartDoor());

    auto *legacyDoor1 = new DoorIntegrator();
    legacyDoor1->addDoor(new OldDoor());

    auto *legacyDoor2 = new DoorIntegrator();
    legacyDoor2->addDoor(new OldDoor());

    auto *smartThermo = new ThermoIntegrator();
    smartThermo->addThermo(new SmartThermo(21));

    auto *legacyThermo = new ThermoIntegrator();
    legacyThermo->addThermo(new OldThermo(21));

    // Bedroom Lights
    smartHomeSystem.addBedroomsLightNode(new LightNode(legacyLight1));
    smartHomeSystem.addBedroomsLightNode(new LightNode(legacyLight2));
    // Bathroom Lights
    smartHomeSystem.addBedroomsLightNode(new LightNode(smartLight1));

    // Living Area Lights
    smartHomeSystem.addLivingAreaLightNode(new LightNode(smartLight2));
    smartHomeSystem.addLivingAreaLightNode(new LightNode(smartLight3));
    smartHomeSystem.addLivingAreaLightNode(new LightNode(smartLight4));
    smartHomeSystem.addLivingAreaLightNode(new LightNode(smartLight5));
    smartHomeSystem.addLivingAreaLightNode(new LightNode(smartLight6));

    // Bedroom Doors
    smartHomeSystem.addBedroomsDoorNode(new DoorNode(legacyDoor1));
    smartHomeSystem.addBedroomsDoorNode(new DoorNode(legacyDoor2));
    // Bathroom Door
    smartHomeSystem.addLivingAreaDoorNode(new DoorNode(smartDoor1));

    // Front Door
    smartHomeSystem.addLivingAreaDoorNode(new DoorNode(smartDoor2));

    // Bedroom Thermostat
    smartHomeSystem.addBedroomsThermoNode(new ThermoNode(legacyThermo));

    // Living Area Thermostat
    smartHomeSystem.addLivingAreaThermoNode(new ThermoNode(smartThermo));

    // Observers
    auto *time = new TimeObserver(&smartHomeSystem);
    auto *movement = new MovementObserver(&smartHomeSystem);

    printMap(smartHomeSystem, *time);

    string firstInput;

    cout << endl << endl << "The user is currently outside" << endl;

    while (firstInput != "y" && firstInput != "Y" && firstInput != "Yes" && firstInput != "yes" && firstInput != "n" && firstInput != "N" && firstInput != "No" && firstInput != "no") {
        cout << "Go Inside? (y/n): ";
        cin >> firstInput;

        if (firstInput != "y" && firstInput != "Y" && firstInput != "Yes" && firstInput != "yes" && firstInput != "n" && firstInput != "N" && firstInput != "No" && firstInput != "no") {
            cout << "Please give a valid input" << endl;
        }
    }


    if (firstInput == "n" || firstInput == "N" || firstInput == "No" || firstInput == "no") {
        cout << "Thank you for playing our demo. See you next time!" << endl;
        return 0;
    }

    int option = -1;

    while (option != 7) {

        option = chooseOption();

        if (option == 1) {
            if (!movement->getMovement() && time->getTime() == 3) {
                movement->toggleMovement();
            }
            else if (time->getTime() == 2) {
                movement->sendCustomMessage("Walked into the living room");
            }

            cout << "Moved to Living Room" << endl;
        }
        else if (option == 2) {
            if (!movement->getMovement() && time->getTime() == 3) {
                    movement->toggleMovement();
            }
            else if (time->getTime() == 2) {
                movement->sendCustomMessage("Walked into the kitchen");
            }

            cout << "Moved to Kitchen" << endl;
        }
        else if (option == 3) {
            if (!movement->getMovement() && time->getTime() == 3) {
                movement->toggleMovement();
            }
            else if (time->getTime() == 2) {
                movement->sendCustomMessage("Walked into the bedroom");
            }

            cout << "Moved to Bedroom" << endl;
        }
        else if (option == 4) {
            if (!movement->getMovement() && time->getTime() == 3) {
                movement->toggleMovement();
            }
            else if (time->getTime() == 2) {
                movement->sendCustomMessage("Walked into the bathroom");
            }

            cout << "Moved to Bathroom" << endl;
        }
        else if (option == 5) {
            if (!movement->getMovement() && time->getTime() == 3) {
                movement->toggleMovement();
            }
            else if (time->getTime() == 2) {
                movement->sendCustomMessage("Walked into the master bedroom");
            }

            cout << "Moved to Master Bedroom" << endl;
        }
        else if (option == 6) {
            time->advanceTime();
        }
        else if (option == 7) {
            cout << "Thank you for playing our demo. See you next time!" << endl;
            return 0;
        }

        // switch (option) {
        //     case 1: {
        //         if (!movement->getMovement()) {
        //             movement->toggleMovement();
        //         }
        //
        //         cout << "Moved to Living Room" << endl;
        //     }
        //
        //     case 2: {
        //         if (!movement->getMovement()) {
        //             movement->toggleMovement();
        //         }
        //
        //         cout << "Moved to Kitchen" << endl;
        //     }
        //
        //     case 3: {
        //         if (!movement->getMovement()) {
        //             movement->toggleMovement();
        //         }
        //
        //         cout << "Moved to Bedroom" << endl;
        //     }
        //
        //     case 4: {
        //         if (!movement->getMovement()) {
        //             movement->toggleMovement();
        //         }
        //
        //         cout << "Moved to Bathroom" << endl;
        //     }
        //
        //     case 5: {
        //         if (!movement->getMovement()) {
        //             movement->toggleMovement();
        //         }
        //
        //         cout << "Moved to Master Bedroom" << endl;
        //     }
        //
        //     case 6: {
        //         time->advanceTime();
        //     }
        //
        //     case 7: {
        //         cout << "Thank you for playing our demo. See you next time!" << endl;
        //         return 0;
        //     }
        //
        //     default: {
        //
        //     }

        printMap(smartHomeSystem, *time);
    }
}

