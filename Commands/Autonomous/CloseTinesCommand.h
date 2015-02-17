#ifndef CLOSE_TINES_COMMAND_H
#define CLOSE_TINES_COMMAND_H

#include "../Types/DefaultCommand.h"

class CloseTinesCommand : public DefaultCommand {

public:
	CloseTinesCommand();
	void Initialize();
	bool IsFinished();
	void End();
	
protected:
	double previousWidth;
	int stoppedCount;
};

#endif
