#include "ThermoType.h"

ThermoType::ThermoType(float initialTemp) {
    this->temp = initialTemp;

}

void ThermoType::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        cout << "Thermostat: Temperature increased to " << temp << "°C" << endl;
    } else {
        cout << "Thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

void ThermoType::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        cout << "Thermostat: Temperature decreased to " << temp << "°C" << endl;
    } else {
        cout << "Thermostat: New temperature must be lower than the current temperature." << endl;
    }
}

float ThermoType::getTemp() {
    return temp;
}
