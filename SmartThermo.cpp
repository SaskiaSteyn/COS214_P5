#include "SmartThermo.h"

SmartThermo::SmartThermo(float initialTemp) : ThermoType(initialTemp) {

}

void SmartThermo::increaseTemp(float newTemp) {
    if (newTemp > temp) {
        temp = newTemp;
        cout << "Smart thermostat: Increased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Smart thermostat: New temperature must be higher than the current temperature." << endl;
    }
}

void SmartThermo::decreaseTemp(float newTemp) {
    if (newTemp < temp) {
        temp = newTemp;
        cout << "Smart thermostat: Decreased temperature to " << temp << "°C" << endl;
    } else {
        cout << "Smart thermostat: New temperature must be lower than the current temperature." << endl;
    }
}
