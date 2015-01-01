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
	}

	DefaultCommand::Initialize();
}

bool ConditionalCommand::IsFinished()
{
	return !m_command->IsRunning();
}

void ConditionalCommand::Interrupted()
{
	if (m_command->IsRunning())
	{
		m_command->Cancel();
	}

	DefaultCommand::Interrupted();
}



