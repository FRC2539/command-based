#include "DriveTrain.h"

#include <Gyro.h>
#include <RobotDrive.h>

#include <cmath>

#include "../Commands/DriveCommand.h"
#include "../Config.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_motors = {
		new CANTalon(Config::DriveBase::frontLeftMotorID),
		new CANTalon(Config::DriveBase::frontRightMotorID),
		new CANTalon(Config::DriveBase::backLeftMotorID),
		new CANTalon(Config::DriveBase::backRightMotorID)
	};

	setMode(CANTalon::kSpeed);
	for (auto motor : m_motors)
	{
		motor->SetVoltageRampRate(0.5);
		motor->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		motor->SetSafetyEnabled(false);
	}

#if defined(ARCADE_DRIVE)
	// Only control the front motors and have the back motors follow
	m_motors[RobotDrive::kRearLeftMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_motors[RobotDrive::kRearLeftMotor]->Set(
		Config::DriveBase::frontLeftMotorID
	);
	m_motors[RobotDrive::kRearRightMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_motors[RobotDrive::kRearRightMotor]->Set(
		Config::DriveBase::frontRightMotorID
	);
#endif

	m_speeds.resize(m_motors.size());

	m_gyro = new Gyro(Config::DriveBase::gyroPort);
	m_gyro->SetSensitivity(Config::DriveBase::gyroSensitivity);
	m_fieldOrientation = false;
}

DriveTrain::~DriveTrain()
{
	for (auto motor: m_motors)
	{
		delete motor;
	}

	delete m_gyro;
}

void DriveTrain::move(float x, float y, float rotate)
{
#if defined(ARCADE_DRIVE)
	x = 0;
#endif

	if (m_fieldOrientation)
	{
		float angle = getAngle();

		double cosA = cos(angle * (3.14159 / 180.0));
		double sinA = sin(angle * (3.14159 / 180.0));
		double xOut = x * cosA - y * sinA;
		double yOut = x * sinA + y * cosA;
		x = xOut;
		y = yOut;
	}

	m_speeds[RobotDrive::kFrontLeftMotor] = x + y + rotate;
	m_speeds[RobotDrive::kFrontRightMotor] = x - y + rotate;
	m_speeds[RobotDrive::kRearLeftMotor] = -x + y + rotate;
	m_speeds[RobotDrive::kRearRightMotor] = -x - y + rotate;

	// Don't allow input values > 1 (Example: x=0.5, y=0.5, rotate=1)
	float maxSpeed = 0;
	for (auto speed : m_speeds)
	{
		float currentSpeed = std::abs(speed);
		if (currentSpeed > maxSpeed)
		{
			maxSpeed = currentSpeed;
		}
	}
	if (maxSpeed > 1.0)
	{
		for (auto &speed : m_speeds)
		{
			speed /= maxSpeed;
		}
	}

	if (m_readEncoders == false)
	{
		setOutputs(1);
		return;
	}

	equalizeMotors();
	setOutputs(m_maxSpeed);
}

void DriveTrain::stop()
{
	for (auto motor : m_motors)
	{
		motor->ClearIaccum();
	}
	move(0, 0, 0);
}

void DriveTrain::equalizeMotors()
{
	float maxVoltage = m_motors[0]->GetBusVoltage() - 0.1;
	float slowFactor = 1;

	// If one motor is pegged, don't let the others pass it
	// NOTE: Are there cases where motors could be pegged at different values?
	unsigned int index = 0;
	for (auto motor : m_motors)
	{
		float currentVoltage = std::abs(motor->GetOutputVoltage());
		if (currentVoltage > maxVoltage)
		{
			float sensorValue = std::abs(motor->Get());
			if (sensorValue < m_maxSpeed)
			{
				float disproportion = std::abs(
					sensorValue / (m_speeds[index] * m_maxSpeed)
				);
				if (disproportion < slowFactor)
				{
					slowFactor = disproportion;
				}
			}
		}

		index++;
	}

	if (slowFactor < 1)
	{
		for (auto &speed : m_speeds)
		{
			speed *= slowFactor;
		}
	}
}

void DriveTrain::setOutputs(float maxValue)
{
	unsigned int index = 0;
	for (auto motor : m_motors)
	{
		if (motor->GetControlMode() != CANTalon::kFollower)
		{
			motor->Set(m_speeds[index] * maxValue);
		}
		index++;
	}
}

void DriveTrain::enableFieldOrientation(bool isActive)
{
	m_fieldOrientation = isActive;
}

void DriveTrain::disableFieldOrientation()
{
	enableFieldOrientation(false);
}

void DriveTrain::resetGyro()
{
	m_gyro->Reset();
}

float DriveTrain::getAngle()
{
	return m_gyro->GetAngle();
}

void DriveTrain::useEncoders()
{
	m_readEncoders = true;
	setMode(CANTalon::kSpeed);
}

void DriveTrain::ignoreEncoders()
{
	m_readEncoders = false;
	setMode(CANTalon::kPercentVbus);
}

void DriveTrain::moveDistance(double distance, SensorMoveDirection direction)
{
	if (m_readEncoders == false)
	{
		wpi_setErrorWithContext(
			129,
			"Cannot determine distance while encoders are disabled"
		);
		return;
	}

	distance /= Config::DriveBase::encoderSensitivity;

	setMode(CANTalon::kPosition);

#if defined(MECANUM_DRIVE)
	if (direction == DriveX)
	{

		m_motors[RobotDrive::kFrontLeftMotor]->Set(
			m_motors[RobotDrive::kFrontLeftMotor]->GetPosition() + distance
		);
		m_motors[RobotDrive::kFrontRightMotor]->Set(
			m_motors[RobotDrive::kFrontRightMotor]->GetPosition() + distance
		);
		m_motors[RobotDrive::kRearLeftMotor]->Set(
			m_motors[RobotDrive::kRearLeftMotor]->GetPosition() - distance
		);
		m_motors[RobotDrive::kRearRightMotor]->Set(
			m_motors[RobotDrive::kRearRightMotor]->GetPosition() - distance
		);

		return;
	}

	m_motors[RobotDrive::kRearLeftMotor]->Set(
		m_motors[RobotDrive::kRearLeftMotor]->GetPosition() + distance
	);
	m_motors[RobotDrive::kRearRightMotor]->Set(
		m_motors[RobotDrive::kRearRightMotor]->GetPosition() - distance
	);
#endif

	m_motors[RobotDrive::kFrontLeftMotor]->Set(
		m_motors[RobotDrive::kFrontLeftMotor]->GetPosition() + distance
	);
	m_motors[RobotDrive::kFrontRightMotor]->Set(
		m_motors[RobotDrive::kFrontRightMotor]->GetPosition() - distance
	);
}

bool DriveTrain::doneMoving()
{
	float maxError = 10;
	bool onTarget = true;
	for (auto motor : m_motors)
	{
		if (std::abs(motor->GetClosedLoopError()) > maxError)
		{
			onTarget = false;
		}
	}

	if (onTarget)
	{
		setMode(CANTalon::kSpeed);
	}

	return onTarget;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCommand());
}

void DriveTrain::setMaxSpeed(float speed)
{
	// Rescale acceleration to match speed
	float rescaleFactor = speed / m_maxSpeed;
	for (auto motor : m_motors)
	{
		motor->SetI(motor->GetI() * rescaleFactor);
	}

	m_maxSpeed = speed;
}

void DriveTrain::setMode(CANTalon::ControlMode mode)
{
	for (auto motor : m_motors)
	{
		if (motor->GetControlMode() == CANTalon::kFollower)
		{
			continue;
		}

		if (mode == CANTalon::kPosition)
		{
			motor->SetPID(0.1, 0, 0);
		}
		else if (mode == CANTalon::kSpeed)
		{
			motor->ClearIaccum();
			motor->SetPID(0, Config::DriveBase::accelerationRate, 0);
		}
		motor->SetControlMode(mode);
	}

}
