#pragma once

#include <CANTalon.h>
#include <memory>
#include "../Custom/DebuggingSubsystem.h"

class PickupArms: public Subsystem {
public:
	PickupArms();
	void pivotToHeight(double position);
	void setRollerSpeed(float speed);

	void manualRun(float power);

	void resetEncoder();
	
protected:
	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_rollerMotor;
};