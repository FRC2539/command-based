#ifndef CONFIG_H
#define CONFIG_H

/**
 * The Config is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

//#define DEBUG

namespace Config {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort;
	typedef const unsigned int PneumaticPort;
	typedef const unsigned int CanID;

	namespace DriveTrain {
		//#define MECANUM_DRIVE
		#define ARCADE_DRIVE

		CanID frontLeftMotorID = 1;
		CanID frontRightMotorID = 5;
		CanID backLeftMotorID = 3;
		CanID backRightMotorID = 4;

		AnalogPort gyroPort = 0;
		const double gyroSensitivity = 0.007;

		const double encoderSensitivity = 0.02;

		const double maxSpeed = 150;
		const double preciseModeMaxSpeed = 50;
		const double accelerationRate = 0.01;
	}
}

#if defined(MECANUM_DRIVE) && defined(ARCADE_DRIVE)
	#error Multiple drive types specified
#elif ! (defined(MECANUM_DRIVE) || defined(ARCADE_DRIVE))
	#error No drive type specified
#endif

#endif
