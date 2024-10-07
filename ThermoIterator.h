#ifndef CODE_THERMOITERATOR_H
#define CODE_THERMOITERATOR_H

//#include "Integrator.h"
#include "ThermoNode.h"

class ThermoNode;

class ThermoIterator{
    friend class ThermoNode;


protected:


public:
    ThermoNode* current;
    ThermoNode* head;
    ThermoIterator();
    ThermoIterator(ThermoNode *thermo);
    ThermoNode* goToNext();
    void reset();
    void addNode(ThermoNode* newNode);

    virtual void setLight() {};
    virtual void toggleDoor() {};
    virtual void increaseTemp(float newTemp) {};
    virtual void decreaseTemp(float newTemp) {};
};


#endif //CODE_THERMOITERATOR_H
