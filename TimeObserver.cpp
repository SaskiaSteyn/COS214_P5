#include "TimeObserver.h"

TimeObserver::TimeObserver() {
    time = 0;
    this->mediator = nullptr;
}

TimeObserver::TimeObserver(Mediator* newMediator) {
    time = 0;
    this->mediator = newMediator;
}

int TimeObserver::getTime() {
    return this->time;
}

void TimeObserver::advanceTime() {
    time++;
    if (this->time > 3) {
        time = 0;
    }

    sendMessage();
}

void TimeObserver::sendMessage() {
    if (time == 0) {
        this->mediator->handleReceivedMessage("Time changed to morning");
    }
    else if (time == 1) {
        this->mediator->handleReceivedMessage("Time changed to afternoon");
    }
    else if (time == 2) {
        this->mediator->handleReceivedMessage("Time changed to evening");
    }
    else {
        this->mediator->handleReceivedMessage("Time changed to night");
    }
}