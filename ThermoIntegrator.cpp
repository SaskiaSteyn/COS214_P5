/**
 * @file ThermoIntegrator.cpp
 * @author Saskia
 * @brief Adapter of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ThermoIntegrator.h"

/**
 * @brief Construct a new Thermo Integrator:: Thermo Integrator object
 * 
 */
ThermoIntegrator::ThermoIntegrator() {
    this->thermostat = nullptr;
}

/**
 * @brief Destroy the Thermo Integrator:: Thermo Integrator object
 * 
 */
ThermoIntegrator::~ThermoIntegrator() {
    delete thermostat;
}

/**
 * @brief Add a new thermostat object
 * 
 * @param newThermo 
 */
void ThermoIntegrator::addThermo(ThermoType *newThermo) {
    this->thermostat = newThermo;
}

/**
 * @brief sets the temperature
 * 
 * @param oldTemp 
 * @param newTemp 
 */
void ThermoIntegrator::setThermo(float oldTemp, float newTemp) {
    if(newTemp >= oldTemp){
        thermostat->increaseTemp(newTemp);
    }
    else{
        thermostat->decreaseTemp(newTemp);
    }
}

/**
 * @brief returns the temperature
 * 
 * @return float 
 */
float ThermoIntegrator::getTemp() {
    return thermostat->getTemp();
}
