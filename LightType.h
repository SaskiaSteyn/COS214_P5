#ifndef CODE_LIGHTTYPE_H
#define CODE_LIGHTTYPE_H

#include <iostream>

using namespace std;

class LightType {
    protected:
        bool lightOnOff;

    public:
        LightType();
        virtual void setLight();
        bool getLight();

        float getTemp() {return 0.0;};
        bool getDoor() {return false;};

        virtual void toggleDoor() {};
        virtual void increaseTemp(float newTemp) {};
        virtual void decreaseTemp(float newTemp) {};

};


#endif //CODE_LIGHTTYPE_H
