#ifndef CODE_MEDIATOR_H
#define CODE_MEDIATOR_H

#include "LightNode.h"
#include "ThermoNode.h"
#include "DoorNode.h"

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
        LightNode* lightHead;
        ThermoNode* thermoHead;
        DoorNode* doorHead;

        LightNode* outdoorLightHead;
        LightNode* livingAreaLightHead;
        LightNode* bedroomsLightHead;

        ThermoNode* livingAreaThermoHead;
        ThermoNode* bedroomsThermoHead;

        DoorNode* livingAreaDoorHead;
        DoorNode* bedroomsDoorHead;

    public:
        Mediator() : lightHead(nullptr), thermoHead(nullptr), doorHead(nullptr) {}
        void notifyLights();
        void notifyThermo();
        void notifyDoor();
        void handleReceivedMessage(string message);

        void addLightNode(LightNode* light);
        void addThermoNode(ThermoNode* thermo);
        void addDoorNode(DoorNode* door);

        void addOutdoorLightNode(LightNode* light);
        void addLivingAreaLightNode(LightNode* light);
        void addBedroomsLightNode(LightNode* light);

        void addLivingAreaThermoNode(ThermoNode* thermo);
        void addBedroomsThermoNode(ThermoNode* thermo);

        void addLivingAreaDoorNode(DoorNode* door);
        void addBedroomsDoorNode(DoorNode* door);

};


#endif //CODE_MEDIATOR_H
