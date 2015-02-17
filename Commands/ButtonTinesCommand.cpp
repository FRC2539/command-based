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

void ButtonTinesCommand::IsFinished()
{
	if (m_speed < 0)
	{
		return tines->getWidth() <= RobotMap::Elevator::minPosition;
	}
	else
	{
		return tines->getWidth() >= RobotMap::Elevator::maxPosition;
	}
}

void ButtonTinesCommand::End()
{
	tines->directDrive(0);
}
