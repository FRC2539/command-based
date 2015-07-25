#include "SetTinesCommand.h"

#include "../../Config.h"

SetTinesCommand::SetTinesCommand(double target)
	: DefaultCommand("SetTines"), targetWidth(target), speed(0)
{
	Requires(tines);

	if (targetWidth > Config::Tines::maxWidth)
	{
		targetWidth = Config::Tines::maxWidth;
	}
	else if (targetWidth < Config::Tines::minWidth)
	{
		targetWidth = Config::Tines::minWidth;
	}
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

bool SetTinesCommand::IsFinished()
{
	tines->displayWidth();
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

void SetTinesCommand::End()
{
	tines->directDrive(0);
}

