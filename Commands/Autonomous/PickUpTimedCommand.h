#ifndef PICK_UP_TIMED_COMMAND_H
#define PICK_UP_TIMED_COMMAND_H

#include "../Types/TimedCommand.h"

class PickUpTimedCommand : public TimedCommand {

public:
	PickUpTimedCommand(float direction, double seconds);
	void Initialize();
	void End();
protected:
    float m_direction;
};

#endif
