#include "LightType.h"

LightType::LightType(){
    lightOnOff = false;
}

void LightType::setLight() {
    if (lightOnOff) {
        lightOnOff = false;
        cout << "Light is now OFF (Base LightType)" << endl;
    } else {
        lightOnOff = true;
        cout << "Light is now ON (Base LightType)" << endl;
    }
}

bool LightType::getLight() {
    return lightOnOff;
}
