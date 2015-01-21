#ifndef ENCODER_DRIVE_H
#define ENCODER_DRIVE_H

#include <RobotDrive.h>

#include <vector>
#include <tuple>

class SpeedController;
class CANTalon;
class Encoder;
class EncoderRatePIDController;
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
	virtual void MecanumDrive(double x, double y, double rotate, double angle);
	void setMaxSpeed(float speed);

	void ignoreEncoders();

protected:
	float m_maxSpeed;

	bool m_brokenEncoder;

	std::vector<PIDSource*> sensors;
	std::vector<EncoderRatePIDController*> outputs;
	std::vector<SpeedController*> motors;
	std::vector<float> speeds;

	void equalizeMotors();
	void addMotor(PIDSource* sensor, SpeedController* motor);
};

#endif
