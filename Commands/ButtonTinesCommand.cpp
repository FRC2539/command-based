#include "ButtonTinesCommand.h"

#include "../RobotMap.h"

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
	if (m_speed < 0)
	{
		return tines->getWidth() <= RobotMap::Tines::minWidth;
	}
	else
	{
		return tines->getWidth() >= RobotMap::Tines::maxWidth;
	}
}

void ButtonTinesCommand::End()
{
	tines->directDrive(0);
}
