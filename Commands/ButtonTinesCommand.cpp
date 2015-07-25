#include "ButtonTinesCommand.h"

#include "../Config.h"

ButtonTinesCommand::ButtonTinesCommand(float speed)
	: DefaultCommand("ButtonTines"), m_speed(speed)
{
	Requires(tines);
}

void ButtonTinesCommand::Initialize()
{
	tines->directDrive(m_speed);
}

bool ButtonTinesCommand::IsFinished()
{
	tines->displayWidth();
	if (m_speed < 0)
	{
		return tines->getWidth() <= Config::Tines::minWidth;
	}
	else
	{
		return tines->getWidth() >= Config::Tines::maxWidth;
	}
}

void ButtonTinesCommand::End()
{
	tines->directDrive(0);
}
