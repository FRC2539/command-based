#ifndef STOP_MOTOR_H
#define STOP_MOTOR_H

#include "../CommandBase.h"

class StopMotor : public CommandBase {
public:
	StopMotor();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
