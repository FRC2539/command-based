#include <WPILib.h>
#include <LiveWindow/LiveWindow.h>
#include <Commands/Command.h>
#include "Commands/Autonomous/AutonomousCommandGroup.h"
#include "Commands/ResetCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command* autonomousCommand;
	Command* resetCommand;
#if defined(DEBUG)
	LiveWindow* lw;
#endif
	
	virtual void RobotInit() {
		CommandBase::init();

		autonomousCommand = new AutonomousCommandGroup();
		resetCommand = new ResetCommand();

#if defined(DEBUG)
		lw = LiveWindow::GetInstance();
#endif
	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
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
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

#if defined(DEBUG)
		lw->Run();
#endif
	}

#if defined(DEBUG)
	virtual void TestInit() {
		lw->SetEnabled(true);
	}

	virtual void TestPeriodic() {
		lw->Run();
	}
#endif
};

START_ROBOT_CLASS(CommandBasedRobot);

