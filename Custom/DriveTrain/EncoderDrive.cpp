#include "EncoderDrive.h"
#include <iostream>

#include <cmath>

#include <SpeedController.h>
#include <Encoder.h>
#include "EncoderRatePIDController.h"

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

	leftMotorSpeed = new EncoderRatePIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		new EncoderRatePIDSource(m_leftEncoder),
		leftMotor
	);
	leftMotorSpeed->Reset();
	leftMotorSpeed->SetInputRange(-m_maxSpeed, m_maxSpeed);
	leftMotorSpeed->SetPercentTolerance('1');
	leftMotorSpeed->Enable();
	leftMotorSpeed->SetSetpoint(0);

	rightMotorSpeed = new EncoderRatePIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		new EncoderRatePIDSource(m_rightEncoder),
		rightMotor
	);
	rightMotorSpeed->Reset();
	rightMotorSpeed->SetInputRange(-m_maxSpeed, m_maxSpeed);
	rightMotorSpeed->SetPercentTolerance('1');
	rightMotorSpeed->Enable();
	rightMotorSpeed->SetSetpoint(0);
}

void EncoderDrive::setMaxSpeed(float speed)
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

	leftOutput *= m_maxSpeed;
	if (leftOutput != 0)
	{
		setFeedForward(leftMotorSpeed, m_rearLeftMotor->Get()/leftOutput);
	}
	rightOutput *= -m_maxSpeed;
	if (rightOutput != 0)
	{
		setFeedForward(rightMotorSpeed, m_rearRightMotor->Get()/rightOutput);
	}
	leftMotorSpeed->SetSetpoint(leftOutput);
	rightMotorSpeed->SetSetpoint(rightOutput);
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

void EncoderDrive::setFeedForward(EncoderRatePIDController *encoder, float f)
{
	encoder->SetPID(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		f
	);
}


void EncoderDrive::ignoreEncoders()
{
	m_brokenEncoder = true;
}

