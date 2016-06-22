#pragma once

#include "../Types/DefaultCommand.h"

class DriveDistanceCommandGroup;

class StopAtPositionCommand : public DefaultCommand {

public:
	StopAtPositionCommand();
	void Initialize();
	bool IsFinished();
	void End();

protected:
	DriveDistanceCommandGroup* m_parent;
	unsigned int m_atTargetCount;
};
