#include "FireCommandGroup.h"

#include "FireCommand.h"
#include "Commands/WaitCommand.h"
#include "DrawBackCommand.h"
#include "InitializeShooterCommand.h"

FireCommandGroup::FireCommandGroup() {
	AddSequential(new FireCommand());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new DrawBackCommand());
	AddSequential(new WaitCommand(1));
	AddSequential(new InitializeShooterCommand());
}