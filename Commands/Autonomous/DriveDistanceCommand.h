#ifndef DRIVE_DISTANCE_COMMAND_H
#define DRIVE_DISTANCE_COMMAND_H

#include "../Types/DefaultCommand.h"

class DriveDistanceCommand : public DefaultCommand {

public:
	DriveDistanceCommand(
		double distance,
		DriveTrain::SensorMoveDirection direction=DriveTrain::DriveY
	);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double m_distance;
	DriveTrain::SensorMoveDirection m_direction;

};

#endif
