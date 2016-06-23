#include "DriveTrain.h"

#include <RobotDrive.h>

#include <cmath>
#include <string>
#include <algorithm>

#include "../Config.h"
#include "../Commands/DriveCommand.h"
#include "../Custom/Netconsole.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), m_navX(SPI::Port::kMXP)
{
	m_allMotors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::frontLeftMotorID)
	);
	m_allMotors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::frontRightMotorID)
	);
	m_allMotors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::backLeftMotorID)
	);
	m_allMotors.push_back(
		std::make_shared<CANTalon>(Config::DriveTrain::backRightMotorID)
	);

	for (auto motor : m_allMotors)
	{
		motor->ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
		motor->SetSafetyEnabled(false);
	}

	m_activeMotors.push_back(m_allMotors[RobotDrive::kFrontLeftMotor]);
	m_activeMotors.push_back(m_allMotors[RobotDrive::kFrontRightMotor]);

	m_allMotors[RobotDrive::kFrontLeftMotor]->SetSensorDirection(true);

#if DRIVE_TYPE == SKID
	// Only control the front motors and have the back motors follow because
	// there is only one encoder per side in an arcade drive setup.
	m_allMotors[RobotDrive::kRearLeftMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_allMotors[RobotDrive::kRearLeftMotor]->Set(
		Config::DriveTrain::frontLeftMotorID
	);
	m_allMotors[RobotDrive::kRearRightMotor]->SetControlMode(
		CANTalon::kFollower
	);
	m_allMotors[RobotDrive::kRearRightMotor]->Set(
		Config::DriveTrain::frontRightMotorID
	);
#elif DRIVE_TYPE == MECANUM
	m_activeMotors.push_back(m_allMotors[RobotDrive::kRearLeftMotor]);
	m_activeMotors.push_back(m_allMotors[RobotDrive::kRearRightMotor]);

	m_allMotors[RobotDrive::kRearLeftMotor]->SetSensorDirection(true);
#endif

	setMode(CANTalon::kSpeed);

	m_speeds.resize(m_allMotors.size());
	m_stopped = false;
	m_last[SensorMoveDirection::DriveX] = -1;
	m_last[SensorMoveDirection::DriveY] = -1;
	m_last[SensorMoveDirection::Rotate] = -1;

	setMaxSpeed(Config::DriveTrain::maxSpeed);
	m_readEncoders = true;
	m_defenseLastState = DefenseState::Floor;
	
	m_fieldOrientation = false;
	resetGyro();
	m_gyroOffset = 0;

	DEBUG_SENSOR(m_navX);
	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator(
		GetName(),
		"FrontLeftMotor",
		m_allMotors[RobotDrive::kFrontLeftMotor]
	);
	lw->AddActuator(
		GetName(),
		"FrontRightMotor",
		m_allMotors[RobotDrive::kFrontRightMotor]
	);
	lw->AddActuator(
		GetName(),
		"RearLeftMotor",
		m_allMotors[RobotDrive::kRearLeftMotor]
	);
	lw->AddActuator(
		GetName(),
		"RearRightMotor",
		m_allMotors[RobotDrive::kRearRightMotor]
	);
}

void DriveTrain::move(float x, float y, float rotate)
{
#if DRIVE_TYPE == SKID
	x = 0;
#endif

	if (x == m_last[SensorMoveDirection::DriveX] &&
		y == m_last[SensorMoveDirection::DriveY] &&
		rotate == m_last[SensorMoveDirection::Rotate])
	{
		return;
	}

	m_last[SensorMoveDirection::DriveX] = x;
	m_last[SensorMoveDirection::DriveY] = y;
	m_last[SensorMoveDirection::Rotate] = rotate;

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

	setOutputs();
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
		setMaxSpeed(Config::DriveTrain::maxSpeed);
	}

	move(0, 0, 0);
}

void DriveTrain::setOutputs()
{
	unsigned int index = 0;
	if (m_readEncoders == true)
	{
		bool isStopped = std::all_of(
			m_speeds.begin(),
			m_speeds.end(),
			[](float speed) { return std::abs(speed) < 0.1; }
		);
		if (isStopped)
		{
			for (auto motor : m_activeMotors)
			{
				motor->ClearIaccum();
			}
		}
		for (auto motor : m_activeMotors)
		{
			motor->Set(m_speeds[index] * m_maxSpeed);
			index++;
		}
	}
	else
	{
		for (auto motor : m_activeMotors)
		{
			motor->Set(m_speeds[index] * m_maxPercentVBus);
			index++;
		}
	}
}

