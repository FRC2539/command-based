#include "DrawBackCommandGroup.h"

#include "Commands/WaitCommand.h"
#include "DrawBackCommand.h"
#include "RunBackCommand.h"
#include "InitializeShooterCommand.h"

DrawBackCommandGroup::DrawBackCommandGroup() {
	AddSequential(new DrawBackCommand());
	AddSequential(new RunBackCommand());
	AddSequential(new WaitCommand(1.1));
	AddSequential(new InitializeShooterCommand());
}