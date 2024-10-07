/**
 * @file OldThermo.cpp
 * @author Saskia
 * @brief Concrete Product of the template class (ThermoType)
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "OldThermo.h"

/**
 * @brief Construct a new Old Thermo:: Old Thermo object
 * 
 */
OldThermo::OldThermo(float initialTemp) : ThermoType(initialTemp) {

}

/**
 * @brief Increase the temperature
 * 
 * @param newTemp 
 */
void OldThermo::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        // cout << "Legacy thermostat: Increased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Legacy thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

/**
 * @brief Decrease the temperature
 * 
 * @param newTemp 
 */
void OldThermo::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        // cout << "Legacy thermostat: Decreased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Legacy thermostat: New temperature must be lower than the current temperature." << endl;
    }
}
