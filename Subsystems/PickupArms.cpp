#include "PickupArms.h"

#include <Preferences.h>

#include "../Config.h"

PickupArms::PickupArms() : Subsystem("PickupArms"),
	m_leftPivotMotor(Config::PickupArms::leftPivotMotorID),
	m_rightPivotMotor(Config::PickupArms::rightPivotMotorID),
	m_rollerMotor(Config::PickupArms::rollerMotorID)
{
	m_rollerMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rollerMotor.SetInverted(true);

	m_leftPivotMotor.SetControlMode(CANTalon::kPosition);
	m_leftPivotMotor.ConfigSoftPositionLimits(
		Config::PickupArms::maxHeight,
		Config::PickupArms::minHeight
	);
	m_leftPivotMotor.SetP(Config::PickupArms::P);
	m_leftPivotMotor.ConfigMaxOutputVoltage(6);
	m_leftPivotMotor.SetClosedLoopOutputDirection(true);

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	m_rightPivotMotor.ConfigSoftPositionLimits(
		Config::PickupArms::maxHeight,
		Config::PickupArms::minHeight
	);
	m_rightPivotMotor.SetP(Config::PickupArms::P);
	m_rightPivotMotor.ConfigMaxOutputVoltage(6);

	DEBUG_MOTOR(m_leftPivotMotor);
	DEBUG_MOTOR(m_rightPivotMotor);
	DEBUG_MOTOR(m_rollerMotor);
}

void PickupArms::pivotToHeight(int position)
{
	if ( ! atKnownPosition())
	{
		return;
	}

	m_leftPivotMotor.Set(position);
	m_rightPivotMotor.Set(position);

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("pickupPosition", position);
}

void PickupArms::setEncoderPosition(int position)
{
	m_leftPivotMotor.SetPosition(position);
	m_rightPivotMotor.SetPosition(position);
}

void PickupArms::setRollerSpeed(float speed)
{
	m_rollerMotor.Set(speed);
}

void PickupArms::manualRun(float power)
{
	m_rollerMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rollerMotor.Set(power);
}

bool PickupArms::atKnownPosition()
{
	if ( ! m_settingsLoaded)
	{
		Preferences* preferences = Preferences::GetInstance();
		if (preferences->ContainsKey("pickupPosition"))
		{
			setEncoderPosition(preferences->GetInt("pickupPosition"));
			m_settingsLoaded = true;
		}
	}

	return m_settingsLoaded;
}
