#include "PreciseWidthPickupCommand.h"

#include "../Config.h"

PreciseWidthPickupCommand::PreciseWidthPickupCommand(double toteMeasurements)
	: DefaultCommand("PreciseWidthPickupCommand"), m_targetWidth(toteMeasurements)
{
	Requires(tines);
	if (m_targetWidth < Config::Tines::minWidth)
	{
		m_targetWidth = Config::Tines::minWidth;
	}
	else if (m_targetWidth > Config::Tines::maxWidth)
	{
		m_targetWidth = Config::Tines::maxWidth;
	}
}
void PreciseWidthPickupCommand::Initialize()
{
	double currentWidth = tines->getWidth();
	if (currentWidth < m_targetWidth)
	{
		m_isOpening = true;
		tines->directDrive(1);
	}
	else
	{
		m_isOpening = false;
		tines->directDrive(-1);
	}
	m_previousWidth = currentWidth;
	m_stoppedCount = 0;
}

bool PreciseWidthPickupCommand::IsFinished()
{
	double currentWidth = tines->getWidth();
	if (m_isOpening)
	{
		if (currentWidth > m_targetWidth)
		{
			return true;
		}
	}
	else if( ! m_isOpening)
	{
		if (currentWidth < m_targetWidth)
		{
			return true;
		}

		if (m_previousWidth - currentWidth >= 0.05)
		{
			m_previousWidth = currentWidth;
			m_stoppedCount = 0;
		}
		else
		{
			m_stoppedCount++;
			if (m_stoppedCount > 15)
			{
				return true;
			}
		}
	}
	return false;
}

void PreciseWidthPickupCommand::End()
{
	tines->directDrive(0);
}
