#include "ThermoNode.h"

ThermoNode::ThermoNode() {

}

ThermoNode::ThermoNode(Integrator *thermo) {
    this->thermo = thermo;
    this->next = nullptr;
    this->prev = nullptr;
}
