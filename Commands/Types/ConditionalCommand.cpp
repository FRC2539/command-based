#include "ConditionalCommand.h"

ConditionalCommand::ConditionalCommand(const char* name) : DefaultCommand(name) {}

ConditionalCommand::ConditionalCommand() : DefaultCommand() {}

ConditionalCommand::~ConditionalCommand()
{
	delete m_command;
}

void ConditionalCommand::Initialize()
{
	if (shouldRun())
	{
		m_command->Start();
		m_isStarted = false;
	}

	DefaultCommand::Initialize();
}

bool ConditionalCommand::IsFinished()
{
	if (m_isStarted)
	{
		return !m_command->IsRunning();
	}
	if (m_command->IsRunning())
	{
		m_isStarted = true;
		return false;
	}
}

void ConditionalCommand::Interrupted()
{
	if (m_command->IsRunning())
	{
		m_command->Cancel();
	}

	DefaultCommand::Interrupted();
}



