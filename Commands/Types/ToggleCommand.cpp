#include "ToggleCommand.h"

ToggleCommand::ToggleCommand(const char* name, Command* command)
	: InstantCommand(name)
{
	m_command = command;
}

ToggleCommand::ToggleCommand(Command* command) : InstantCommand()
{
	m_command = command;
}

ToggleCommand::~ToggleCommand()
{
	delete m_command;
}

void ToggleCommand::Initialize()
{
	if (m_command->IsRunning())
	{
		m_command->Cancel();
	}
	else
	{
		m_command->Start();
	}
}
