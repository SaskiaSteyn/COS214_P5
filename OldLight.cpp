#include "OldLight.h"


void OldLight::setLight() {
    if(lightOnOff){
        lightOnOff = false;
        cout << "Legacy light is now OFF" << endl;
    }
    else{
        lightOnOff = true;
        cout << "Legacy light is now ON" << endl;
    }
}
