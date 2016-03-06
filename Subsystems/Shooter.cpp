#include "Shooter.h"

#include "../Config.h"

#include <networktables/NetworkTable.h>
#include <Preferences.h>
#include <vector>

Shooter::Shooter() : Subsystem("Shooter"),
	m_ballDetector(Config::Shooter::ballDetectorID),
	m_leftPivotMotor(Config::Shooter::leftPivotMotorID),
	m_rightPivotMotor(Config::Shooter::rightPivotMotorID),
	m_indexWheel(Config::Shooter::indexWheelID),
	m_shooterWheel(Config::Shooter::shooterWheelID),
	m_settingsLoaded(false)
{
	m_indexWheel.SetControlMode(CANTalon::kPercentVbus);
	m_indexWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_indexWheel.SetInverted(true);

	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_shooterWheel.SetI(Config::Shooter::I);
	m_shooterWheel.SetInverted(true);

	m_leftPivotMotor.SetControlMode(CANTalon::kPosition);
	/*m_leftPivotMotor.ConfigSoftPositionLimits(
		Config::Shooter::maxHeight,
		Config::Shooter::minHeight
	);*/
	m_leftPivotMotor.SetP(Config::Shooter::P);
	m_leftPivotMotor.ConfigMaxOutputVoltage(4);
	m_leftPivotMotor.SetSensorDirection(true);

	m_rightPivotMotor.SetControlMode(CANTalon::kFollower);
	m_rightPivotMotor.Set(Config::Shooter::leftPivotMotorID);
	m_rightPivotMotor.SetClosedLoopOutputDirection(true);

	m_targetInfo = NetworkTable::GetTable("cameraTarget");

	DEBUG_MOTOR(m_leftPivotMotor);
	DEBUG_MOTOR(m_rightPivotMotor);
	DEBUG_MOTOR(m_indexWheel);
	DEBUG_MOTOR(m_shooterWheel);

	DEBUG_SENSOR(m_ballDetector);
}

void Shooter::pivotToHeight(int position)
{
	if (atKnownPosition() == false)
	{
		return;
	}
	m_leftPivotMotor.Set(position);
}

void Shooter::setIndexerSpeed(float speed)
{
	m_indexWheel.Set(speed);
}

void Shooter::setShooterSpeed(float speed)
{
	m_shooterWheel.Set(speed);
}

void Shooter::stopShooter()
{
	m_shooterWheel.SetControlMode(CANTalon::kPercentVbus);
	m_shooterWheel.Set(0);
}

void Shooter::manualRun(float power)
{
	m_rightPivotMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rightPivotMotor.Set(power);
}

bool Shooter::readyToFire()
{
	if (m_shooterWheel.GetSetpoint() != Config::Shooter::firingSpeed)
	{
		return false;
	}
	return std::abs(m_shooterWheel.GetClosedLoopError()) < 100;
}

int Shooter::getHeight()
{
	return m_leftPivotMotor.GetPosition();
}

void Shooter::setEncoderPosition(int position)
{
	m_leftPivotMotor.SetPosition(position);

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("shooterPosition", position);

	m_settingsLoaded = true;
}

void Shooter::storeEncoderPosition()
{
	if (atKnownPosition())
	{
		setEncoderPosition(getHeight());
	}
}

bool Shooter::hasBall()
{
	return m_ballDetector.Get();
}

Shooter::Target Shooter::getTarget()
{
	Target target;

	if (m_targetInfo->GetBoolean("hasTarget", false) == false)
	{
		return target;
	}

	target.found = true;
	target.position = m_targetInfo->GetNumber("centerX", 0);
	target.distance = m_targetInfo->GetNumber("distance", 0);

	return target;
}

bool Shooter::atKnownPosition()
{
	if ( ! m_settingsLoaded)
	{
		Preferences* preferences = Preferences::GetInstance();
		if (preferences->ContainsKey("shooterPosition"))
		{
			m_leftPivotMotor.SetPosition(preferences->GetInt("shooterPosition"));
			m_settingsLoaded = true;
		}
	}

	return m_settingsLoaded;
}
