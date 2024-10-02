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

    public:
        Mediator() : lightHead(nullptr), thermoHead(nullptr), doorHead(nullptr) {}
        void notifyLights();
        void notifyThermo();
        void notifyDoor();
        void handleReceivedMessage(string& message);

};


#endif //CODE_MEDIATOR_H
