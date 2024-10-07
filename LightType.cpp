/**
 * @file LightType.cpp
 * @author Saskia
 * @brief Adaptee of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "LightType.h"

/**
 * @brief Construct a new Light Type:: Light Type object
 * 
 */
LightType::LightType(){
    lightOnOff = false;
}

/**
 * @brief sets the light state
 * 
 */
void LightType::setLight() {
    if (lightOnOff) {
        lightOnOff = false;
        cout << "Light is now OFF (Base LightType)" << endl;
    } else {
        lightOnOff = true;
        cout << "Light is now ON (Base LightType)" << endl;
    }
}

/**
 * @brief gets the state of the light
 * 
 * @return true if the light is on
 * @return false if the light is off
 */
bool LightType::getLight() {
    return lightOnOff;
}
