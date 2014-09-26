#ifndef SAFE_BALL_PICK_UP_COMMAND_H
#define SAFE_BALL_PICK_UP_COMMAND_H

#include "Types/ConditionalCommand.h"

class SafeBallPickUpCommand : public ConditionalCommand {

public:
	SafeBallPickUpCommand();
	
protected:
	bool shouldRun();
};

#endif
