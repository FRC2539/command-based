#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is where we store constants, the most common of which are port
 * numbers. This provides flexibility, makes checking the wiring easier, and
 * significantly reduces the number of magic numbers floating around.
 */

//#define ENABLE_AIR_COMPRESSOR
#define DEBUG

namespace RobotMap {

	typedef const unsigned int PWMPort;
	typedef const unsigned int DIOPort;
	typedef const unsigned int AnalogPort;
	typedef const unsigned int RelayPort; 
	typedef const unsigned int PneumaticPort;

	namespace DriveBase {
		PWMPort leftMotorsPort = 2;
		PWMPort rightMotorsPort = 1;

		AnalogPort gyroPort = 1;

		DIOPort leftEncoderPortA = 4;
		DIOPort leftEncoderPortB = 5;
		DIOPort rightEncoderPortA = 6;
		DIOPort rightEncoderPortB = 7;

		const double gyroSensitivity = 0.007;
		const double encoderSensitivity = 0.053333333;

		const double accelerationFactor = 0.08;
		const double preciseModeMaxY = 0.45;
		const double preciseModeMaxRotate = 0.45;
	}

	namespace Pneumatics {
		RelayPort airCompressorPort = 1;
		DIOPort pressureSwitchPort = 1;
	}

	namespace PickUpArm {
		PWMPort wheelsMotorPort = 3;
		DIOPort ballSensorPort = 2;
		PneumaticPort lowerArmPort = 1;
		PneumaticPort RaiseArmPort = 2;


		const double pickUpSpeed = 1;
		const double passTimeout = 1;
	}
}

#endif
