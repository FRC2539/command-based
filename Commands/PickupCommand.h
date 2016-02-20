#pragma once

#include "Types/ConditionalCommand.h"

class PickupCommand : public ConditionalCommand {
public:
    PickupCommand();

protected:
    virtual bool shouldRun();
};

