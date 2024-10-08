#ifndef CODE_INTEGRATOR_H
#define CODE_INTEGRATOR_H

#include "Mediator.h"
#include <string>

using namespace std;

class Integrator {

    public:
        void receiveMessage(string message);

        virtual bool getDoor() = 0;
        virtual bool getLight() = 0;
        virtual float getTemp() = 0;

        virtual void setDoor() {};
        virtual void setLight() {};
        virtual void toggleDoor() = 0;
        virtual void increaseTemp(float newTemp) = 0;
        virtual void decreaseTemp(float newTemp) = 0;
};


#endif //CODE_INTEGRATOR_H
