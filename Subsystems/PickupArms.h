#pragma once

#include <CANTalon.h>
#include <memory>
#include "../Custom/DebuggingSubsystem.h"

class PickupArms: public Subsystem {
public:
	PickupArms();
	void pivotToHeight(double position);
	void setRollerSpeed(float speed);
	
protected:
	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_rollerMotor;
};