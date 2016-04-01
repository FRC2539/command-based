#pragma once

/**
 * The Config is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

#define SKID 1
#define MECANUM 2

namespace Config {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort;
	typedef const unsigned int PneumaticPort;
	typedef const unsigned int CanID;
	typedef const double PID[3];

	namespace DriveTrain {
		#define DRIVE_TYPE SKID

		CanID frontLeftMotorID = 1;
		CanID frontRightMotorID = 3;
		CanID backLeftMotorID = 2;
		CanID backRightMotorID = 4;

		const double encoderSensitivity = 0.02;

		const double maxSpeed = 300;
		const double preciseModeMaxSpeed = 75;
		PID movingPID = {0, 0.01225, 0};
		PID distancePID = {0.1, 0, 0};

		// Ratio of y speed to rotation speed, between 0 and 1
		const double rotationGain = 0.8;
	}

	namespace Shooter {
		CanID rightPivotMotorID = 8;
		CanID leftPivotMotorID = 9;
		CanID indexWheelID = 10;
		CanID shooterWheelID = 11;

		DIOPort ballDetectorID = 0;

		const int minHeight = 0;
		const int shootingHeight = 100000;
		const int liftingHeight = 120000;
		const int maxHeight = 175000;

		const int pivotSpeed = 20000;
		PID pivotHoldPID = {0.003, 0, 0};
		PID pivotMovePID = {0, 0.001, 0};

		const double firingSpeed = 6000;
		PID shootingPID = {0, 0.01, 0};
	}
}

#if ! DRIVE_TYPE
	#error No drive type specified
#endif
