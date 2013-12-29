#ifndef STOP_MOTOR_COMMAND_H
#define STOP_MOTOR_COMMAND_H

#include "../CommandBase.h"

class StopMotorCommand : public CommandBase {
public:
	StopMotorCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
