#include "DriveTrain.h"

#include "../RobotMap.h"

#include "../Custom/SelfCleaningDrive.h"
#include <Talon.h>
#include <Gyro.h>
#include <Encoder.h>

#include "../Commands/ArcadeDriveCommand.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
	currentY(0),
	currentRotate(0)
{
	drive = new SelfCleaningDrive(
		new Talon(RobotMap::DriveBase::rightMotorsPort),
		new Talon(RobotMap::DriveBase::leftMotorsPort)
	);

	drive->SetSafetyEnabled(false);

	gyro = new Gyro(RobotMap::DriveBase::gyroPort);

	leftEncoder = new Encoder(
		RobotMap::DriveBase::leftEncoderPortA,
		RobotMap::DriveBase::leftEncoderPortB
	);
	rightEncoder = new Encoder(
		RobotMap::DriveBase::rightEncoderPortA,
		RobotMap::DriveBase::rightEncoderPortB
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
	if (next > current + RobotMap::DriveBase::accelerationFactor)
	{
		return (current + RobotMap::DriveBase::accelerationFactor);
	}
	else if (next < current - RobotMap::DriveBase::accelerationFactor)
	{
		return (current - RobotMap::DriveBase::accelerationFactor);
	}
	else
	{
		return next;
	}
}

void DriveTrain::move(float yValue, float rotate) {
	currentY = limitAcceleration(currentY, yValue);
	currentRotate = limitAcceleration(currentRotate, rotate);

	directDrive(currentY, currentRotate);
}

void DriveTrain::directDrive(float yValue, float rotateValue, bool squareInputs)
{
	drive->ArcadeDrive(-yValue, -rotateValue, squareInputs);
}

