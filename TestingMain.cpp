#include "Mediator.h"
#include "LightIntegrator.h"
#include "DoorIntegrator.h"
#include "ThermoIntegrator.h"
#include "SmartLight.h"
#include "OldLight.h"
#include "SmartThermo.h"
#include "OldThermo.h"
#include "SmartDoor.h"
#include "OldDoor.h"
#include "MorningEvent.h"
#include "AfternoonEvent.h"
#include "EveningEvent.h"
#include "NightEvent.h"

#include <iostream>
#include <memory> // For std::unique_ptr
using namespace std;

// Function prototypes
void testLightIntegration();
void testThermoIntegration();
void testThermoTypeMethods(); // New prototype for ThermoType tests
void testDoorIntegration();
void testEventMessages();
void testMediatorAddNodes();
void testMediatorNotifyMethods();
void testNodeConstructors(); // New prototype for Node constructor tests
void testLightNodeConstructor(); // New prototype for LightNode constructor test

int main() {
    testLightIntegration();
    testThermoIntegration();
    testThermoTypeMethods(); // New test for ThermoType methods
    testDoorIntegration();
    testEventMessages();
    testMediatorAddNodes();
    testMediatorNotifyMethods(); // New test for notify methods
    testNodeConstructors(); // New test for Node constructors
    testLightNodeConstructor(); // Test for LightNode constructor

    return 0;
}

void testLightIntegration() {
    cout << "————————————————————————— Testing Light Integration —————————————————————————" << endl;

    // Create light types
    unique_ptr<LightType> smartLight = make_unique<SmartLight>();
    unique_ptr<LightType> oldLight = make_unique<OldLight>();

    // Create light integrators
    LightIntegrator smartLightIntegrator;
    smartLightIntegrator.addLight(smartLight.release()); // Transfer ownership
    LightIntegrator legacyLightIntegrator;
    legacyLightIntegrator.addLight(oldLight.release()); // Transfer ownership

    // Test initial state
    cout << "Initial Smart light status: " << smartLightIntegrator.getLight() << endl; // Expecting false
    cout << "Initial Legacy light status: " << legacyLightIntegrator.getLight() << endl; // Expecting false

    // Test toggling the light state
    smartLightIntegrator.setLight(); // Turn ON
    cout << "Smart light status (after setting ON): " << smartLightIntegrator.getLight() << endl; // Expecting true

    legacyLightIntegrator.setLight(); // Turn ON
    cout << "Legacy light status (after setting ON): " << legacyLightIntegrator.getLight() << endl; // Expecting true

    // Toggle lights again
    smartLightIntegrator.setLight(); // Turn OFF
    cout << "Smart light status (after setting OFF): " << smartLightIntegrator.getLight() << endl; // Expecting false

    legacyLightIntegrator.setLight(); // Turn OFF
    cout << "Legacy light status (after setting OFF): " << legacyLightIntegrator.getLight() << endl; // Expecting false

    // Additional test to ensure toggling back ON works correctly
    smartLightIntegrator.setLight(); // Turn ON
    cout << "Smart light status (after toggling ON again): " << smartLightIntegrator.getLight() << endl; // Expecting true

    legacyLightIntegrator.setLight(); // Turn ON
    cout << "Legacy light status (after toggling ON again): " << legacyLightIntegrator.getLight() << endl; // Expecting true

    // Final toggle to OFF again
    smartLightIntegrator.setLight(); // Turn OFF
    legacyLightIntegrator.setLight(); // Turn OFF

    // Output final statuses
    cout << "Final Smart light status: " << smartLightIntegrator.getLight() << endl; // Expecting false
    cout << "Final Legacy light status: " << legacyLightIntegrator.getLight() << endl; // Expecting false
}

