#include "TineWidthCommand.h"

#include "../Config.h"

TineWidthCommand::TineWidthCommand(int width)
	: PIDCommand("TineWidth", width, 1, 0, 0)
{
	Requires(tines);

	if (m_target < Config::Tines::minWidth)
	{
		m_target = Config::Tines::minWidth;
	}
	else if (m_target > Config::Tines::maxWidth)
	{
		m_target = Config::Tines::maxWidth;
	}

	setAbsoluteError(0.1);
}

void TineWidthCommand::Initialize()
{
	m_stalledCount = 0;
	m_lastWidth = tines->getWidth();
	m_closing = (m_target < m_lastWidth);

	PIDCommand::Initialize();
}

bool TineWidthCommand::IsFinished()
{
	return PIDCommand::IsFinished() || isStalled();
}

bool TineWidthCommand::isStalled()
{
	float currentWidth = tines->getWidth();

	if (m_closing && currentWidth - m_lastWidth <= -0.5)
	{
		m_lastWidth = currentWidth;
		m_stalledCount = 0;
	}
	else if ( ! m_closing && currentWidth - m_lastWidth >= 0.5)
	{
		m_lastWidth = currentWidth;
		m_stalledCount = 0;
	}
	else
	{
		m_stalledCount++;
	}

	return m_stalledCount > 15;
}

double TineWidthCommand::ReturnPIDInput() const
{
	return tines->getWidth();
}

void TineWidthCommand::UsePIDOutput(double output)
{
	tines->directDrive(output);
}