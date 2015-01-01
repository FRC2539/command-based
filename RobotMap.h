#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

//#define ENABLE_AIR_COMPRESSOR
//#define DEBUG

namespace RobotMap {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort;
	typedef const unsigned int PneumaticPort;

	namespace DriveBase {
		PWMPort leftMotorsPort = 2;
		PWMPort rightMotorsPort = 1;

		DIOPort leftEncoderPortA = 4;
		DIOPort leftEncoderPortB = 5;
		DIOPort rightEncoderPortA = 6;
		DIOPort rightEncoderPortB = 7;

		const double encoderSensitivity = 0.053333333;

		const double maxSpeed = 100;
		const double accelerationFactor = 0.03;
		const double preciseModeMaxSpeed = 45;

		const double P = 0.01;
		const double I = 0;
		const double D = 0;
	}

	namespace Pneumatics {
		RelayPort airCompressorPort = 1;
		DIOPort pressureSwitchPort = 1;
	}
}

#endif
