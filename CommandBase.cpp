#include "CommandBase.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}


void CommandBase::init() {
	motor = new Motor();
	talon = new TalonSystem();
	drivebase = new DriveBase();
	
	oi = new OI();
}

Motor* CommandBase::motor = NULL;
TalonSystem* CommandBase::talon = NULL;
OI* CommandBase::oi = NULL;
