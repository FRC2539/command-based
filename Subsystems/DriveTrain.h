#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "../Custom/DebuggingSubsystem.h"
#include <vector>

class EncoderDrive;
class Encoder;
class Talon;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float rotateValue);
	void directDrive(float yValue, float rotateValue, bool squareInputs=false);

	void setMaxSpeed(float speed);

protected:
	EncoderDrive* drive;
	Talon* leftMotor;
	Talon* rightMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;

	float currentY;
	float currentRotate;

	float limitAcceleration(float current, float next);
};

#endif
