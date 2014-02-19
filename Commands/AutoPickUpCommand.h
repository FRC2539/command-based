#ifndef AUTO_PICK_UP_COMMAND_H
#define AUTO_PICK_UP_COMMAND_H

#include "../CommandBase.h"

class AutoPickUpCommand : public CommandBase {

public:
	AutoPickUpCommand(float direction, float seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
protected:
    float m_direction;
    float m_seconds;
};

#endif
