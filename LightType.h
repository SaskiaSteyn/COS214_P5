#ifndef CODE_LIGHTTYPE_H
#define CODE_LIGHTTYPE_H

#include <iostream>

using namespace std;

class LightType {
    protected:
        bool lightOnOff;

    public:
        LightType();
        virtual void setLight();
        bool getLight();

};


#endif //CODE_LIGHTTYPE_H
