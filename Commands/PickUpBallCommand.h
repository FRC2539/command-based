#ifndef PICK_UP_BALL_COMMAND_H
#define PICK_UP_BALL_COMMAND_H

#include "Types/DefaultCommand.h"

class PickUpBallCommand : public DefaultCommand {

public:
	PickUpBallCommand();
	void Initialize();
	bool IsFinished();
	void End();

};

#endif

