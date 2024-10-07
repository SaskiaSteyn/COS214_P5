/**
 * @file ThermoType.cpp
 * @author Saskia
 * @brief Adaptee of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ThermoType.h"

/**
 * @brief Construct a new Thermo Type:: Thermo Type object
 * 
 */
ThermoType::ThermoType(float initialTemp) {
    this->temp = initialTemp;

}

/**
 * @brief Increase the temperature
 * 
 * @param newTemp 
 */
void ThermoType::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        cout << "Thermostat: Temperature increased to " << temp << "°C" << endl;
    } else {
        cout << "Thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

/**
 * @brief Decrease the temperature
 * 
 * @param newTemp 
 */
void ThermoType::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        cout << "Thermostat: Temperature decreased to " << temp << "°C" << endl;
    } else {
        cout << "Thermostat: New temperature must be lower than the current temperature." << endl;
    }
}

/**
 * @brief returns the temperature
 * 
 * @return float 
 */
float ThermoType::getTemp() {
    return temp;
}
