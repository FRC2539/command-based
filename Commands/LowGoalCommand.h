#pragma once

#include "Types/ConditionalCommand.h"

class LowGoalCommand : public ConditionalCommand {
public:
    LowGoalCommand();

protected:
    virtual bool shouldRun();
};

