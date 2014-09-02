#include "SelfCleaningDrive.h"

#include "SpeedController.h"

SelfCleaningDrive::SelfCleaningDrive(
		SpeedController *frontLeftMotor,
		SpeedController *rearLeftMotor,
		SpeedController *frontRightMotor,
		SpeedController *rearRightMotor
	) : RobotDrive(
		frontLeftMotor,
		rearLeftMotor,
		frontRightMotor,
		rearRightMotor
	) {
		m_deleteSpeedControllers = true;
	}

SelfCleaningDrive::SelfCleaningDrive(
		SpeedController *leftMotor,
		SpeedController *rightMotor
	) : RobotDrive(
		leftMotor,
		rightMotor
	) {
		m_deleteSpeedControllers = true;
	}

// The rest of these don't do anything.
SelfCleaningDrive::SelfCleaningDrive(
		UINT32 leftMotorChannel,
		UINT32 rightMotorChannel
	) : RobotDrive(
		leftMotorChannel,
		rightMotorChannel
	) {}

SelfCleaningDrive::SelfCleaningDrive(
		UINT32 frontLeftMotorChannel,
		UINT32 rearLeftMotorChannel,
		UINT32 frontRightMotorChannel,
		UINT32 rearRightMotorChannel
	) : RobotDrive(
		frontLeftMotorChannel,
		rearLeftMotorChannel,
		frontRightMotorChannel,
		rearRightMotorChannel
	) {}

SelfCleaningDrive::SelfCleaningDrive(
		SpeedController &leftMotor,
		SpeedController &rightMotor
	) : RobotDrive(
		leftMotor,
		rightMotor
	) {}

SelfCleaningDrive::SelfCleaningDrive(
		SpeedController &frontLeftMotor,
		SpeedController &rearLeftMotor,
		SpeedController &frontRightMotor,
		SpeedController &rearRightMotor
	) : RobotDrive(
		frontLeftMotor,
		rearLeftMotor,
		frontRightMotor,
		rearRightMotor
	) {}
