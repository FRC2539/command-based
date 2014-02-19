#ifndef AUTO_DRIVE_COMMAND_H
#define AUTO_DRIVE_COMMAND_H

#include "../CommandBase.h"

class AutoDriveCommand : public CommandBase {

public:
	AutoDriveCommand(float speed, float seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
protected:
    float m_seconds;
    float m_speed;
};

#endif
