#ifndef CODE_SMARTLIGHT_H
#define CODE_SMARTLIGHT_H

#include "LightType.h"

class SmartLight : public LightType{
    public:
        void setLight() override;
};


#endif //CODE_SMARTLIGHT_H
