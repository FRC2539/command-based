#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Commands/PIDSubsystem.h"

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

	float limitAcceleration(float current, float next);

	float PID(float current, float target, float p, float i, float d);
	void resetPID();


protected:
	SelfCleaningDrive* drive;
	Gyro* gyro;
	Encoder* rightEncoder;
	Encoder* leftEncoder;

	float currentY;
	float currentRotate;

	//PID Variables
	float error;
	float totalError;
	float previousError;
	float deltaError;
	float p_out, i_out, d_out;
	float output;

private:
	int ticks;
};

#endif