void testThermoIntegration() {
    cout << "————————————————————————— Testing Thermostat Integration —————————————————————————" << endl;

    // Create thermostat types
    unique_ptr<ThermoType> smartThermo = make_unique<SmartThermo>(22.5);
    unique_ptr<ThermoType> oldThermo = make_unique<OldThermo>(19.0);

    // Create thermostat integrators
    ThermoIntegrator smartThermoIntegrator;
    smartThermoIntegrator.addThermo(smartThermo.release()); // Transfer ownership
    ThermoIntegrator legacyThermoIntegrator;
    legacyThermoIntegrator.addThermo(oldThermo.release()); // Transfer ownership

    // Test temperature changes
    cout << "Initial smart thermostat temperature: " << smartThermoIntegrator.getThermo() << "°C" << endl;
    smartThermoIntegrator.setThermo(22.5, 25.0); // Increase temperature
    smartThermoIntegrator.setThermo(25.0, 18.0); // Decrease temperature

    cout << "Initial legacy thermostat temperature: " << legacyThermoIntegrator.getThermo() << "°C" << endl;
    legacyThermoIntegrator.setThermo(19.0, 30.0); // Increase temperature
    legacyThermoIntegrator.setThermo(30.0, 15.0); // Decrease temperature
}

void testThermoTypeMethods() {
    cout << "————————————————————————— Testing ThermoType Methods —————————————————————————" << endl;

    // Create a ThermoType instance
    unique_ptr<ThermoType> thermoType = make_unique<ThermoType>(20.0);

    // Test initial temperature
    cout << "Initial temperature: " << thermoType->getTemp() << "°C" << endl; // Expecting 20.0

    // Test increasing temperature
    thermoType->increaseTemp(25.0); // Valid increase
    cout << "Temperature after increase: " << thermoType->getTemp() << "°C" << endl; // Expecting 25.0

    // Test invalid increase (should not change)
    thermoType->increaseTemp(22.0); // Invalid, should not change
    cout << "Temperature after invalid increase: " << thermoType->getTemp() << "°C" << endl; // Expecting 25.0

    // Test decreasing temperature
    thermoType->decreaseTemp(18.0); // Valid decrease
    cout << "Temperature after decrease: " << thermoType->getTemp() << "°C" << endl; // Expecting 18.0

    // Test invalid decrease (should not change)
    thermoType->decreaseTemp(20.0); // Invalid, should not change
    cout << "Temperature after invalid decrease: " << thermoType->getTemp() << "°C" << endl; // Expecting 18.0
}

void testDoorIntegration() {
    cout << "————————————————————————— Testing Door Integration —————————————————————————" << endl;

    // Create door types
    unique_ptr<DoorType> smartDoor = make_unique<SmartDoor>();
    unique_ptr<DoorType> oldDoor = make_unique<OldDoor>();

    // Create door integrators
    DoorIntegrator smartDoorIntegrator;
    smartDoorIntegrator.addDoor(smartDoor.release()); // Transfer ownership
    DoorIntegrator legacyDoorIntegrator;
    legacyDoorIntegrator.addDoor(oldDoor.release()); // Transfer ownership

    // Test toggling the door state
    cout << "Toggling Smart Door:" << endl;
    smartDoorIntegrator.setDoor(); // Locking
    smartDoorIntegrator.setDoor(); // Unlocking

    cout << "Toggling Legacy Door:" << endl;
    legacyDoorIntegrator.setDoor(); // Locking
    legacyDoorIntegrator.setDoor(); // Unlocking
}

void testEventMessages() {
    cout << "————————————————————————— Testing Event Messages —————————————————————————" << endl;

    Mediator mediator;

    MorningEvent morningEvent;
    AfternoonEvent afternoonEvent;
    EveningEvent eveningEvent;
    NightEvent nightEvent;

    // Send event messages
    string morningMessage = morningEvent.sendMessage();
    mediator.handleReceivedMessage(morningMessage); // Testing MorningEvent

    string afternoonMessage = afternoonEvent.sendMessage();
    mediator.handleReceivedMessage(afternoonMessage); // Testing AfternoonEvent

    string eveningMessage = eveningEvent.sendMessage();
    mediator.handleReceivedMessage(eveningMessage); // Testing EveningEvent

    string nightMessage = nightEvent.sendMessage();
    mediator.handleReceivedMessage(nightMessage); // Testing NightEvent
}

