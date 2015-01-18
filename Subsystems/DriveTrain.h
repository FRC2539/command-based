#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "../Custom/DebuggingSubsystem.h"

class EncoderDrive;

class DriveTrain: public Subsystem {
public:
	DriveTrain(const char* type);
	virtual ~DriveTrain();
	virtual void InitDefaultCommand();

	void setMaxSpeed(float speed);
	virtual void stop() = 0;

protected:
	EncoderDrive* drive;
};

#endif
