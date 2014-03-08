#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/ResetCommand.h"
#include "Commands/StartCompressorCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command* autonomousCommand;
	Command* resetCommand;
	Command* startCompressorCommand;
	LiveWindow* lw;
	
	virtual void RobotInit() {
		CommandBase::init();

		autonomousCommand = new AutonomousCommandGroup();
		resetCommand = new ResetCommand();
		startCompressorCommand = new StartCompressorCommand();

		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
		startCompressorCommand->Start();
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
		startCompressorCommand->Start();

		resetCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

