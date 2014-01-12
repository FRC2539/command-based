#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include"../Robotmap.h"

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void driveWithController(Joystick* controller);

private:
	RobotDrive* drive;

	DRIVE_MOTOR_CONTROLLER* frontRight;
	DRIVE_MOTOR_CONTROLLER* frontLeft;
	DRIVE_MOTOR_CONTROLLER* backRight;
	DRIVE_MOTOR_CONTROLLER* backLeft;
};
#endif
