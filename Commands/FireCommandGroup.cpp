#include "FireCommandGroup.h"

#include "UnblockShooterCommand.h"
#include "FireCommand.h"

FireCommandGroup::FireCommandGroup() {
	AddSequential(new UnblockShooterCommand());
	AddSequential(new FireCommand());
}
