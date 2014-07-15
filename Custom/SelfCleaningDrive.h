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
	SelfCleaningDrive(UINT32 leftMotorChannel, UINT32 rightMotorChannel);
	SelfCleaningDrive(
		UINT32 frontLeftMotorChannel,
		UINT32 rearLeftMotorChannel,
		UINT32 frontRightMotorChannel,
		UINT32 rearRightMotorChannel
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