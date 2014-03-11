#ifndef RUN_BACK_COMMAND_H
#define RUN_BACK_COMMAND_H

#include "Types/TimedCommand.h"

class RunBackCommand : public TimedCommand {

public:
	RunBackCommand();
	void Initialize();
	void End();
};

#endif
