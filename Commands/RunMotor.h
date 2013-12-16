#ifndef RUN_MOTOR_H
#define RUN_MOTOR_H

#include "../CommandBase.h"

class RunMotor : public CommandBase {
public:
	RunMotor(float speed, double duration);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

protected:
	float m_speed;
	double m_timeout;
};

#endif
