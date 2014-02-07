#ifndef FIRE_COMMAND_H
#define FIRE_COMMAND_H

#include "../CommandBase.h"

class FireCommand : public CommandBase {

public:
	FireCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:

};

#endif
