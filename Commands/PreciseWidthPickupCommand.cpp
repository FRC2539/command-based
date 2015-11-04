#include "PreciseWidthPickupCommand.h"

#include "../Config.h"

PreciseWidthPickupCommand::PreciseWidthPickupCommand(double toteMeasurements)
	: DefaultCommand("PreciseWidthPickupCommand"), preciseWidth(toteMeasurements)
{
	Requires(tines);
}

void PreciseWidthPickupCommand::Initialize()
{
	if (tines->getWidth() < preciseWidth+0.01)
	{
		reverse = false;
		tines->directDrive(1);
	}

	else if (tines->getWidth() > preciseWidth-0.01)
	{
		reverse = true;
		tines->directDrive(-1);
	}
}

bool PreciseWidthPickupCommand::IsFinished()
{
	if (reverse==false)
	{
		if (tines->getWidth() < preciseWidth-0.01)
		{
			return false;
		}
	}
	else if(reverse==true)
	{
		if (tines->getWidth() > preciseWidth+0.01)
		{
			return false;
		}
	}

	return true;
}

void PreciseWidthPickupCommand::End()
{
	tines->directDrive(0);
}
