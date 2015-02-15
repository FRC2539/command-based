#include "ButtonTinesCommand.h"

ButtonTinesCommand::ButtonTinesCommand(float speed)
	: DefaultCommand("ButtonTines"), m_speed(speed)
{
	Requires(tines);
}

void ButtonTinesCommand::Initialize()
{
	tines->directDrive(m_speed);
}

void ButtonTinesCommand::End()
{
	tines->directDrive(0);
}
