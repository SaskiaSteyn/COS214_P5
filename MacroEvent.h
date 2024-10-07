#ifndef CODE_MACROEVENT_H
#define CODE_MACROEVENT_H

#include <iostream>
using namespace std;

class MacroEvent {
    public:
        MacroEvent() {}
        virtual string sendMessage() = 0;
};


#endif //CODE_MACROEVENT_H
