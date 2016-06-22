#pragma once

#include "../Types/DefaultCommand.h"

class DriveDistanceCommandGroup;

class ApproachPositionCommand : public DefaultCommand {

public:
	explicit ApproachPositionCommand(float distance);

	void Initialize() override;
	bool IsFinished() override;
	void End() override;

protected:
	DriveDistanceCommandGroup* m_parent;
	int m_speed;
};
