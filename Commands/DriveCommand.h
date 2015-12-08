#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "Types/DefaultCommand.h"

class DriveCommand : public DefaultCommand {

public:
	explicit DriveCommand(const double speed);
	void Initialize();
	void Execute();

protected:
	double m_speed;
};

#endif
