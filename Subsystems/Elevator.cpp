#include "Elevator.h"

#include <CANTalon.h>
#include <Preferences.h>
#include <SmartDashboard/SmartDashboard.h>
#include <cmath>

#include "../RobotMap.h"
#include "../Commands/MaintainElevatorHeightCommand.h"

Elevator::Elevator() : Subsystem("Elevator"),
	m_settingsLoaded(false),
	m_targetHeight(-1),
	m_currentLevel(-1)
{
	m_elevatorMotor = new CANTalon(RobotMap::Elevator::elevatorMotorID);
	m_elevatorMotor->SetSensorDirection(true);
	m_elevatorMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_elevatorMotor->SetPosition(0);
	m_elevatorMotor->SetPID(
		RobotMap::Elevator::P,
		RobotMap::Elevator::I,
		RobotMap::Elevator::D
	);

	m_maxLevel = std::ceil(
		(RobotMap::Elevator::maxPosition - RobotMap::Elevator::levelOffset) /
		(float)RobotMap::Elevator::toteHeight
	);
}

Elevator::~Elevator()
{
	delete m_elevatorMotor;
}

void Elevator::InitDefaultCommand()
{
	SetDefaultCommand(new MaintainElevatorHeightCommand());
}

void Elevator::go(Elevator::Direction direction)
{
	m_direction = direction;
	if (m_settingsLoaded == false)
	{
		loadSettings();
	}

	m_elevatorMotor->ClearIaccum();
	if (direction == HOLD)
	{
		m_elevatorMotor->SetControlMode(CANTalon::kPosition);
		m_elevatorMotor->Set(m_elevatorMotor->GetPosition());

		calculateLevel();
		storeSettings();
	}
	else if (direction == UP)
	{
		m_elevatorMotor->SetControlMode(CANTalon::kSpeed);
		m_elevatorMotor->Set(RobotMap::Elevator::speed);
	}
	else if (direction == DOWN)
	{
		m_elevatorMotor->SetControlMode(CANTalon::kSpeed);
		m_elevatorMotor->Set(-RobotMap::Elevator::speed);
	}
}

void Elevator::changeLevel(int difference)
{
	if (m_atExactLevel == false && difference < 0)
	{
		m_atExactLevel == true; // In case this is called multiple times
		difference++;
	}
	m_currentLevel += difference;
	m_currentLevel = std::max(m_currentLevel, -1);
	m_currentLevel = std::min(m_currentLevel, m_maxLevel);

	goTo(
		RobotMap::Elevator::levelOffset
		+ m_currentLevel * RobotMap::Elevator::toteHeight
	);
}

void Elevator::goTo(int height)
{
	if (height < m_elevatorMotor->GetPosition())
	{
		go(DOWN);
	}
	else
	{
		go(UP);
	}

	m_targetHeight = height;
}

bool Elevator::atTargetPosition()
{
	bool done = false;
	if (m_direction == DOWN)
	{
		if (m_elevatorMotor->IsRevLimitSwitchClosed())
		{
			done = true;

			m_elevatorMotor->SetPosition(0);
			m_settingsLoaded = true; // We know where we are, store it
		}
		else if (m_targetHeight > 0)
		{
			done = m_elevatorMotor->GetPosition() <= m_targetHeight;
		}
	}
	else if (m_direction == UP)
	{
		if (m_elevatorMotor->IsFwdLimitSwitchClosed())
		{
			done = true;

			if (m_elevatorMotor->GetPosition() < RobotMap::Elevator::maxPosition)
			{
				m_elevatorMotor->SetPosition(RobotMap::Elevator::maxPosition);
			}
		}
		else if (m_targetHeight < RobotMap::Elevator::maxPosition)
		{
			done = m_elevatorMotor->GetPosition() >= m_targetHeight;
		}
	}

	return done;
}

void Elevator::calculateLevel()
{
	if (m_settingsLoaded == false)
	{
		return;
	}

	int value = m_elevatorMotor->GetPosition()
		- RobotMap::Elevator::levelOffset;
	value += 10; // "Exact" means within 10 ticks
	m_currentLevel = std::floor((float)value / RobotMap::Elevator::toteHeight);

	int error = value % RobotMap::Elevator::toteHeight;
	m_atExactLevel = (error >= 0 && error <= 20); // Up to 10 above or 10 below

	if (m_elevatorMotor->IsRevLimitSwitchClosed())
	{
		m_atExactLevel = true;
	}

	updateDashboardLevel();
	updateDashboardHeight();
}

void Elevator::loadSettings()
{
	if (m_settingsLoaded == true)
	{
		return;
	}

	Preferences* preferences = Preferences::GetInstance();
	if (preferences->ContainsKey("elevatorPosition"))
	{
		m_elevatorMotor->SetPosition(preferences->GetInt("elevatorPosition"));
		m_settingsLoaded = true;
		calculateLevel();
	}
	else
	{
		SmartDashboard::PutString(
			"Elevator Level",
			"Lower elevator to bottom to calibrate"
		);
	}
}

void Elevator::storeSettings()
{
	if (m_settingsLoaded == false)
	{
		return;
	}

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("elevatorPosition", m_elevatorMotor->GetPosition());
	preferences->Save();
}

void Elevator::updateDashboardLevel()
{
	std::string precision = " Approximate";
	if (m_atExactLevel == true)
	{
		precision = " Exact";
	}
	SmartDashboard::PutString(
		"Elevator Level",
		std::to_string(m_currentLevel + 1) + precision
	);
}

void Elevator::updateDashboardHeight()
{
	SmartDashboard::PutNumber(
		"Elevator Height",
		m_elevatorMotor->GetPosition()
	);
}
