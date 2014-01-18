#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"

class SelfCleaningDrive;
class GenericHID;

class DriveTrain: public Subsystem {
public:
	DriveTrain();
	virtual ~DriveTrain();
	void InitDefaultCommand();

	void driveWithController(GenericHID *controller);

private:
	SelfCleaningDrive* drive;
};

#endif
