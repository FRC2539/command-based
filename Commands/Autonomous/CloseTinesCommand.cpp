#include "CloseTinesCommand.h"

CloseTinesCommand::CloseTinesCommand()
	: DefaultCommand("CloseTines") 
{
	Requires(tines);
}

void CloseTinesCommand::Initialize()
{
	tines->directDrive(-1);
	previousgetwidth = tines->getWidth();
	stoppedCount = 0;
}

void CloseTinesCommand::End()
{
	tines->directDrive(0.1);
}

bool CloseTinesCommand::IsFinished()
{
	double getWidth = tines->getWidth();
	if(previousgetwidth - getWidth > .05)
	{
		previousgetwidth = getWidth;
		stoppedCount = 0;
		return false;
	}
	else
	{
		stoppedCount++;
	}
	
	return stoppedCount > 5;
}

