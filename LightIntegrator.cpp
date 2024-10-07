/**
 * @file LightIntegrator.cpp
 * @author Saskia
 * @brief Adapter of the Adapter pattern
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "LightIntegrator.h"

/**
 * @brief Construct a new Light Integrator:: Light Integrator object
 * 
 */
LightIntegrator::LightIntegrator() {
    this->light = nullptr;
}

/**
 * @brief Destroy the Light Integrator:: Light Integrator object
 * 
 */
LightIntegrator::~LightIntegrator() {
    delete light;
}

/**
 * @brief Add a new light object
 * 
 * @param newLight 
 */
void LightIntegrator::addLight(LightType* newLight) {
    this->light = newLight;
}

/**
 * @brief sets the light state
 * 
 */
void LightIntegrator::setLight() {
    light->setLight();
}

/**
 * @brief returns the light state
 * 
 * @return true if the light is on 
 * @return false if the light is off
 */
bool LightIntegrator::getLight() {
    return light->getLight();
}