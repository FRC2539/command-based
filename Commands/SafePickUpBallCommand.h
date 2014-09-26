#ifndef SAFE_PICK_UP_BALL_COMMAND_H
#define SAFE_PICK_UP_BALL_COMMAND_H

#include "Types/ConditionalCommand.h"

class SafePickUpBallCommand : public ConditionalCommand {

public:
	SafePickUpBallCommand();
	
protected:
	bool shouldRun();
};

#endif
