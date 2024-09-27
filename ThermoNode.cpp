#include "ThermoNode.h"

ThermoNode::ThermoNode() {

}

ThermoNode::ThermoNode(Integrator *thermo) {
    this->thermo = thermo;
}
