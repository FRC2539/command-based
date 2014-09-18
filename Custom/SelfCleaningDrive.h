#ifndef SELF_CLEANING_DRIVE_H
#define SELF_CLEANING_DRIVE_H

#include "RobotDrive.h"

class SpeedController;

/*
 * This class is just like the RobotDrive, except that motors passed as pointers
 * will automatically be deleted in the destructor.
 */
class SelfCleaningDrive: public RobotDrive {
public:
	SelfCleaningDrive(uint32_t leftMotorChannel, uint32_t rightMotorChannel);
	SelfCleaningDrive(
		uint32_t frontLeftMotorChannel,
		uint32_t rearLeftMotorChannel,
		uint32_t frontRightMotorChannel,
		uint32_t rearRightMotorChannel
	);
	SelfCleaningDrive(SpeedController *leftMotor, SpeedController *rightMotor);
	SelfCleaningDrive(SpeedController &leftMotor, SpeedController &rightMotor);
	SelfCleaningDrive(
		SpeedController *frontLeftMotor,
		SpeedController *rearLeftMotor,
		SpeedController *frontRightMotor,
		SpeedController *rearRightMotor
	);
	SelfCleaningDrive(
		SpeedController &frontLeftMotor,
		SpeedController &rearLeftMotor,
		SpeedController &frontRightMotor,
		SpeedController &rearRightMotor
	);

};

#endif