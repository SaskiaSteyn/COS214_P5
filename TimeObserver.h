#ifndef CODE_TIMEOBSERVER_H
#define CODE_TIMEOBSERVER_H

#include <string>
#include "Mediator.h"

using namespace std;

class TimeObserver {
    protected:
        int time;
        Mediator *mediator;
    public:
        TimeObserver();
        TimeObserver(Mediator *newMediator);
        int getTime();
        void advanceTime();
        void sendMessage();
};


#endif //CODE_TIMEOBSERVER_H
