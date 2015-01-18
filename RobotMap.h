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

	namespace DriveBase {
		#define MECANUM_DRIVE
		//#define ARCADE_DRIVE

		PWMPort frontLeftMotorsPort = 0;
		PWMPort frontRightMotorsPort = 1;
		PWMPort backLeftMotorsPort = 2;
		PWMPort backRightMotorsPort = 3;

		const double encoderSensitivity = 0.053333333;

		const double maxSpeed = 100;
		const double accelerationFactor = 0.03;
		const double preciseModeMaxSpeed = 20;

		const double P = 0.0075;
		const double I = 0;
		const double D = 0.001;
	}
}

#if defined(MECANUM_DRIVE) && defined(ARCADE_DRIVE)
	#error Multiple drive types specified
#elif ! (defined(MECANUM_DRIVE) || defined(ARCADE_DRIVE))
	#error No drive type specified
#endif

#endif
