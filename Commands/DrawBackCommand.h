#ifndef DRAWBACK_COMMAND_H
#define DRAWBACK_COMMAND_H

#include "Types/TimedCommand.h"

class DrawBackCommand : public TimedCommand {

public:
	DrawBackCommand();
	void Initialize();
	bool IsFinished();
	void End();


};

#endif
