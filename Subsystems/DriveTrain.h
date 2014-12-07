#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "../Custom/DebuggingSubsystem.h"
#include <vector>

class RobotDrive;
class Gyro;
class Encoder;
class Talon;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float rotateValue);
	void directDrive(float yValue, float rotateValue, bool squareInputs=false);

	float limitAcceleration(float current, float next);

protected:
	RobotDrive* drive;
	Talon* leftMotor;
	Talon* rightMotor;
	Gyro* gyro;
	Encoder* leftEncoder;
	Encoder* rightEncoder;

	float currentY;
	float currentRotate;

};

#endif
