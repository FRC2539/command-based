#ifndef SAFE_PASS_BALL_COMMAND_H
#define SAFE_PASS_BALL_COMMAND_H

#include "Types/ConditionalCommand.h"

class SafePassBallCommand : public ConditionalCommand {

public:
	SafePassBallCommand();

protected:
	bool shouldRun();
};

#endif
