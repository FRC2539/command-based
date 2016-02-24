#include "PickupArms.h"
#include "../Config.h"
#include "../Custom/Netconsole.h"

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

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	m_rightPivotMotor.ConfigSoftPositionLimits(
		Config::PickupArms::minHeight,
		Config::PickupArms::maxHeight
	);
	m_rightPivotMotor.SetP(Config::PickupArms::P);

	DEBUG_MOTOR(m_leftPivotMotor);
	DEBUG_MOTOR(m_rightPivotMotor);
	DEBUG_MOTOR(m_rollerMotor);
}

void PickupArms::pivotToHeight(double position)
{
	m_leftPivotMotor.SetPosition(position);
	m_rightPivotMotor.SetPosition(position);
}

void PickupArms::resetEncoder()
{
	m_leftPivotMotor.SetPosition(0);
	m_rightPivotMotor.SetPosition(0);
}

void PickupArms::setRollerSpeed(float speed)
{
	m_rollerMotor.Set(speed);
}

void PickupArms::manualRun(float power)
{
	Netconsole::instant("Running", 1);
	m_rollerMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rollerMotor.Set(power);
}
