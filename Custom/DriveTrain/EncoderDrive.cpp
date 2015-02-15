#include "EncoderDrive.h"

#include <cmath>
#include <iterator>
#include <algorithm>

#include <CANTalon.h>
#include <Encoder.h>

#include "RatePIDController.h"
#include "EncoderRatePIDSource.h"
#include "CANTalonRatePIDSource.h"

#include "../../RobotMap.h"

EncoderDrive::EncoderDrive(
	SpeedController* leftMotor,
	SpeedController* rightMotor,
	Encoder* leftEncoder,
	Encoder* rightEncoder
): RobotDrive(leftMotor, rightMotor),
	m_maxSpeed(RobotMap::DriveBase::maxSpeed),
	m_brokenEncoder(false)
{
	addMotor(new EncoderRatePIDSource(leftEncoder), leftMotor);
	addMotor(new EncoderRatePIDSource(rightEncoder), rightMotor);

	speeds.resize(motors.size());
}

EncoderDrive::EncoderDrive(
	CANTalon* frontLeftMotor,
	CANTalon* backLeftMotor,
	CANTalon* frontRightMotor,
	CANTalon* backRightMotor
): RobotDrive(frontLeftMotor, backLeftMotor, frontRightMotor, backRightMotor),
	m_maxSpeed(RobotMap::DriveBase::maxSpeed),
	m_brokenEncoder(false)
{
	addMotor(new CANTalonRatePIDSource(frontLeftMotor), frontLeftMotor);
	addMotor(new CANTalonRatePIDSource(frontRightMotor), frontRightMotor);
	addMotor(new CANTalonRatePIDSource(backLeftMotor), backLeftMotor);
	addMotor(new CANTalonRatePIDSource(backRightMotor), backRightMotor);

	speeds.resize(motors.size());
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

	speeds[0] = leftOutput;
	speeds[1] = rightOutput;

	equalizeMotors();
}

void EncoderDrive::MecanumDrive(double x, double y, double rotate, double angle)
{
	if (m_brokenEncoder)
	{
		RobotDrive::MecanumDrive_Cartesian(x, -y, rotate, angle);
		return;
	}

	static bool reported = false;
	if (!reported)
	{
		HALReport(
			HALUsageReporting::kResourceType_RobotDrive,
			motors.size(),
			HALUsageReporting::kRobotDrive_MecanumCartesian
		);
		reported = true;
	}

	// Compensate for gyro angle.
	RotateVector(x, y, angle);

	speeds[kFrontLeftMotor] = x + y + rotate;
	speeds[kFrontRightMotor] = -x + y - rotate;
	speeds[kRearLeftMotor] = -x + y + rotate;
	speeds[kRearRightMotor] = x + y - rotate;

	for (int i = 1; i < kMaxNumberOfMotors; i++)
	{
		speeds[i] *= m_invertedMotors[i];
	}

	// Normalize joystick values
	float maxSpeed = std::abs(speeds[kFrontLeftMotor]);
	for (int i = 1; i < kMaxNumberOfMotors; i++)
	{
		float currentSpeed = std::abs(speeds[i]);
		if (currentSpeed > maxSpeed)
		{
			maxSpeed = currentSpeed;
		}
	}
	if (maxSpeed > 1.0)
	{
		for (int i=0; i < kMaxNumberOfMotors; i++)
		{
			speeds[i] = speeds[i] / maxSpeed;
		}
	}

	equalizeMotors();
}

void EncoderDrive::addMotor(PIDSource* sensor, SpeedController* motor)
{
	sensors.push_back(sensor);
	motors.push_back(motor);

	RatePIDController* output = new RatePIDController(
		RobotMap::DriveBase::P,
		RobotMap::DriveBase::I,
		RobotMap::DriveBase::D,
		1,
		sensor,
		motor
	);
	output->SetInputRange(-m_maxSpeed, m_maxSpeed);
	output->SetPercentTolerance('1');
	output->Enable();
	outputs.push_back(output);
}


void EncoderDrive::equalizeMotors()
{
	int motorCount = motors.size();
	float maxInput = 1;
	float currentInput = 0;
	float peggedInput = 0;
	int peggedIndex = -1;

	// If one motor is pegged, don't let the others pass it
	// NOTE: Are there cases where motors could be pegged at different values?
	for (int i=0; i < motorCount; i++)
	{
		currentInput = std::abs(motors[i]->Get());
		if (currentInput > .99)
		{
			peggedInput = std::abs(sensors[i]->PIDGet()) / m_maxSpeed;
			if (peggedInput < maxInput)
			{
				maxInput = peggedInput;
				peggedIndex = i;
			}
		}
	}

	if (peggedIndex != -1)
	{
		for (int i=0; i < motorCount; i++)
		{
			if (i == peggedIndex)
			{
				continue;
			}

			if (speeds[i] >= 0)
			{
				speeds[i] = std::min(speeds[i], maxInput);
			}
			else
			{
				speeds[i] = std::max(speeds[i], -maxInput);
			}
		}
	}
	for (int i=0; i < motorCount; i++)
	{
		outputs[i]->SetSetpoint(speeds[i] * m_maxSpeed);
	}

	m_safetyHelper->Feed();
}

void EncoderDrive::ignoreEncoders()
{
	m_brokenEncoder = true;

	for (auto pidLoop : outputs)
	{
		pidLoop->Disable();
	}
}

void EncoderDrive::resetEncoders()
{
	for (auto pidLoop : outputs)
	{
		pidLoop->Reset();
		if (m_brokenEncoder == false)
		{
			pidLoop->Enable();
		}
	}
}

float EncoderDrive::getYPosition()
{
	float position = 0;
	int sensorCount = sensors.size();

	for (int i=0; i < sensorCount; i++)
	{
		position += sensors[i]->PIDGet() * m_invertedMotors[i];
	}

	return position / sensorCount;
}

float EncoderDrive::getXPosition()
{
	float position = sensors[kFrontLeftMotor]->PIDGet();
	position += sensors[kFrontRightMotor]->PIDGet(); // double inverted
	position += sensors[kRearLeftMotor]->PIDGet() * -1;
	position += sensors[kRearRightMotor]->PIDGet() * -1;

	return position / 4;
}
