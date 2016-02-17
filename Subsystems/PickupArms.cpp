#include "PickupArms.h"
#include "../Config.h"

PickupArms::PickupArms() : Subsystem("PickupArms"), m_BackLeft(Config::PickupArms::BackLeft), m_BackRight(Config::PickupArms::BackRight), m_Forward(Config::PickupArms::Forward)
{
	m_Forward.SetControlMode(CANTalon::kPercentVbus);
	m_BackLeft.SetControlMode(CANTalon::kPosition);
	m_BackRight.ConfigSoftPositionLimits(Config::PickupArms::min, Config::PickupArms::max);
	m_BackLeft.ConfigSoftPositionLimits(Config::PickupArms::max, Config::PickupArms::min);
	m_BackRight.SetControlMode(CANTalon::kPosition);
	m_BackLeft.SetP(Config::PickupArms::p);
	m_BackRight.SetP(Config::PickupArms::p);
	DEBUG_MOTOR(m_BackLeft);
	DEBUG_MOTOR(m_BackRight);
	DEBUG_MOTOR(m_Forward);
}

void PickupArms::Pivots(float y)
{
	m_BackLeft.SetPosition(y);
	m_BackRight.SetPosition(-y);	
}

void PickupArms::Spinner(float z)
{
	m_Forward.Set(z);
}

