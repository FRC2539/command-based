#include "FireCommandGroup.h"

#include "UnblockShooterCommand.h"
#include "FireCommand.h"
#include "Commands/WaitCommand.h"
#include "DrawBackCommand.h"
#include "InitializeShooterCommand.h"

FireCommandGroup::FireCommandGroup() {
	AddSequential(new UnblockShooterCommand());
	AddSequential(new FireCommand());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new DrawBackCommand());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new InitializeShooterCommand());
}
