#ifndef MECANUM_DRIVE_TRAIN_H
#define MECANUM_DRIVE_TRAIN_H

#include "DriveTrain.h"

class CANTalon;

class MecanumDriveTrain: public DriveTrain {
public:
	MecanumDriveTrain();
	virtual ~MecanumDriveTrain();

	void move(float xValue, float yValue, float rotateValue);
	virtual void stop();

protected:
	CANTalon* frontLeftMotor;
	CANTalon* frontRightMotor;
	CANTalon* backLeftMotor;
	CANTalon* backRightMotor;
};

#define MOVE_WITH_JOYSTICK\
	drivetrain->move(\
		oi->getAxisValue(logicalAxes::DriveX),\
		oi->getAxisValue(logicalAxes::DriveY),\
		oi->getAxisValue(logicalAxes::DriveRotate)\
	)

#endif
