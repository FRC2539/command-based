#ifndef SET_TINES_COMMAND_H
#define SET_TINES_COMMAND_H

#include "../Types/DefaultCommand.h"

class SetTinesCommand : public DefaultCommand {

public:
	SetTinesCommand(double target);
	void Initialize();
	bool IsFinished();
	void End();
	
protected:
	double targetWidth;
	int speed;
};

#endif