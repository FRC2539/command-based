#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"

class SelfCleaningDrive;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void move(float yValue, float rotateValue);

protected:
	SelfCleaningDrive* drive;

	float currentY;
	float currentRotate;

	float limitAcceleration(float current, float next);
};

#endif
