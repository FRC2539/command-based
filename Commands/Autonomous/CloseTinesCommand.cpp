#include "CloseTinesCommand.h"

#include "../../RobotMap.h"

CloseTinesCommand::CloseTinesCommand()
	: DefaultCommand("CloseTines") 
{
	Requires(tines);
}

void CloseTinesCommand::Initialize()
{
	tines->directDrive(-1);
	previousWidth = tines->getWidth();
	stoppedCount = 0;
}

bool CloseTinesCommand::IsFinished()
{
	tines->displayWidth();
	double width = tines->getWidth();
	if (width <= RobotMap::Tines::minWidth)
	{
		return true;
	}

	if (previousWidth - width >= .05)
	{
		previousWidth = width;
		stoppedCount = 0;
		return false;
	}
	else
	{
		stoppedCount++;
	}

	return stoppedCount > 15;
}

void CloseTinesCommand::End()
{
	tines->directDrive(0.1);
}

