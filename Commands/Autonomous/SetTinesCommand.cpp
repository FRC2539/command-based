#include "SetTinesCommand.h"

SetTinesCommand::SetTinesCommand(double target)
	: DefaultCommand("SetTines"), targetWidth(target)
{
	Requires(tines);
}

void SetTinesCommand::Initialize()
{
	if (targetWidth > tines->getWidth())
	{
		speed = 1;
	}
	else
	{
		speed = -1;
	}
	tines->directDrive(speed);
}

void SetTinesCommand::End()
{
	tines->directDrive(0);
}

bool SetTinesCommand::IsFinished()
{
	double width = tines->getWidth();
	if (speed < 0)
	{
		return width <= targetWidth;
	}
	else
	{
		return width >= targetWidth;
	}
}

