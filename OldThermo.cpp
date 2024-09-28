#include "OldThermo.h"

OldThermo::OldThermo(float initialTemp) : ThermoType(initialTemp) {

}

void OldThermo::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        cout << "Legacy thermostat: Increased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Legacy thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

void OldThermo::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        cout << "Legacy thermostat: Decreased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Legacy thermostat: New temperature must be lower than the current temperature." << endl;
    }
}
