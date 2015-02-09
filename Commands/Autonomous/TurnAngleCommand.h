#ifndef TURN_ANGLE_COMMAND_H
#define TURN_ANGLE_COMMAND_H

#include "../Types/DefaultCommand.h"

class PIDController;

class TurnAngleCommand : public DefaultCommand {

public:
	TurnAngleCommand(double angle);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	double m_angle;

	PIDController* pidLoop;
};

#endif