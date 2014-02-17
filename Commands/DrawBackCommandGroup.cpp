#include "DrawBackCommandGroup.h"

#include "Commands/WaitCommand.h"
#include "DrawBackCommand.h"
#include "InitializeShooterCommand.h"

DrawBackCommandGroup::DrawBackCommandGroup() {
	AddSequential(new DrawBackCommand());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new InitializeShooterCommand());
}
