#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>

class DriverHUD {
public:
	static void prepare();

	static void startAutonomous();
	static void stopAutonomous();

	static void sendMessage(std::string msg);

protected:
	static Command* m_autonomousCommand;
	static Command* m_floorCommand;
	static SendableChooser* m_autonomousChooser;
	static bool m_isShown;
};