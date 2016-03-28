#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>

#include "Custom/DriverHUD.h"
#include "Commands/ResetCommand.h"
#include "Commands/StorePositionsCommandGroup.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command* resetCommand;
	Command* storePositionsCommandGroup;
	LiveWindow* lw;
	
	void RobotInit() override
	{
		CommandBase::init();
		DriverHUD::prepare();

		resetCommand = new ResetCommand();
		storePositionsCommandGroup = new StorePositionsCommandGroup();

		lw = LiveWindow::GetInstance();
	}
	
	void AutonomousInit() override
	{
		DefaultInit();
		DriverHUD::startAutonomous();
	}
	
	void AutonomousPeriodic() override
	{
		DefaultPeriodic();
	}
	
	void TeleopInit() override
	{
		DefaultInit();

		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		DriverHUD::stopAutonomous();

		resetCommand->Start();
	}
	
	void TeleopPeriodic() override
	{
		DefaultPeriodic();
	}

	void DisabledInit() override
	{
		storePositionsCommandGroup->Start();
	}

	void DisabledPeriodic() override
	{
		DefaultPeriodic();
	}

	void TestInit() override
	{
		DefaultInit();

		// Run normal commands while in Test Mode
		Scheduler::GetInstance()->SetEnabled(true);
	}

	void TestPeriodic() override
	{
		DefaultPeriodic();

		lw->Run();
	}

protected:
	void DefaultInit()
	{
	}

	void DefaultPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

