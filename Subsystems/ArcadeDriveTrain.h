#ifndef ARCADE_DRIVE_TRAIN_H
#define ARCADE_DRIVE_TRAIN_H

#include "../Custom/DebuggingSubsystem.h"
#include <vector>

class EncoderDrive;
class Encoder;
class Talon;

class ArcadeDriveTrain: public Subsystem {
public:
	ArcadeDriveTrain();
	virtual ~ArcadeDriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float rotateValue);

	void setMaxSpeed(float speed);

protected:
	EncoderDrive* drive;
	Talon* leftMotor;
	Talon* rightMotor;
	Encoder* leftEncoder;
	Encoder* rightEncoder;

	float currentY;
	float currentRotate;
};

#endif
