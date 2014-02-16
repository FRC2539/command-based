#ifndef UNBLOCK_SHOOTER_COMMAND_H
#define UNBLOCK_SHOOTER_COMMAND_H

#include "../CommandBase.h"

class UnblockShooterCommand : public CommandBase {

public:
	UnblockShooterCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:
	bool wasBlocked;
};

#endif
