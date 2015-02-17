#ifndef CLOSE_TINES_COMMAND_H
#define CLOSE_TINES_COMMAND_H

#include "../Types/DefaultCommand.h"

class CloseTinesCommand : public DefaultCommand {

public:
	CloseTinesCommand();
	void Initialize();
	void End();
	bool IsFinished();
	
protected:
	double previousgetwidth;
	int stoppedCount;
};

#endif
