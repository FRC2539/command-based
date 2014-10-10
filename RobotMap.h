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
	namespace DriveBase {
		const unsigned int leftMotorsPort = 2;
		const unsigned int rightMotorsPort = 1;

		const unsigned int gyroPort = 1;

		const unsigned int leftEncoderPortA = 4;
		const unsigned int leftEncoderPortB = 5;
		const unsigned int rightEncoderPortA = 6;
		const unsigned int rightEncoderPortB = 7;

		const double accelerationFactor = 0.8;
		const double preciseModeMaxY = 0.45;
		const double preciseModeMaxRotate = 0.45;
	}

	namespace Pneumatics {
		const unsigned int airCompressorPort = 1;
		const unsigned int pressureSwitchPort = 5;
	}

	namespace PickUpArm {
		const unsigned int wheelsMotorPort = 3;
		const unsigned int ballSensorPort = 2;

		const double pickUpSpeed = 1;
		const double passTimeout = 1;
	}
}

#endif
