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
	bool m_isOpening;
	double m_targetWidth;
	double m_previousWidth;
	int m_stoppedCount;
};

#endif
