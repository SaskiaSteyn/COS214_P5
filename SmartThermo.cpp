/**
 * @file SmartThermo.cpp
 * @author Saskia
 * @brief Concrete Product of the template class (ThermoType)
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "SmartThermo.h"

/**
 * @brief Construct a new Smart Thermo:: Smart Thermo object
 * 
 */
SmartThermo::SmartThermo(float initialTemp) : ThermoType(initialTemp) {

}

/**
 * @brief Increase the temperature
 * 
 * @param newTemp 
 */
void SmartThermo::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        // cout << "Smart thermostat: Increased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Smart thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

/**
 * @brief Decrease the temperature
 * 
 * @param newTemp 
 */
void SmartThermo::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        // cout << "Smart thermostat: Decreased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Smart thermostat: New temperature must be lower than the current temperature." << endl;
    }
}
