#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/PickupWatcherCommand.h"
#include "CommandBase.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command* autonomousCommand;
	Command* pickupWatcherCommand;
	LiveWindow* lw;
	
	virtual void RobotInit() {
		CommandBase::init();

		autonomousCommand = new AutonomousCommandGroup();
		pickupWatcherCommand = new PickupWatcherCommand();

		lw = LiveWindow::GetInstance();
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

		pickupWatcherCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

