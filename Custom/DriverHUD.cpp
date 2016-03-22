#include "DriverHUD.h"

#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Scheduler.h>

#include "../Commands/Autonomous/AutonomousCommandGroup.h"
#include "../Commands/ZeroGyroCommand.h"
#include "../Commands/ReloadPickupPositionCommand.h"
#include "../Commands/ReloadShooterPositionCommand.h"
#include "../Commands/ShutdownJetsonCommand.h"

void DriverHUD::prepare()
{
	if (m_isShown)
	{
		return;
	}

	m_isShown = true;

	// Set up radio-boxes to choose autonomous mode
	m_autonomousCommand = new AutonomousCommandGroup();

	m_autonomousChooser = new SendableChooser();
	m_autonomousChooser->AddDefault(
		"Default",
		m_autonomousCommand
	);
	m_autonomousChooser->AddObject(
		"Additional Command",
		m_autonomousCommand
	);

	SmartDashboard::PutData("Autonomous Program", m_autonomousChooser);

	SmartDashboard::PutData("Currently Running", Scheduler::GetInstance());

	// Commands to run from dashboard
	SmartDashboard::PutData("Zero Gyro", new ZeroGyroCommand());
	SmartDashboard::PutData(
		"Reload Pickup Position",
		new ReloadPickupPositionCommand()
	);
	SmartDashboard::PutData(
		"Reload Shooter Position",
		new ReloadShooterPositionCommand()
	);
	SmartDashboard::PutData("Shutdown Jetson", new ShutdownJetsonCommand());

	SmartDashboard::PutString("Alert", "");
}

void DriverHUD::startAutonomous()
{
	m_autonomousCommand = (Command *) m_autonomousChooser->GetSelected();
	m_autonomousCommand->Start();
}

void DriverHUD::stopAutonomous()
{
	m_autonomousCommand->Cancel();
}

void DriverHUD::sendMessage(std::string msg)
{
	SmartDashboard::PutString("Alert", msg);
}

Command* DriverHUD::m_autonomousCommand = NULL;
SendableChooser* DriverHUD::m_autonomousChooser = NULL;
bool DriverHUD::m_isShown = false;