void testMediatorAddNodes() {
    cout << "————————————————————————— Testing Mediator Node Addition —————————————————————————" << endl;

    Mediator mediator;

    // Create thermo and door nodes
    unique_ptr<ThermoNode> thermoNode1 = make_unique<ThermoNode>();
    unique_ptr<ThermoNode> thermoNode2 = make_unique<ThermoNode>();
    unique_ptr<DoorNode> doorNode1 = make_unique<DoorNode>();
    unique_ptr<DoorNode> doorNode2 = make_unique<DoorNode>();

    // Add thermo nodes to the mediator
    mediator.addThermoNode(thermoNode1.release()); // Transfer ownership
    mediator.addThermoNode(thermoNode2.release()); // Transfer ownership

    // Add door nodes to the mediator
    mediator.addDoorNode(doorNode1.release()); // Transfer ownership
    mediator.addDoorNode(doorNode2.release()); // Transfer ownership

    // Since the output is handled in the Mediator class, we'll just confirm that nodes have been added.
    cout << "Thermo and door nodes added successfully." << endl;
}

void testMediatorNotifyMethods() {
    cout << "————————————————————————— Testing Mediator Notify Methods —————————————————————————" << endl;

    Mediator mediator;

    // Create light, thermo, and door nodes
    unique_ptr<LightNode> lightNode1 = make_unique<LightNode>();
    unique_ptr<LightNode> lightNode2 = make_unique<LightNode>();
    unique_ptr<ThermoNode> thermoNode1 = make_unique<ThermoNode>();
    unique_ptr<ThermoNode> thermoNode2 = make_unique<ThermoNode>();
    unique_ptr<DoorNode> doorNode1 = make_unique<DoorNode>();
    unique_ptr<DoorNode> doorNode2 = make_unique<DoorNode>();

    // Add nodes to the mediator
    mediator.addLightNode(lightNode1.release()); // Transfer ownership
    mediator.addLightNode(lightNode2.release()); // Transfer ownership
    mediator.addThermoNode(thermoNode1.release()); // Transfer ownership
    mediator.addThermoNode(thermoNode2.release()); // Transfer ownership
    mediator.addDoorNode(doorNode1.release()); // Transfer ownership
    mediator.addDoorNode(doorNode2.release()); // Transfer ownership

    // Call notify methods
    mediator.notifyLights(); // Should notify all light nodes
    mediator.notifyThermo(); // Should notify all thermostat nodes
    mediator.notifyDoor(); // Should notify all door nodes
}

void testNodeConstructors() {
    cout << "————————————————————————— Testing Node Constructors —————————————————————————" << endl;

    // Testing LightNode constructor
    LightNode lightNode;
    cout << "LightNode constructed successfully." << endl;

    // Testing ThermoNode constructor
    Integrator *thermoIntegrator = new ThermoIntegrator();
    ThermoNode thermoNode(thermoIntegrator);
    cout << "ThermoNode constructed successfully." << endl;

    // Testing DoorNode constructor
    Integrator *doorIntegrator = new DoorIntegrator();
    DoorNode doorNode(doorIntegrator);
    cout << "DoorNode constructed successfully." << endl;

    // Cleanup
    delete thermoIntegrator;
    delete doorIntegrator;
}

// New test function for LightNode constructor
void testLightNodeConstructor() {
    cout << "————————————————————————— Testing LightNode Constructor —————————————————————————" << endl;

    // Testing LightNode constructor
    Integrator *lightIntegrator = new LightIntegrator();
    LightNode lightNode(lightIntegrator);
    cout << "LightNode constructed successfully." << endl;

    // Cleanup
    delete lightIntegrator;
}
