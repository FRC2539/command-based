#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>

#include "Custom/DriverHUD.h"
#include "Commands/ResetCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command* resetCommand;

#if defined(DEBUG)
	LiveWindow* lw;
#endif
	
	void RobotInit() override
	{
		CommandBase::init();
		DriverHUD::prepare();

		resetCommand = new ResetCommand();

#if defined(DEBUG)
		lw = LiveWindow::GetInstance();
#endif
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

	void DisabledPeriodic() override
	{
		DefaultPeriodic();
	}

	void TestInit() override
	{
		DefaultInit();
#if defined(DEBUG)
		lw->SetEnabled(true);
#endif
	}

	void TestPeriodic() override
	{
		DefaultPeriodic();
#if defined(DEBUG)
		lw->Run();
#endif
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

