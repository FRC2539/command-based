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

private:
	SelfCleaningDrive* drive;
};

#endif
