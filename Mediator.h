#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include <cmath>

#include "LightNode.h"
#include "ThermoNode.h"
#include "DoorNode.h"

#include "LightIterator.h"
#include "ThermoIterator.h"
#include "DoorIterator.h"

class DoorNode;
class ThermoNode;
class LightNode;

class LightIterator;
class ThermoIterator;
class DoorIterator;

#include <iostream>
using namespace std;

class Mediator {
    friend class LightNode;
    friend class DoorNode;
    friend class ThermoNode;
    friend class LightIterator;
    friend class ThermoIterator;
    friend class DoorIterator;

    protected:
        // LightNode* outdoorLightHead;
        // LightNode* livingAreaLightHead;
        // LightNode* bedroomsLightHead;
        //
        // ThermoNode* livingAreaThermoHead;
        // ThermoNode* bedroomsThermoHead;
        //
        // DoorNode* livingAreaDoorHead;
        // DoorNode* bedroomsDoorHead;

    public:
        LightIterator* lightIteratorLivingArea;
        LightIterator* lightIteratorBedrooms;
        ThermoIterator* thermoIteratorBedrooms;
        ThermoIterator* thermoIteratorLivingArea;
        DoorIterator* doorIteratorLivingArea;
        DoorIterator* doorIteratorBedrooms;

        Mediator();
        void notifyLights(bool state);
        void notifyThermo(float temp);
        void notifyDoor(bool state);
        void handleReceivedMessage(string message);

        void addLivingAreaLightNode(LightNode* light);
        void addBedroomsLightNode(LightNode* light);

        void addLivingAreaThermoNode(ThermoNode* thermo);
        void addBedroomsThermoNode(ThermoNode* thermo);

        void addLivingAreaDoorNode(DoorNode* door);
        void addBedroomsDoorNode(DoorNode* door);

};


#endif //CODE_MEDIATOR_H
