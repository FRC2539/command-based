#ifndef DRIVE_DISTANCE_COMMAND_H
#define DRIVE_DISTANCE_COMMAND_H

#include "../Types/DefaultCommand.h"

class PIDController;

class DriveDistanceCommand : public DefaultCommand {

public:
	enum Direction {
		X,
		Y
	};

	DriveDistanceCommand(double distance, Direction direction=Y);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double distanceToTarget();

	double m_distance;
	Direction m_direction;

	bool onTarget;
	double targetPosition;
	float inverted;
};

#endif
