#ifndef MECANUM_DRIVE_TRAIN_H
#define MECANUM_DRIVE_TRAIN_H

#include "../Custom/DebuggingSubsystem.h"
#include <vector>

class EncoderDrive;
class Encoder;
class Talon;

class MecanumDriveTrain: public Subsystem {
public:
	MecanumDriveTrain();
	virtual ~MecanumDriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float xValue, float rotateValue);

	void setMaxSpeed(float speed);

protected:
	EncoderDrive* drive;
	Talon* frontLeftMotor;
	Talon* frontRightMotor;
	Talon* backLeftMotor;
	Talon* backRightMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;

	float currentY;
	float currentRotate;
};

#endif
