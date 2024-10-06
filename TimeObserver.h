#ifndef CODE_TIMEOBSERVER_H
#define CODE_TIMEOBSERVER_H

#include <string>

using namespace std;

class TimeObserver {
    protected:
        int time;
    public:
        int getTime();
        void advanceTime();
        string sendMessage();
};


#endif //CODE_TIMEOBSERVER_H
