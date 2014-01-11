#ifndef AUTONOMOUS_COMMAND_GROUP_H
#define AUTONOMOUS_COMMAND_GROUP_H

#include "../CommandBase.h"
#include "RunMotorCommand.h"
#include "StopMotorCommand.h"
#include "RunTalonCommand.h"
#include "StopTalonCommand.h"


class AutonomousCommandGroup: public CommandGroup {
public:
	AutonomousCommandGroup();
};

#endif
