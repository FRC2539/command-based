#ifndef RUN_MOTOR_COMMAND_H
#define RUN_MOTOR_COMMAND_H

#include "../CommandBase.h"

class RunMotorCommand : public CommandBase {
public:
	RunMotorCommand(float speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

protected:
	float m_speed;
};

#endif
