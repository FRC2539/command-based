#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"

class SelfCleaningDrive;
class Gyro;
class Encoder;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float rotateValue);
	void preciseMove(float yValue, float rotateValue);

protected:
	SelfCleaningDrive* drive;
	Gyro* gyro;
	Encoder* rightEncoder;
	Encoder* leftEncoder;

	float currentY;
	float currentRotate;

	float limitAcceleration(float current, float next);

private:
	int ticks;
};

#endif
