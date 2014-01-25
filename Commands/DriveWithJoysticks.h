#ifndef DRIVE_WITH_JOYSTICKS_H
#define DRIVE_WITH_JOYSTICKS_H

#include "../CommandBase.h"

class DriveWithJoysticks: public CommandBase {
public:
	DriveWithJoysticks();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

protected:
	float forward, rotation;
};

#endif
