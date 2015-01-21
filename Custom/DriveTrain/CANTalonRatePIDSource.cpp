#include "CANTalonRatePIDSource.h"

#include <CANTalon.h>

CANTalonRatePIDSource::CANTalonRatePIDSource(CANTalon* motor) :
	m_motor(motor) {}

double CANTalonRatePIDSource::PIDGet()
{
	return m_motor->GetSpeed();
}

