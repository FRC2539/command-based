#include "PickupArms.h"

#include <Preferences.h>

#include "../Config.h"

PickupArms::PickupArms() : Subsystem("PickupArms"),
	m_leftPivotMotor(Config::PickupArms::leftPivotMotorID),
	m_rightPivotMotor(Config::PickupArms::rightPivotMotorID),
	m_rollerMotor(Config::PickupArms::rollerMotorID),
	m_settingsLoaded(false)
{
	m_rollerMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rollerMotor.SetInverted(true);

	/*m_leftPivotMotor.SetControlMode(CANTalon::kPosition);
	m_leftPivotMotor.ConfigSoftPositionLimits(
		Config::PickupArms::maxHeight,
		Config::PickupArms::minHeight
	);
	m_leftPivotMotor.SetP(Config::PickupArms::P);
	m_leftPivotMotor.ConfigMaxOutputVoltage(6);
	m_leftPivotMotor.SetClosedLoopOutputDirection(true);*/

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	m_rightPivotMotor.ConfigSoftPositionLimits(
		Config::PickupArms::maxHeight,
		Config::PickupArms::minHeight
	);
	m_rightPivotMotor.SetP(Config::PickupArms::P);
	m_rightPivotMotor.ConfigMaxOutputVoltage(2);

	// Compensate for broken encoder on left side
	m_leftPivotMotor.SetControlMode(CANTalon::kFollower);
	m_leftPivotMotor.Set(Config::PickupArms::rightPivotMotorID);
	m_leftPivotMotor.SetClosedLoopOutputDirection(true);

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

	//m_leftPivotMotor.Set(position);
	m_rightPivotMotor.Set(position);
}

int PickupArms::getHeight()
{
	return m_rightPivotMotor.GetPosition();
}

void PickupArms::setEncoderPosition(int position)
{
	//m_leftPivotMotor.SetPosition(position);
	m_rightPivotMotor.SetPosition(position);

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("pickupPosition", position);

	m_settingsLoaded = true;
}

void PickupArms::storeEncoderPosition()
{
	if (atKnownPosition())
	{
		setEncoderPosition(getHeight());
	}
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
