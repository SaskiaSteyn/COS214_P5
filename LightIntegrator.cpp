#include "LightIntegrator.h"

LightIntegrator::LightIntegrator() {
    this->light = nullptr;
}

LightIntegrator::~LightIntegrator() {
    delete light;
}

void LightIntegrator::addLight(LightType* newLight) {
    this->light = newLight;
}

void LightIntegrator::setLight() {
    light->setLight();
}

bool LightIntegrator::getLight() {
    return light->getLight();
}