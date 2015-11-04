#ifndef PRECISE_WIDTH_PICKUP_COMMAND_H
#define PRECISE_WIDTH_PICKUP_COMMAND_H

#include "Types/DefaultCommand.h"

class PreciseWidthPickupCommand : public DefaultCommand {

public:
	PreciseWidthPickupCommand(double toteMeasurements);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	float m_speed;
	bool reverse;
	double preciseWidth;
};

#endif
