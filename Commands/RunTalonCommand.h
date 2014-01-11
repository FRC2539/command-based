#ifndef RUN_TALON_COMMAND_H
#define RUN_TALON_COMMAND_H

#include "../CommandBase.h"

class RunTalonCommand : public CommandBase {
public:
	RunTalonCommand(float speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

protected:
	float m_speed;
};

#endif
