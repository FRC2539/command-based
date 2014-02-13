#ifndef DRIVE_DISTANCE_COMMAND_H
#define DRIVE_DISTANCE_COMMAND_H

#include "../CommandBase.h"

class DriveDistanceCommand : public CommandBase {

public:
	DriveDistanceCommand(double timeout, float d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	float distance;
};

#endif
