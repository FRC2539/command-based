#ifndef CAN_TALON_RATE_PID_SOURCE_H
#define CAN_TALON_RATE_PID_SOURCE_H

/**
 * The CANTalon class, quite sensibly, only allows itself to be used as a PID
 * source for one type of value (Position or Rate) at a time. However, we need
 * to violate that assumption in order to control the rate while we move to a
 * position.
 */

#include <PIDSource.h>
class CANTalon;

class CANTalonRatePIDSource : public PIDSource {
public:
	CANTalonRatePIDSource(CANTalon* motor);
	virtual double PIDGet();

protected:
	CANTalon* m_motor;
};

#endif
