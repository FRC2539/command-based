#ifndef DRIVE_TIMED_COMMAND_H
#define DRIVE_TIMED_COMMAND_H

#include "../Types/TimedCommand.h"

class DriveTimedCommand : public TimedCommand {

public:
	DriveTimedCommand(float speed, double seconds);
	void Initialize();
	void End();

protected:
    float m_speed;
};

#endif
