#pragma once

#include <CANTalon.h>
#include <memory>
#include "../Custom/DebuggingSubsystem.h"

class PickupArms: public Subsystem {
public:
	PickupArms();
	void Pivots(float y);
	void Spinner(float z);
	
protected:
	CANTalon m_BackLeft;
	CANTalon m_BackRight;
	CANTalon m_Forward;
};