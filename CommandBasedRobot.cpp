#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>
#include "Commands/Autonomous/AutonomousCommandGroup.h"
#include "Commands/ResetCommand.h"
#include "Commands/MonitorCommandGroup.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	SendableChooser* autonomousProgram;
	Command* autonomousCommand;
	Command* resetCommand;
	Command* monitorCommand;
#if defined(DEBUG)
	LiveWindow* lw;
#endif
	
	void RobotInit() override
	{
		CommandBase::init();

		autonomousCommand = new AutonomousCommandGroup();

		autonomousProgram = new SendableChooser();
		autonomousProgram->AddDefault(
			"Default",
			autonomousCommand
		);
		autonomousProgram->AddObject(
			"Additional Command",
			autonomousCommand
		);
		
		SmartDashboard::PutData("Autonomous Program", autonomousProgram);

		resetCommand = new ResetCommand();
		monitorCommand = new MonitorCommandGroup();
		monitorCommand->Start();

#if defined(DEBUG)
		lw = LiveWindow::GetInstance();
#endif
	}
	
	void AutonomousInit() override
	{
		autonomousCommand = (Command *) autonomousProgram->GetSelected();
		autonomousCommand->Start();

		DefaultInit();
	}
	
	void AutonomousPeriodic() override
	{
		DefaultPeriodic();
	}
	
	void TeleopInit() override
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();

		resetCommand->Start();

		DefaultInit();
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
	}

	void TestPeriodic() override
	{
		DefaultPeriodic();
	}

protected:
	void DefaultInit()
	{
#if defined(DEBUG)
		lw->SetEnabled(true);
#endif
	}

	void DefaultPeriodic()
	{
		Scheduler::GetInstance()->Run();

#if defined(DEBUG)
		lw->Run();
#endif
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

