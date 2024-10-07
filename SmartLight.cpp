/**
 * @file SmartLight.cpp
 * @author Saskia
 * @brief Concrete Product of the template class (LightType)
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "SmartLight.h"

/**
 * @brief Construct a new Smart Light:: Smart Light object
 * 
 */
void SmartLight::setLight() {
    if(lightOnOff){
        lightOnOff = false;
        // cout << "Smart light is now OFF" << endl;
    }
    else{
        lightOnOff = true;
        // cout << "Smart light is now ON" << endl;
    }
}
