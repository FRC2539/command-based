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

		// Ratio of y speed to rotation speed, between 0 and 1
		const double rotationGain = 0.6;
	}

	namespace PickupArms {
		CanID rollerMotorID = 5;
		CanID leftPivotMotorID = 6;
		CanID rightPivotMotorID = 7;
		const double P = .11;
		const double maxHeight = 5;
		const double minHeight = 4.927;
	}

	namespace Shooter {
		CanID tallMotorRightID = 8;
		CanID tallMotorLeftID = 9;
		CanID indexWheelID = 10;
		CanID shooterWheelID = 11;
		const double maxTall = .1;
		const double minTall = .01;

		const double P = .11;
		const double I = 42;

		DIOPort maxTallLSID = 0;
		DIOPort minTallLSID = 1;

		DIOPort ballDetectorID = 2;
	}
}

#if ! DRIVE_TYPE
	#error No drive type specified
#endif
