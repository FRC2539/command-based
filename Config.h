#pragma once

/**
 * The Config is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

#define DEBUG
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
		CanID frontRightMotorID = 3;
		CanID backLeftMotorID = 2;
		CanID backRightMotorID = 4;

		const double encoderSensitivity = 0.02;

		const double maxSpeed = 300;
		const double preciseModeMaxSpeed = 75;
		const double accelerationRate = 0.01;
	}
	namespace PickupArms {
		CanID Forward = 5;
		CanID BackLeft = 6;
		CanID BackRight = 7;
		const double p = .11;
		const double max = 5;
		const double min = 4.927;
	}
}

	

#if ! DRIVE_TYPE
	#error No drive type specified
#endif
