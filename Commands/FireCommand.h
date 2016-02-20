#pragma once

#include "Types/ConditionalCommand.h"

class FireCommand : public ConditionalCommand {
public:
    FireCommand();

protected:
    virtual bool shouldRun();
};

