#include "CancelCommand.h"

CancelCommand::CancelCommand(Command* cmd) :
	InstantCommand("Cancel"),
	m_command(cmd) {}

void CancelCommand::Initialize()
{
	m_command->Cancel();
}
