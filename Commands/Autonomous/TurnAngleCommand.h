#ifndef TURN_ANGLE_COMMAND_H
#define TURN_ANGLE_COMMAND_H

#include "../Types/PIDCommand.h"

class TurnAngleCommand : public PIDCommand {

public:
	TurnAngleCommand(double angle);
	void Initialize();
	void End();

protected:
	double ReturnPIDInput();
	void UsePIDOutput(double output);

	double m_angle;
};

#endif
