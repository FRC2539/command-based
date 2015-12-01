#include "TineWidthCommand.h"

#include "../Config.h"
#include <cmath>

TineWidthCommand::TineWidthCommand(float width)
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
	m_isOpening = (m_target > m_lastWidth);

	PIDCommand::Initialize();
}

void TineWidthCommand::Execute()
{
	tines->displayWidth();
	float currentWidth = tines->getWidth();

	if (m_isOpening && currentWidth - m_lastWidth >= 0.1)
	{
		m_lastWidth = currentWidth;
		m_stalledCount = 0;
	}
	else if ( ! m_isOpening && currentWidth - m_lastWidth <= -0.1)
	{
		m_lastWidth = currentWidth;
		m_stalledCount = 0;
	}
	else if (std::abs(currentWidth - m_target) > 0.75)
	{
		if (m_stalledCount >= 15)
		{
			this->Cancel();
		}

		m_stalledCount++;
	}
}

double TineWidthCommand::ReturnPIDInput() const
{
	return tines->getWidth();
}

void TineWidthCommand::UsePIDOutput(double output)
{
	tines->directDrive(output);
}