void DriveTrain::enableFieldOrientation(bool isActive)
{
#if DRIVE_TYPE != MECANUM
	wpi_setErrorWithContext(
		129,
		"Field orientation is only available for mecanum drive"
	);
	return;
#endif
	m_fieldOrientation = isActive;
}

void DriveTrain::disableFieldOrientation()
{
	enableFieldOrientation(false);
}

void DriveTrain::resetGyro()
{
	m_navX.ZeroYaw();
}

void DriveTrain::setGyroAngle(double angle)
{
	double systemAngle = m_navX.GetAngle();
	m_gyroOffset = angle - systemAngle;
	if (m_gyroOffset < 0)
	{
		m_gyroOffset += 360;
	}
}

float DriveTrain::getAngle()
{
	return std::fmod(m_navX.GetAngle() + m_gyroOffset, 360);
}

double DriveTrain::getAcceleration()
{
	return m_navX.GetWorldLinearAccelX();
}

std::vector<double> DriveTrain::getEncoderSpeeds()
{
	std::vector<double> speeds;
	for (auto motor : m_activeMotors)
	{
		speeds.push_back(motor->GetEncVel());
	}

	return speeds;
}

std::vector<double> DriveTrain::getEncoderPositions()
{
	std::vector<double> positions;
	for (auto motor : m_activeMotors)
	{
		positions.push_back(motor->GetPosition());
	}

	return positions;
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

		m_activeMotors[RobotDrive::kFrontLeftMotor]->Set(
			m_activeMotors[RobotDrive::kFrontLeftMotor]->GetPosition() + distance
		);
		m_activeMotors[RobotDrive::kFrontRightMotor]->Set(
			m_activeMotors[RobotDrive::kFrontRightMotor]->GetPosition() + distance
		);
		m_activeMotors[RobotDrive::kRearLeftMotor]->Set(
			m_activeMotors[RobotDrive::kRearLeftMotor]->GetPosition() - distance
		);
		m_activeMotors[RobotDrive::kRearRightMotor]->Set(
			m_activeMotors[RobotDrive::kRearRightMotor]->GetPosition() - distance
		);

		return;
	}

	m_activeMotors[RobotDrive::kRearLeftMotor]->Set(
		m_activeMotors[RobotDrive::kRearLeftMotor]->GetPosition() + distance
	);
	m_activeMotors[RobotDrive::kRearRightMotor]->Set(
		m_activeMotors[RobotDrive::kRearRightMotor]->GetPosition() - distance
	);
#endif

	m_activeMotors[RobotDrive::kFrontLeftMotor]->Set(
		m_activeMotors[RobotDrive::kFrontLeftMotor]->GetPosition() + distance
	);
	m_activeMotors[RobotDrive::kFrontRightMotor]->Set(
		m_activeMotors[RobotDrive::kFrontRightMotor]->GetPosition() - distance
	);
}

void DriveTrain::setEncoderTargetPositions(std::vector<float> positions)
{
	setMode(CANTalon::kPosition);

	unsigned int index = 0;
	for (float position : positions)
	{
		m_activeMotors[index]->Set(position);

		index++;
	}
}

bool DriveTrain::atTargetPosition()
{
	for (auto motor : m_activeMotors)
	{
		if (std::abs(motor->GetClosedLoopError()) > 20)
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
	if (speed < 0)
	{
		wpi_setWPIErrorWithContext(ParameterOutOfRange, "speed < 0.0");
		return;
	}

	m_maxSpeed = speed / Config::DriveTrain::rotationGain;
	m_maxPercentVBus = m_maxSpeed / Config::DriveTrain::maxSpeed;
}

void DriveTrain::setMode(CANSpeedController::ControlMode mode)
{
	for (auto &motor : m_activeMotors)
	{
		if (mode == CANTalon::kPosition)
		{
			motor->SetPID(Config::DriveTrain::distancePID);
		}
		else if (mode == CANTalon::kSpeed)
		{
			motor->ClearIaccum();
			motor->SetPID(Config::DriveTrain::movingPID);
		}
		motor->SetControlMode(mode);
	}

}
