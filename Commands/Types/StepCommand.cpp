#include "StepCommand.h"

StepCommand::StepCommand(const char* name) : DefaultCommand(name), m_index(0) {}
StepCommand::StepCommand() : DefaultCommand(), m_index(0) {}

StepCommand::~StepCommand()
{
	for (auto command : m_commands)
	{
		delete command;
	}
}

void StepCommand::Initialize()
{
	stopCurrentCommand();
	m_index++;
	if (m_index >= m_commands.size())
	{
		m_index = 0;
	}

	m_commands[m_index]->Start();
}

bool StepCommand::IsFinished() {
	return !m_commands[m_index]->IsRunning();
}

void StepCommand::Interrupted() {
	stopCurrentCommand();
	DefaultCommand::Interrupted();
}

void StepCommand::addCommand(Command* command)
{
	m_commands.push_back(command);
}

void StepCommand::restart()
{
	stopCurrentCommand();
	m_index = 0;
}

void StepCommand::stopCurrentCommand()
{
	if (m_commands[m_index]->IsRunning())
	{
		m_commands[m_index]->Cancel();
	}
}



