/**
 * @file OldLight.cpp
 * @author Saskia
 * @brief Concrete Product of the template class (LightType)
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "OldLight.h"

/**
 * @brief Construct a new Old Light:: Old Light object
 * 
 */
void OldLight::setLight() {
    if(lightOnOff){
        lightOnOff = false;
        // cout << "Legacy light is now OFF" << endl;
    }
    else{
        lightOnOff = true;
        // cout << "Legacy light is now ON" << endl;
    }
}
