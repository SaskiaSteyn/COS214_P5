#include "SmartLight.h"

void SmartLight::setLight() {
    if(lightOnOff){
        lightOnOff = false;
        cout << "Smart light is now OFF" << endl;
    }
    else{
        lightOnOff = true;
        cout << "Smart light is now ON" << endl;
    }
}
