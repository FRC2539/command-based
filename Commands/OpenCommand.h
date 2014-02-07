#ifndef OPEN_COMMAND_H
#define OPEN_COMMAND_H

#include "../CommandBase.h"

class OpenCommand : public CommandBase {

public:
	OpenCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:

};

#endif
