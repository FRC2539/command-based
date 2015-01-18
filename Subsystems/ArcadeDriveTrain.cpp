#include "ArcadeDriveTrain.h"

#include "../RobotMap.h"
#if defined(ARCADE_DRIVE)

#include "../Custom/DriveTrain/EncoderDrive.h"
#include <Talon.h>
#include <Encoder.h>

ArcadeDriveTrain::ArcadeDriveTrain() : DriveTrain("ArcadeDriveTrain")
{
	rightMotor = new Talon(RobotMap::DriveBase::leftMotorsPort);
	leftMotor = new Talon(RobotMap::DriveBase::rightMotorsPort);

	leftEncoder = new Encoder(
		RobotMap::DriveBase::leftEncoderPortA,
		RobotMap::DriveBase::leftEncoderPortB
	);
	rightEncoder = new Encoder(
		RobotMap::DriveBase::rightEncoderPortA,
		RobotMap::DriveBase::rightEncoderPortB
	);
	leftEncoder->SetDistancePerPulse(RobotMap::DriveBase::encoderSensitivity);
	rightEncoder->SetDistancePerPulse(RobotMap::DriveBase::encoderSensitivity);

	drive = new EncoderDrive(leftMotor, rightMotor, leftEncoder, rightEncoder);
	drive->SetSafetyEnabled(false);

	DEBUG_SENSOR(leftEncoder);
	DEBUG_SENSOR(rightEncoder);

	DEBUG_MOTOR(leftMotor);
	DEBUG_MOTOR(rightMotor);
}

ArcadeDriveTrain::~ArcadeDriveTrain() {
	delete drive;
	delete leftMotor;
	delete rightMotor;
	delete leftEncoder;
	delete rightEncoder;
}

void ArcadeDriveTrain::move(float yValue, float rotate) {
	drive->ArcadeDrive(-yValue, -rotate, true);
}

void ArcadeDriveTrain::stop()
{
	drive->ArcadeDrive(0.0, 0.0);
}

#endif