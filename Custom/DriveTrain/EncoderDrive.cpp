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
	leftMotorSpeed->SetPercentTolerance('1');
	leftMotorSpeed->Enable();

	rightMotorSpeed = new PIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		new EncoderRatePIDSource(m_rightEncoder),
		rightMotor
	);
	rightMotorSpeed->SetInputRange(-m_maxSpeed, m_maxSpeed);
	rightMotorSpeed->SetPercentTolerance('1');
	rightMotorSpeed->Enable();
}

void EncoderDrive::SetMaxSpeed(float speed)
{
	m_maxSpeed = speed;
}

void EncoderDrive::SetLeftRightMotorOutputs(float leftOutput, float rightOutput)
{
	if (m_brokenEncoder)
	{
		RobotDrive::SetLeftRightMotorOutputs(leftOutput, rightOutput);
		return;
	}
	
	scaleMotor(m_rearLeftMotor, m_leftEncoder, rightOutput);
	scaleMotor(m_rearRightMotor, m_rightEncoder, leftOutput);

	leftMotorSpeed->SetSetpoint(leftOutput * m_maxSpeed);
	rightMotorSpeed->SetSetpoint(rightOutput * m_maxSpeed);
}

void EncoderDrive::scaleMotor(
	SpeedController* motor, 
	Encoder* encoder, 
	float& oppositeInput
)
{
	// If one motor is pegged, don't let the other pass it
	// NOTE: Are there cases where both motors could be pegged at different values?
	float currentInput = std::abs(motor->Get());
	if (currentInput > .99)
	{
		float maxInput = std::abs(encoder->GetRate()) / m_maxSpeed;
		if (oppositeInput >= 0)
		{
			oppositeInput = std::min(oppositeInput, maxInput);
		}
		else
		{
			oppositeInput = std::max(oppositeInput, -maxInput);
		}
	}
}
