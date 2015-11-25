#include "TineWidthCommand.h"

#include "../Config.h"
#include "../Custom/Netconsole.h"

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
	Netconsole::instant("Width", m_lastWidth);
	m_closing = (m_target < m_lastWidth);

	PIDCommand::Initialize();
}

bool TineWidthCommand::IsFinished()
{
	tines->displayWidth();
	StopIfStalled();
	return PIDCommand::IsFinished();
}

void TineWidthCommand::StopIfStalled()
{
	float currentWidth = tines->getWidth();

	if (m_closing && currentWidth - m_target < 0.75)
	{
		Netconsole::print("Too Small", currentWidth);
		return;
	}
	else if ( ! m_closing && m_target - currentWidth < 0.75)
	{
		Netconsole::print("Too Big", currentWidth);
		return;
	}

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

	if (m_stalledCount > 15)
	{
		Netconsole::instant("Stalled", currentWidth);
		this->Cancel();
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