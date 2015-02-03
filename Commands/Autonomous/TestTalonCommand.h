#ifndef TEST_TALON_COMMAND_H
#define TEST_TALON_COMMAND_H

#include "../Types/TimedCommand.h"

class TestTalonCommand : public TimedCommand {

public:
	TestTalonCommand();
	void Initialize();
	void End();
};

#endif
