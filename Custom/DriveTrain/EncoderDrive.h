#ifndef ENCODER_DRIVE_H
#define ENCODER_DRIVE_H

#include <RobotDrive.h>

#include "../../RobotMap.h"

#include <vector>

class SpeedController;
class CANTalon;
class Encoder;
class RatePIDController;
class PIDSource;

class EncoderDrive : public RobotDrive {

public:
	EncoderDrive(
		SpeedController* leftMotor,
		SpeedController* rightMotor,
		Encoder* leftEncoder,
		Encoder* rightEncoder
	);

	EncoderDrive(
		CANTalon* frontLeftMotor,
		CANTalon* backLeftMotor,
		CANTalon* frontRightMotor,
		CANTalon* backRightMotor
	);

	virtual void SetLeftRightMotorOutputs(float leftOutput, float rightOutput);
	virtual void MecanumDrive(double x, double y, double rotate, double angle=0.0);
	void setMaxSpeed(float speed);
	void setMotorSpeed(RobotMap::CanID motorID, float speed);
	void ignoreEncoders();

protected:
	float m_maxSpeed;

	bool m_brokenEncoder;

	std::vector<PIDSource*> sensors;
	std::vector<RatePIDController*> outputs;
	std::vector<SpeedController*> motors;
	std::vector<float> speeds;

	void equalizeMotors();
	void addMotor(PIDSource* sensor, SpeedController* motor);
};

#endif
