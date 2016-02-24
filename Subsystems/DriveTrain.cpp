#include "DriveTrain.h"

#include <RobotDrive.h>

#include <cmath>

#include "../Commands/DriveCommand.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), m_navX(SPI::Port::kMXP)
{
	m_motors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::frontLeftMotorID)
	);
	m_motors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::frontRightMotorID)
	);
	m_motors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::backLeftMotorID)
	);
	m_motors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::backRightMotorID)
	);

	setMode(CANTalon::kSpeed, true);
	for (auto motor : m_motors)
	{
		motor->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		motor->SetSafetyEnabled(false);
		motor->SetSensorDirection(true);
	}

#if DRIVE_TYPE == SKID
	// Only control the front motors and have the back motors follow because
	// there is only one encoder per side in an arcade drive setup.
	m_motors[RobotDrive::kRearLeftMotor]->SetControlMode(
		CANTalon::kPercentVbus
	);
	m_motors[RobotDrive::kRearRightMotor]->SetControlMode(
		CANTalon::kPercentVbus
	);
#endif

	m_speeds.resize(m_motors.size());
	m_stopped = false;

	m_maxSpeed = Config::DriveTrain::maxSpeed;
	m_readEncoders = true;
	m_defenseLastState = DefenseState::Floor;
	
#if DRIVE_TYPE == MECANUM
	m_fieldOrientation = false;
#endif

#ifdef DEBUG
	DEBUG_SENSOR(m_navX);
	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator(
		GetName(),
		"FrontLeftMotor",
		m_motors[RobotDrive::kFrontLeftMotor]
	);
	lw->AddActuator(
		GetName(),
		"FrontRightMotor",
		m_motors[RobotDrive::kFrontRightMotor]
	);
	lw->AddActuator(
		GetName(),
		"RearLeftMotor",
		m_motors[RobotDrive::kRearLeftMotor]
	);
	lw->AddActuator(
		GetName(),
		"RearRightMotor",
		m_motors[RobotDrive::kRearRightMotor]
	);
#endif
}

void DriveTrain::move(float x, float y, float rotate)
{
	SmartDashboard::PutNumber("Angle", getAngle());
	SmartDashboard::PutNumber("Pitch", m_navX.GetRoll());
	SmartDashboard::PutNumber("Roll", m_navX.GetPitch());
	SmartDashboard::PutNumber(
		"Defense State",
		static_cast<int>(getDefenseState())
	);

#if DRIVE_TYPE == SKID
	x = 0;
#endif
	y *= Config::DriveTrain::rotationGain;

#if DRIVE_TYPE == MECANUM
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
#endif

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
		setOutputs(m_maxSpeed / Config::DriveTrain::maxSpeed);
		return;
	}

	equalizeMotors();
	//handleStop();
	setOutputs(m_maxSpeed);
}

DriveTrain::DefenseState DriveTrain::getDefenseState()
{
	return m_defenseLastState;
}

void DriveTrain::calculateDefenseState()
{
	double speed = m_speeds[RobotDrive::kFrontLeftMotor];
	speed -= m_speeds[RobotDrive::kFrontRightMotor];
	speed += m_speeds[RobotDrive::kRearLeftMotor];
	speed -= m_speeds[RobotDrive::kRearRightMotor];

	double pitch = m_navX.GetRoll();
	
	if (speed > 0)
	{
		if (pitch > 5)
		{
			m_defenseLastState = DefenseState::Up;
		}
		else if (pitch < -5) 
		{
			m_defenseLastState = DefenseState::Down;
		}
		else
		{
			if (m_defenseLastState == DefenseState::Up)
			{
				m_defenseLastState = DefenseState::Defense;
			}
			else if (m_defenseLastState == DefenseState::Down)
			{
				m_defenseLastState = DefenseState::Floor;
			}
		}
	}
	if (speed < 0)
	{
		if (pitch > 5)
		{
			m_defenseLastState = DefenseState::Down;
		}
		else if (pitch < -5) 
		{
			m_defenseLastState = DefenseState::Up;
		}
		else 
		{
			if (m_defenseLastState == DefenseState::Up)
			{
				m_defenseLastState = DefenseState::Defense;
			}
			else if (m_defenseLastState == DefenseState::Down)
			{
				m_defenseLastState = DefenseState::Floor;
			}
		}
	}
}

void DriveTrain::stop()
{
	if (m_readEncoders)
	{
		setMode(CANTalon::kSpeed);
		m_maxSpeed = Config::DriveTrain::maxSpeed;
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
			if (motor->GetControlMode() == CANTalon::kPercentVbus)
			{
				index++;
				continue;
			}
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

void DriveTrain::handleStop()
{
	bool isStopped = true;
	for (auto &speed : m_speeds)
	{
		if (std::abs(speed) > 0.05)
		{
			isStopped = false;
		}
	}
	if (isStopped)
	{
		m_stopped = true;
		for (auto &motor : m_motors)
		{
			motor->SetControlMode(CANTalon::kPercentVbus);
		}
	}
	else if (m_stopped)
	{
		m_stopped = false;
		for (auto &motor : m_motors)
		{
			motor->SetControlMode(CANTalon::kSpeed);
		}
	}
}

void DriveTrain::setOutputs(float maxValue)
{
	unsigned int index = 0;
	for (auto motor : m_motors)
	{
#if DRIVE_TYPE == SKID
		if (m_readEncoders && motor->GetControlMode() == CANTalon::kPercentVbus)
		{
			motor->Set(
				m_motors[index - 2]->GetOutputVoltage() /
				m_motors[index - 2]->GetBusVoltage()
			);
		}
		else
		{
#endif
			motor->Set(m_speeds[index] * maxValue);
#if DRIVE_TYPE == SKID
		}
#endif
		index++;
	}
}

#if DRIVE_TYPE == MECANUM
void DriveTrain::enableFieldOrientation(bool isActive)
{
	m_fieldOrientation = isActive;
}

void DriveTrain::disableFieldOrientation()
{
	enableFieldOrientation(false);
}
#endif

void DriveTrain::resetGyro()
{
	m_navX.ZeroYaw();
}

float DriveTrain::getAngle()
{
	return m_navX.GetAngle();
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

	distance /= Config::DriveTrain::encoderSensitivity;

	setMode(CANTalon::kPosition);

#if DRIVE_TYPE == MECANUM
	if (direction == SensorMoveDirection::DriveX)
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
	for (auto motor : m_motors)
	{
		if (std::abs(motor->GetClosedLoopError()) > maxError)
		{
			return false;
		}
	}

	return true;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveCommand(Config::DriveTrain::maxSpeed));
}

void DriveTrain::setMaxSpeed(float speed)
{
	// Rescale acceleration to match speed
	float rescaleFactor = speed / m_maxSpeed;
	for (auto motor : m_motors)
	{
		motor->SetI(motor->GetI());
	}

	m_maxSpeed = speed;
}

void DriveTrain::setMode(CANSpeedController::ControlMode mode, bool resetAll)
{
	for (auto &motor : m_motors)
	{
		if ( ! resetAll && motor->GetControlMode() == CANTalon::kPercentVbus)
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
			motor->SetPID(0, Config::DriveTrain::accelerationRate, 0);
		}
		motor->SetControlMode(mode);
	}

}
