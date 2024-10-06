#include "ThermoIntegrator.h"

ThermoIntegrator::ThermoIntegrator() {
    this->thermostat = nullptr;
}

ThermoIntegrator::~ThermoIntegrator() {
    delete thermostat;
}

void ThermoIntegrator::addThermo(ThermoType *newThermo) {
    this->thermostat = newThermo;
}

void ThermoIntegrator::setThermo(float oldTemp, float newTemp) {
    if(newTemp >= oldTemp){
        thermostat->increaseTemp(newTemp);
    }
    else{
        thermostat->decreaseTemp(newTemp);
    }
}

float ThermoIntegrator::getThermo() {
    return thermostat->getTemp();
}
