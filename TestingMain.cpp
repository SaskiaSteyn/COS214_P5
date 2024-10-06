#include "Mediator.h"
#include "SmartLight.h"
#include "OldLight.h"
#include "SmartThermo.h"
#include "OldThermo.h"
#include "SmartDoor.h"
#include "OldDoor.h"
#include "LightIntegrator.h"

#include <iostream>
using namespace std;

void testingLight(){
    cout << "————————————————————————————————————————Testing lights————————————————————————————————————————" << endl;
    LightType* smartLight = new SmartLight();
    LightType* oldLight = new OldLight();

    LightIntegrator *smartLightIntegrator = new LightIntegrator();
    smartLightIntegrator->addLight(smartLight);

    LightIntegrator *legacyLightIntegrator = new LightIntegrator();
    legacyLightIntegrator->addLight(oldLight);

    // Test toggling the light state for SmartLight
    smartLight->setLight();
    cout << "Smart light status: " << smartLight->getLight() << endl;

    // Test toggling the light state for OldLight
    oldLight->setLight();
    cout << "Legacy light status: " << oldLight->getLight() << endl;

    smartLight->setLight();
    oldLight->setLight();

    delete smartLightIntegrator;
    delete legacyLightIntegrator;
}

void testingThermostat(){
    cout << "————————————————————————————————————————Testing Thermostat————————————————————————————————————————" << endl;
    ThermoType* smartThermo = new SmartThermo(22.5);
    ThermoType* oldThermo = new OldThermo(19.0);

    // Test increasing and decreasing temperature on SmartThermo
    cout << "Initial smart thermostat temperature: " << smartThermo->getTemp() << "°C" << endl;
    smartThermo->increaseTemp(25.0);
    smartThermo->decreaseTemp(18.0);

    // Test increasing and decreasing temperature on OldThermo
    cout << "Initial legacy thermostat temperature: " << oldThermo->getTemp() << "°C" << endl;
    oldThermo->increaseTemp(30.0);
    oldThermo->decreaseTemp(15.0);

    delete smartThermo;
    delete oldThermo;
}

void testingDoors(){
    cout << "————————————————————————————————————————Testing Doors————————————————————————————————————————" << endl;
    DoorType* smartDoor = new SmartDoor();
    DoorType* oldDoor = new OldDoor();

    // Test toggling the door state for SmartDoor
    cout << "Smart door:" << endl;
    smartDoor->toggleDoor();
    smartDoor->toggleDoor();

    // Test toggling the door state for OldDoor
    cout << "Legacy door:" << endl;
    oldDoor->toggleDoor();
    oldDoor->toggleDoor();

    // Clean up dynamic memory
    delete smartDoor;
    delete oldDoor;
}



int main() {
    testingLight();
    // testingThermostat();
    // testingDoors();

    return 0;
}


