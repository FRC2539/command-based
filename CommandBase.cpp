#include "CommandBase.h"
#include "Subsystems/Motor.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}


void CommandBase::init() {
	motor = new Motor();
	talon = new TalonSystem();
	
	oi = new OI();
}

Motor* CommandBase::motor = NULL;
TalonSystem* CommandBase::talon = NULL;
OI* CommandBase::oi = NULL;
