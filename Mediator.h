#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include "LightNode.h"
#include "ThermoNode.h"
#include "DoorNode.h"

#include "LightIterator.h"
#include "ThermoIterator.h"
#include "DoorIterator.h"

class DoorNode;
class ThermoNode;
class LightNode;

#include <iostream>
using namespace std;

class Mediator {
    friend class LightNode;
    friend class DoorNode;
    friend class ThermoNode;

    protected:
        LightIterator* lightIteratorLivingArea;
        LightIterator* lightIteratorBedrooms;
        ThermoIterator* thermoIteratorBedrooms;
        ThermoIterator* thermoIteratorLivingArea;
        DoorIterator* doorIteratorLivingArea;
        DoorIterator* doorIteratorBedrooms;

    public:
        Mediator();
        void notifyLights();
        void notifyThermo();
        void notifyDoor();
        void handleReceivedMessage(string message);

        void addLivingAreaLightNode(LightNode* light);
        void addBedroomsLightNode(LightNode* light);

        void addLivingAreaThermoNode(ThermoNode* thermo);
        void addBedroomsThermoNode(ThermoNode* thermo);

        void addLivingAreaDoorNode(DoorNode* door);
        void addBedroomsDoorNode(DoorNode* door);

        LightIterator* getLivingAreaLights();
        LightIterator* getBedroomsLights();
        ThermoIterator* getLivingAreaThermo();
        ThermoIterator* getBedroomsThermo();
        DoorIterator* getLivingAreaDoors();
        DoorIterator* getBedroomsDoors();

};


#endif //CODE_MEDIATOR_H
