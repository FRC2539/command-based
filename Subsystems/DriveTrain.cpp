#include "DriveTrain.h"

#include "../RobotMap.h"

#include "../Custom/SelfCleaningDrive.h"
#include <Talon.h>
#include <Gyro.h>
#include <Encoder.h>

#include "../Commands/ArcadeDriveCommand.h"

#include <iostream>

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	currentY(0),
	currentRotate(0)
{

	#ifdef FRONT_RIGHT_DRIVE_MOTOR_PORT
	drive = new SelfCleaningDrive(
		new Talon(FRONT_LEFT_DRIVE_MOTOR_PORT),
		new Talon(BACK_LEFT_DRIVE_MOTOR_PORT),
		new Talon(FRONT_RIGHT_DRIVE_MOTOR_PORT),
		new Talon(BACK_RIGHT_DRIVE_MOTOR_PORT)
	);
	#endif
	#ifdef RIGHT_DRIVE_MOTOR_PORT
	drive = new SelfCleaningDrive(
		new Talon(LEFT_DRIVE_MOTOR_PORT),
		new Talon(RIGHT_DRIVE_MOTOR_PORT)
	);
	#endif

	drive->SetSafetyEnabled(false);

	gyro = new Gyro(GYRO_MODULE, GYRO_PORT);

	leftEncoder = new Encoder(
		ENCODER_MODULE,
		LEFT_ENCODER_A_PORT,
		ENCODER_MODULE,
		LEFT_ENCODER_B_PORT
	);
	rightEncoder = new Encoder(
		ENCODER_MODULE,
		RIGHT_ENCODER_A_PORT,
		ENCODER_MODULE,
		RIGHT_ENCODER_B_PORT

	);
	leftEncoder->SetDistancePerPulse(.053333333);
	rightEncoder->SetDistancePerPulse(.053333333);
	leftEncoder->Start();
	rightEncoder->Start();
}

DriveTrain::~DriveTrain() {
	delete drive;
	delete gyro;
	delete leftEncoder;
	delete rightEncoder;
}

void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new ArcadeDriveCommand());
}

float DriveTrain::limitAcceleration(float current, float next)
{
	if (next > current + ACCELERATION_FACTOR)
	{
		return (current + ACCELERATION_FACTOR);
	}
	else if (next < current - ACCELERATION_FACTOR)
	{
		return (current - ACCELERATION_FACTOR);
	}
	else
	{
		return next;
	}
}

void DriveTrain::move(std::vector<float> values) {
	currentY = limitAcceleration(currentY, values[0]);
	currentRotate = limitAcceleration(currentRotate, values[1]);

	directDrive(currentY, currentRotate, true);

}

void DriveTrain::preciseMove(std::vector<float> values) {
	currentY = (values[0] * values[0]) * MAX_Y_PRECISE_SPEED;
	currentRotate = (values[1] * values[1]) * MAX_ROTATE_PRECISE_SPEED;

	if (values[0] < 0)
	{
		currentY *= -1;
	}
	if (values[1] < 0)
	{
		currentRotate *= -1;
	}

	directDrive(currentY, currentRotate);
}

void DriveTrain::directDrive(float yValue, float rotateValue, bool squareInputs)
{
	// For some reason, we need to invert rotateValue
	// We really ought to investigate why that is...
	drive->ArcadeDrive(-yValue, -rotateValue, squareInputs);
}

