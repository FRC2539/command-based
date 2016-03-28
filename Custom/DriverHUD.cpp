#include "DriverHUD.h"

#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Scheduler.h>

#include "../Commands/Autonomous/AutonomousCommandGroup.h"
#include "../Commands/Autonomous/ReachDefenseCommandGroup.h"
#include "../Commands/Autonomous/CrossDefenseCommandGroup.h"
#include "../Commands/Autonomous/LowBarCommandGroup.h"
#include "../Commands/ZeroGyroCommand.h"
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
	m_autonomousChooser = new SendableChooser();
	m_autonomousChooser->AddObject(
		"Stand Still",
		new AutonomousCommandGroup()
	);
	m_autonomousChooser->AddDefault(
		"Drive To Defense",
		new ReachDefenseCommandGroup()
	);
	m_autonomousChooser->AddObject(
		"Cross Simple Defense",
		new CrossDefenseCommandGroup()
	);
	m_autonomousChooser->AddObject(
		"Go Under Low Bar",
		new LowBarCommandGroup()
	);

	SmartDashboard::PutData("Autonomous Program", m_autonomousChooser);

	SmartDashboard::PutData("Currently Running", Scheduler::GetInstance());

	// Commands to run from dashboard
	SmartDashboard::PutData("Zero Gyro", new ZeroGyroCommand());

	SmartDashboard::PutData(
		"Reload Shooter Position",
		new ReloadShooterPositionCommand()
	);
	//SmartDashboard::PutData("Shutdown Jetson", new ShutdownJetsonCommand());

	SmartDashboard::PutString("Alert", "");
}

void DriverHUD::startAutonomous()
{
	stopAutonomous();

	m_currentAuton = (Command *) m_autonomousChooser->GetSelected();
	m_currentAuton->Start();
}

void DriverHUD::stopAutonomous()
{
	if (m_currentAuton != nullptr)
	{
		m_currentAuton->Cancel();
	}
}

void DriverHUD::sendMessage(std::string msg)
{
	SmartDashboard::PutString("Alert", msg);
}

Command* DriverHUD::m_currentAuton = nullptr;
SendableChooser* DriverHUD::m_autonomousChooser = nullptr;
bool DriverHUD::m_isShown = false;