#pragma once

/**
 * The Config is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

//#define DEBUG
#define SKID 1
#define MECANUM 2

namespace Config {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort;
	typedef const unsigned int PneumaticPort;
	typedef const unsigned int CanID;

	namespace DriveTrain {
		#define DRIVE_TYPE SKID

		CanID frontLeftMotorID = 1;
		CanID frontRightMotorID = 3 ;
		CanID backLeftMotorID = 2;
		CanID backRightMotorID = 4;

		AnalogPort gyroPort = 0;
		const double gyroSensitivity = 0.007;

		const double encoderSensitivity = 0.02;

		const double maxSpeed = 150;
		const double preciseModeMaxSpeed = 50;
		const double accelerationRate = 0.01;
	}
}

#if ! DRIVE_TYPE
	#error No drive type specified
#endif
