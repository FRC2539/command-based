#include "GraphEncodersCommand.h"

#include <SmartDashboard/SmartDashboard.h>

GraphEncodersCommand::GraphEncodersCommand()
	: DefaultCommand("GraphEncoders")
{
	int index = 0;
	for (auto speed : drivetrain->getEncoderSpeeds())
	{
		m_labels.push_back(std::string("Motor ") + std::to_string(index));
		index++;
	}
}

void GraphEncodersCommand::Execute()
{
	int index = 0;
	for (auto speed : drivetrain->getEncoderSpeeds())
	{
		SmartDashboard::PutNumber(m_labels[index], speed);
		index++;
	}
}
