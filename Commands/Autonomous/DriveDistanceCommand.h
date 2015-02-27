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

	DriveDistanceCommand(double distance, Direction direction=Y, double speed=0);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double distanceToTarget();

	double m_distance;
	Direction m_direction;

	double m_speed;
	
	bool onTarget;
	double targetPosition;
	float inverted;
};

#endif
