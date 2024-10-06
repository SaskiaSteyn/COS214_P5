#include "TimeObserver.h"

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

string TimeObserver::sendMessage() {
    if (time == 0) {
        return "Time changed to morning";
    }
    else if (time == 1) {
        return "Time changed to afternoon";
    }
    else if (time == 2) {
        return "Time changed to evening";
    }
    else {
        return "Time changed to night";
    }
}