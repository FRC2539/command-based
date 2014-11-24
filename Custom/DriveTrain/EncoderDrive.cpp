#include "EncoderDrive.h"

#include <cmath>

#include <SpeedController.h>
#include <Encoder.h>
#include <PIDController.h>

#include "EncoderRatePIDSource.h"

#include "../../RobotMap.h"

EncoderDrive::EncoderDrive(
	SpeedController* leftMotor,
	SpeedController* rightMotor,
	Encoder* leftEncoder,
	Encoder* rightEncoder
): RobotDrive(leftMotor, rightMotor)
{
	m_leftEncoder = leftEncoder;
	m_rightEncoder = rightEncoder;

	m_maxSpeed = RobotMap::DriveBase::maxSpeed;
	m_brokenEncoder = false;

	leftMotorSpeed = new PIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		new EncoderRatePIDSource(m_leftEncoder),
		leftMotor
	);
	leftMotorSpeed->SetInputRange(-m_maxSpeed, m_maxSpeed);

	rightMotorSpeed = new PIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		new EncoderRatePIDSource(m_rightEncoder),
		rightMotor
	);
	rightMotorSpeed->SetInputRange(-m_maxSpeed, m_maxSpeed);
}

void EncoderDrive::SetMaxSpeed(float speed)
{
	m_maxSpeed = speed;
}

void EncoderDrive::SetLeftRightMotorOutputs(float leftOutput, float rightOutput)
{
	// If one motor is pegged, scale the other down to match
	// NOTE: Are there cases where both conditions could be true?
	if (m_rearLeftMotor->Get() > .99 || m_rearLeftMotor->Get() < -.99)
	{
		rightOutput *= std::abs(leftOutput);
	}
	if (m_rearRightMotor->Get() > .99 || m_rearRightMotor->Get() < -.99)
	{
		leftOutput *= std::abs(rightOutput);
	}

	leftMotorSpeed->SetSetpoint(leftOutput * m_maxSpeed);
	rightMotorSpeed->SetSetpoint(rightOutput * m_maxSpeed);
}

