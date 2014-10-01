#ifndef PASS_BALL_COMMAND_H
#define PASS_BALL_COMMAND_H

#include "Types/DefaultCommand.h"

class PassBallCommand : public DefaultCommand {

public:
	PassBallCommand();
	void Initialize();
	bool IsFinished();
	void End();

protected:
    bool ballReleased;
};

#endif
