#ifndef CODE_OLDDOOR_H
#define CODE_OLDDOOR_H

#include "DoorType.h"

class OldDoor : public DoorType{
    public:
        void toggleDoor() override;
};


#endif //CODE_OLDDOOR_H
