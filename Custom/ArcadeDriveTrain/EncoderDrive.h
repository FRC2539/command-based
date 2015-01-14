#ifndef ENCODER_DRIVE_H
#define ENCODER_DRIVE_H

#include <RobotDrive.h>

class SpeedController;
class Encoder;
class EncoderRatePIDController;

class EncoderDrive : public RobotDrive {

public:
	EncoderDrive(
		SpeedController* leftMotor,
		SpeedController* rightMotor,
		Encoder* leftEncoder,
		Encoder* rightEncoder
	);

	virtual void SetLeftRightMotorOutputs(float leftOutput, float rightOutput);
	void setMaxSpeed(float speed);

	void ignoreEncoders();

protected:
	Encoder* m_leftEncoder;
	Encoder* m_rightEncoder;

	float m_maxSpeed;

	bool m_brokenEncoder;

	EncoderRatePIDController* leftMotorSpeed;
	EncoderRatePIDController* rightMotorSpeed;

	void scaleMotor(SpeedController* motor, Encoder* encoder, float& oppositeInput);
};

#endif
