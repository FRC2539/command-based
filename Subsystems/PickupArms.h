#pragma once

#include <CANTalon.h>
#include <memory>
#include "../Custom/DebuggingSubsystem.h"

class PickupArms: public Subsystem {
public:
	PickupArms();
	void pivotToHeight(int position);
	void setRollerSpeed(float speed);

	void manualRun(float power);

	void setEncoderPosition(int position=0);
	
protected:
	CANTalon m_leftPivotMotor;
	CANTalon m_rightPivotMotor;
	CANTalon m_rollerMotor;

	bool atKnownPosition();
	bool m_settingsLoaded;
};