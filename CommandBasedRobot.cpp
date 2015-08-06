#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>
#include "Commands/Autonomous/AutonomousCommandGroup.h"
#include "Commands/Autonomous/BinOnlyCommandGroup.h"
#include "Commands/Autonomous/DriveOnlyCommandGroup.h"
#include "Commands/ResetCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	SendableChooser* autonomousProgram;
	Command* autonomousCommand;
	Command* resetCommand;
#if defined(DEBUG)
	LiveWindow* lw;
#endif
	
	virtual void RobotInit()
	{
		CommandBase::init();

		autonomousProgram = new SendableChooser();
		autonomousProgram->AddDefault(
			"Take Bin and Tote",
			new AutonomousCommandGroup()
		);
		autonomousProgram->AddObject(
			"Take Bin Only",
			new BinOnlyCommandGroup()
		);
		autonomousProgram->AddObject(
			"Just Drive Forward",
			new DriveOnlyCommandGroup()
		);
		SmartDashboard::PutData("Autonomous Program", autonomousProgram);

		resetCommand = new ResetCommand();

#if defined(DEBUG)
		lw = LiveWindow::GetInstance();
#endif
	}
	
	virtual void AutonomousInit()
	{
		autonomousCommand = (Command *) autonomousProgram->GetSelected();
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();

		resetCommand->Start();

#if defined(DEBUG)
		lw->SetEnabled(true);
#endif
	}
	
	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

#if defined(DEBUG)
		lw->Run();
#endif
	}

#if defined(DEBUG)
	virtual void TestInit()
	{
		lw->SetEnabled(true);
	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
#endif
};

START_ROBOT_CLASS(CommandBasedRobot);

