#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

//#define ENABLE_AIR_COMPRESSOR

namespace RobotMap {
	namespace DriveBase {
		const unsigned int leftMotorsPort = 2;
		const unsigned int rightMotorsPort = 1;

		const unsigned int gyroPort = 1;

		const unsigned int leftEncoderPortA = 1;
		const unsigned int leftEncoderPortB = 2;
		const unsigned int rightEncoderPortA = 3;
		const unsigned int rightEncoderPortB = 4;

		const double accelerationFactor = 0.0085;
		const double preciseModeMaxY = 0.45;
		const double preciseModeMaxRotate = 0.45;
	}

	namespace Pneumatics {
		const unsigned int airCompressorPort = 1;
		const unsigned int pressureSwitchPort = 5;
	}
}

#endif
