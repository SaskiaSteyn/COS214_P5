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
#include "OldDoor.h"
#include "ThermoNode.h"

using namespace std;

int main() {

    // Mediator initialization
    auto *smartHomeSystem = new Mediator();

    // Smart Light 1
    auto *smartLight1 = new LightIntegrator();
    smartLight1->addLight(new SmartLight());

    // Smart Light 2
    auto *smartLight2 = new LightIntegrator();
    smartLight2->addLight(new SmartLight());

    // Smart Light 3
    auto *smartLight3 = new LightIntegrator();
    smartLight3->addLight(new SmartLight());

    // Smart Light 4
    auto *smartLight4 = new LightIntegrator();
    smartLight4->addLight(new SmartLight());

    // Smart Light 5
    auto *smartLight5 = new LightIntegrator();
    smartLight5->addLight(new SmartLight());

    // Legacy Light 1
    auto *legacyLight1 = new LightIntegrator();
    legacyLight1->addLight(new OldLight());

    // Legacy Light 2
    auto *legacyLight2 = new LightIntegrator();
    legacyLight2->addLight(new OldLight());

    // Smart Door 1
    auto *smartDoor1 = new DoorIntegrator();
    smartDoor1->addDoor(new SmartDoor());

    // Smart Door 2
    auto *smartDoor2 = new DoorIntegrator();
    smartDoor2->addDoor(new SmartDoor());

    // Legacy Door 1
    auto *legacyDoor1 = new DoorIntegrator();
    legacyDoor1->addDoor(new OldDoor());

    // Legacy Door 2
    auto *legacyDoor2 = new DoorIntegrator();
    legacyDoor2->addDoor(new OldDoor());

    // Smart Thermo
    auto *smartThermo = new ThermoIntegrator();
    smartThermo->addThermo(new SmartThermo(21));

    // Legacy Thermo
    auto *legacyThermo = new ThermoIntegrator();
    legacyThermo->addThermo(new OldThermo(21));

    // Bedroom Lights
    smartHomeSystem->addBedroomsLightNode(new LightNode(legacyLight1));
    smartHomeSystem->addBedroomsLightNode(new LightNode(legacyLight2));
    // Bathroom Lights
    smartHomeSystem->addBedroomsLightNode(new LightNode(smartLight1));

    // Living Area Lights
    smartHomeSystem->addLivingAreaLightNode(new LightNode(smartLight2));
    smartHomeSystem->addLivingAreaLightNode(new LightNode(smartLight3));
    smartHomeSystem->addLivingAreaLightNode(new LightNode(smartLight4));
    smartHomeSystem->addLivingAreaLightNode(new LightNode(smartLight5));

    // Bedroom Doors
    smartHomeSystem->addBedroomsDoorNode(new DoorNode(legacyDoor1));
    smartHomeSystem->addBedroomsDoorNode(new DoorNode(legacyDoor2));
    // Bathroom Door
    smartHomeSystem->addBedroomsDoorNode(new DoorNode(smartDoor1));

    // Front Door
    smartHomeSystem->addLivingAreaDoorNode(new DoorNode(smartDoor2));

    // Bedroom Thermostat
    smartHomeSystem->addBedroomsThermoNode(new ThermoNode(legacyThermo));

    // Living Area Thermostat
    smartHomeSystem->addLivingAreaThermoNode(new ThermoNode(smartThermo));

     // Thermostat statistics
    float bedroomTemp = smartHomeSystem->getBedroomsThermo()->getCurrent()->thermo->getThermo();
    int livingAreaTemp = smartHomeSystem->getLivingAreaThermo()->getCurrent()->thermo->getThermo(); // Fahrenheit

    // Light statuses
    bool bedroomLight = smartHomeSystem->getBedroomsLights()->getCurrent()->light->getLight();  // true = on, false = off
    bool hallwayLight = smartHomeSystem->getLivingAreaLights()->getCurrent()->light->getLight();
    smartHomeSystem->getLivingAreaLights()->goToNext();
    bool bathroomLight = smartHomeSystem->getLivingAreaLights()->getCurrent()->light->getLight();
    smartHomeSystem->getLivingAreaLights()->goToNext();
    bool livingRoomLight = smartHomeSystem->getLivingAreaLights()->getCurrent()->light->getLight();
    smartHomeSystem->getLivingAreaLights()->goToNext();
    bool kitchenLight = smartHomeSystem->getLivingAreaLights()->getCurrent()->light->getLight();
    smartHomeSystem->getLivingAreaLights()->goToNext();
    bool outdoorLight = smartHomeSystem->getLivingAreaLights()->getCurrent()->light->getLight();

    std::cout << "Advanced House Floor Plan:\n\n";

    // Bedroom Area with hallway, bedrooms, and bathroom
    cout << "  +----------------------+        Thermostat     : " << bedroomTemp << "°F\n";
    cout << "  |                      |        Bedrooms Lights: " << (bedroomLight ? "On" : "Off") << " \n";
    cout << "  |     Master Bedroom   | \n";
    cout << "  |                      | \n";
    cout << "  |     [Door: Open]     | \n";
    cout << "  +----------------------| \n";
    cout << "            +------------+\n";
    cout << "            |   Hallway  |   Lights: " << (hallwayLight ? "On" : "Off") << "  \n";
    cout << "            +            | \n";
    cout << "  +---------+            +------------+ \n";
    cout << "  |         |            |  Bathroom  | \n";
    cout << "  | Bedroom |            |  [Open]    |  Lights: " << (bathroomLight ? "On" : "Off") << " \n";
    cout << "  | [Closed]|            |            | \n";
    cout << "  +---------+            +------------+ \n";
    cout << "            |            |           \n";
    cout << "            |            |\n";
    cout << "            |            |\n";
    cout << "            |            |\n";
    cout << "  +---------+------------+---+--------------------+      Thermostat: " << livingAreaTemp << "°F\n";
    cout << "  |                          |                    |\n";
    cout << "  |       Living Room        |      Kitchen       |\n";
    cout << "  |     Lights: " << (livingRoomLight ? "On " : "Off") << "          |     Lights: " << (kitchenLight ? "On " : "Off") << "    |\n";
    cout << "  |                          |                    |\n";
    cout << "  +-----------+   Front Door +--------------------+\n";
    cout << "              |   [Open]     |\n";
    cout << "              +--------------+\n";
    cout << endl;
    cout << "              Lights: " << (outdoorLight ? "On" : "Off") << " \n";

    return 0;
}