#ifndef CODE_SMARTDOOR_H
#define CODE_SMARTDOOR_H

#include "DoorType.h"

class SmartDoor : public DoorType{
    public:
        void toggleDoor() override;
};


#endif //CODE_SMARTDOOR_H
