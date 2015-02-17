#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

//#define DEBUG

namespace RobotMap {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort;
	typedef const unsigned int PneumaticPort;
	typedef const unsigned int CanID;

	namespace DriveBase {
		#define MECANUM_DRIVE
		//#define ARCADE_DRIVE

		CanID frontLeftMotorID = 1;
		CanID frontRightMotorID = 5;
		CanID backLeftMotorID = 3;
		CanID backRightMotorID = 4;

		AnalogPort gyroPort = 0;
		const double encoderSensitivity = 0.053333333;
		const double gyroSensitivity = 0.007;

		const double maxSpeed = 200;
		const double preciseModeMaxSpeed = 20;

		const double P = 0.1;
		const double I = 0;
		const double D = 0.05;
	}

	namespace Elevator {
		CanID elevatorMotorID = 2;

		const unsigned int stepSize = 1000;
		const unsigned int stepSpeed = 100;

		const unsigned int minPosition = 0;
		const unsigned int maxPosition = 10000;

		const double P = 0.3;
		const double I = 0;
		const double D = 0;
	}

	namespace Tines {
		PWMPort tinesMotorPort = 9;
		AnalogPort stringPotentiometerPort = 3;

		const double maxWidth = 29;
		const double minWidth = 14.5;
	}
}

#if defined(MECANUM_DRIVE) && defined(ARCADE_DRIVE)
	#error Multiple drive types specified
#elif ! (defined(MECANUM_DRIVE) || defined(ARCADE_DRIVE))
	#error No drive type specified
#endif

#endif
