#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/Subsystem.h"
#include <Gyro.h>
#include "Encoder.h"

class SelfCleaningDrive;

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

};

#endif
