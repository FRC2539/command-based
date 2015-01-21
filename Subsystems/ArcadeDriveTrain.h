#ifndef ARCADE_DRIVE_TRAIN_H
#define ARCADE_DRIVE_TRAIN_H

#include "DriveTrain.h"

class Encoder;
class Talon;

class ArcadeDriveTrain: public DriveTrain {
public:
	ArcadeDriveTrain();
	virtual ~ArcadeDriveTrain();

	void move(float yValue, float rotateValue);
	virtual void stop();

protected:
	Talon* leftMotor;
	Talon* rightMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
};

#define MOVE_WITH_JOYSTICK\
	move(\
		oi->getAxisValue(logicalAxes::DriveY),\
		oi->getAxisValue(logicalAxes::DriveRotate)\
	)

#endif
