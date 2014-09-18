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
		uint32_t leftMotorChannel,
		uint32_t rightMotorChannel
	) : RobotDrive(
		leftMotorChannel,
		rightMotorChannel
	) {}

SelfCleaningDrive::SelfCleaningDrive(
		uint32_t frontLeftMotorChannel,
		uint32_t rearLeftMotorChannel,
		uint32_t frontRightMotorChannel,
		uint32_t rearRightMotorChannel
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
