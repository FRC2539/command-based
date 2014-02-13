#ifndef ROTATE_ANGLE_COMMAND_H
#define ROTATE_ANGLE_COMMAND_H

#include "../CommandBase.h"

class RotateAngleCommand : public CommandBase {

public:
	RotateAngleCommand(double timeout, float a);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	float angle;
};

#endif
