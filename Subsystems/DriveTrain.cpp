#include "DriveTrain.h"

#include <Gyro.h>
#include <RobotDrive.h>

#include <cmath>

#include "../Commands/DriveCommand.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_motors.push_back(new CANTalon(RobotMap::DriveBase::frontLeftMotorID));
	m_motors.push_back(new CANTalon(RobotMap::DriveBase::frontRightMotorID));
	m_motors.push_back(new CANTalon(RobotMap::DriveBase::backLeftMotorID));
	m_motors.push_back(new CANTalon(RobotMap::DriveBase::backRightMotorID));

	setMode(CANTalon::kSpeed);
	for (auto motor : m_motors)
	{
		motor->SetVoltageRampRate(0.5);
		motor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
		motor->SetSafetyEnabled(false);
	}

#if defined(ARCADE_DRIVE)
	// Only control the front motors and have the back motors follow
	m_motors[RobotDrive::kRearLeftMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_motors[RobotDrive::kRearLeftMotor]->Set(
		RobotMap::DriveBase::frontLeftMotorID
	);
	m_motors[RobotDrive::kRearRightMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_motors[RobotDrive::kRearRightMotor]->Set(
		RobotMap::DriveBase::frontRightMotorID
	);
#endif

	m_speeds.resize(m_motors.size());

	m_gyro = new Gyro(RobotMap::DriveBase::gyroPort);
	m_gyro->SetSensitivity(RobotMap::DriveBase::gyroSensitivity);
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

void DriveTrain::move(float y, float x, float rotate)
{
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

	equalizeMotors();
	setOutputs();
}

void DriveTrain::stop()
{
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

void DriveTrain::setOutputs()
{
	int index = -1;
	for (auto motor : m_motors)
	{
		index++;
		if (motor->GetControlMode() == CANTalon::kFollower)
		{
			continue;
		}
		motor->Set(m_speeds[index] * m_maxSpeed);
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

void DriveTrain::moveDistance(
	double distance,
	DriveTrain::SensorMoveDirection direction
)
{
	distance /= RobotMap::DriveBase::encoderSensitivity;

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
			motor->SetPID(0, RobotMap::DriveBase::accelerationRate, 0);
		}
		motor->SetControlMode(mode);
	}

}
